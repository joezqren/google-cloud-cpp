// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/storage/internal/grpc_client.h"
#include "google/cloud/storage/grpc_plugin.h"
#include "google/cloud/storage/internal/grpc_configure_client_context.h"
#include "google/cloud/storage/internal/grpc_object_access_control_parser.h"
#include "google/cloud/storage/internal/grpc_object_metadata_parser.h"
#include "google/cloud/storage/internal/grpc_object_read_source.h"
#include "google/cloud/storage/internal/grpc_object_request_parser.h"
#include "google/cloud/storage/internal/grpc_resumable_upload_session.h"
#include "google/cloud/storage/internal/resumable_upload_session.h"
#include "google/cloud/storage/internal/sha256_hash.h"
#include "google/cloud/storage/internal/storage_auth.h"
#include "google/cloud/storage/internal/storage_round_robin.h"
#include "google/cloud/storage/internal/storage_stub.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/big_endian.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/invoke_result.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/log.h"
#include "absl/strings/str_split.h"
#include "absl/time/time.h"
#include <crc32c/crc32c.h>
#include <grpcpp/grpcpp.h>
#include <algorithm>
#include <cinttypes>

namespace google {
namespace cloud {
namespace storage {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

using ::google::cloud::internal::GrpcAuthenticationStrategy;
using ::google::cloud::internal::MakeBackgroundThreadsFactory;

auto constexpr kDirectPathConfig = R"json({
    "loadBalancingConfig": [{
      "grpclb": {
        "childPolicy": [{
          "pick_first": {}
        }]
      }
    }]
  })json";

int DefaultGrpcNumChannels() {
  auto constexpr kMinimumChannels = 4;
  auto const count = std::thread::hardware_concurrency();
  return (std::max)(kMinimumChannels, static_cast<int>(count));
}

Options DefaultOptionsGrpc(Options options) {
  options = DefaultOptionsWithCredentials(std::move(options));
  if (!options.has<UnifiedCredentialsOption>() &&
      !options.has<GrpcCredentialOption>()) {
    options.set<UnifiedCredentialsOption>(
        google::cloud::MakeGoogleDefaultCredentials());
  }
  if (!options.has<EndpointOption>()) {
    options.set<EndpointOption>("storage.googleapis.com");
  }
  using google::cloud::internal::GetEnv;
  auto env = GetEnv("CLOUD_STORAGE_GRPC_ENDPOINT");
  if (env.has_value()) options.set<EndpointOption>(*env);
  if (GetEnv("CLOUD_STORAGE_EMULATOR_ENDPOINT")) {
    // The emulator does not support HTTPS or authentication, use insecure
    // (sometimes called "anonymous") credentials, which disable SSL.
    options.set<UnifiedCredentialsOption>(MakeInsecureCredentials());
  }
  if (!options.has<GrpcNumChannelsOption>()) {
    options.set<GrpcNumChannelsOption>(DefaultGrpcNumChannels());
  }
  return options;
}

std::shared_ptr<grpc::Channel> CreateGrpcChannel(
    GrpcAuthenticationStrategy& auth, Options const& options, int channel_id) {
  grpc::ChannelArguments args;
  auto const& config = options.get<storage_experimental::GrpcPluginOption>();
  if (config.empty() || config == "default" || config == "none") {
    // Just configure for the regular path.
    args.SetInt("grpc.channel_id", channel_id);
    return auth.CreateChannel(options.get<EndpointOption>(), std::move(args));
  }
  std::set<absl::string_view> settings = absl::StrSplit(config, ',');
  auto const dp = settings.count("dp") != 0 || settings.count("alts") != 0;
  if (dp || settings.count("pick-first-lb") != 0) {
    args.SetServiceConfigJSON(kDirectPathConfig);
  }
  if (dp || settings.count("enable-dns-srv-queries") != 0) {
    args.SetInt("grpc.dns_enable_srv_queries", 1);
  }
  if (settings.count("disable-dns-srv-queries") != 0) {
    args.SetInt("grpc.dns_enable_srv_queries", 0);
  }
  if (settings.count("exclusive") != 0) {
    args.SetInt("grpc.channel_id", channel_id);
  }
  if (settings.count("alts") != 0) {
    grpc::experimental::AltsCredentialsOptions alts_opts;
    return grpc::CreateCustomChannel(
        options.get<EndpointOption>(),
        grpc::CompositeChannelCredentials(
            grpc::experimental::AltsCredentials(alts_opts),
            grpc::GoogleComputeEngineCredentials()),
        std::move(args));
  }
  return auth.CreateChannel(options.get<EndpointOption>(), std::move(args));
}

std::shared_ptr<StorageStub> CreateStorageStub(CompletionQueue cq,
                                               Options const& opts) {
  auto auth = google::cloud::internal::CreateAuthenticationStrategy(
      std::move(cq), opts);
  std::vector<std::shared_ptr<StorageStub>> children(
      (std::max)(1, opts.get<GrpcNumChannelsOption>()));
  int id = 0;
  std::generate(children.begin(), children.end(), [&id, &auth, opts] {
    return MakeDefaultStorageStub(CreateGrpcChannel(*auth, opts, id++));
  });
  std::shared_ptr<StorageStub> stub =
      std::make_shared<StorageRoundRobin>(std::move(children));
  if (auth->RequiresConfigureContext()) {
    stub = std::make_shared<StorageAuth>(std::move(auth), std::move(stub));
  }
  return stub;
}

std::shared_ptr<GrpcClient> GrpcClient::Create(Options opts) {
  // Cannot use std::make_shared<> as the constructor is private.
  return std::shared_ptr<GrpcClient>(new GrpcClient(std::move(opts)));
}

std::shared_ptr<GrpcClient> GrpcClient::CreateMock(
    std::shared_ptr<StorageStub> stub, Options opts) {
  return std::shared_ptr<GrpcClient>(
      new GrpcClient(std::move(stub), DefaultOptionsGrpc(std::move(opts))));
}

GrpcClient::GrpcClient(Options opts)
    : options_(std::move(opts)),
      backwards_compatibility_options_(
          MakeBackwardsCompatibleClientOptions(options_)),
      background_(MakeBackgroundThreadsFactory(options_)()),
      stub_(CreateStorageStub(background_->cq(), options_)) {}

GrpcClient::GrpcClient(std::shared_ptr<StorageStub> stub, Options opts)
    : options_(std::move(opts)),
      backwards_compatibility_options_(
          MakeBackwardsCompatibleClientOptions(options_)),
      background_(MakeBackgroundThreadsFactory(options_)()),
      stub_(std::move(stub)) {}

std::unique_ptr<GrpcClient::WriteObjectStream> GrpcClient::CreateUploadWriter(
    std::unique_ptr<grpc::ClientContext> context) {
  auto const timeout = options_.get<TransferStallTimeoutOption>();
  if (timeout.count() != 0) {
    context->set_deadline(std::chrono::system_clock::now() + timeout);
  }
  return stub_->WriteObject(std::move(context));
}

StatusOr<ResumableUploadResponse> GrpcClient::QueryResumableUpload(
    QueryResumableUploadRequest const& request) {
  grpc::ClientContext context;
  ApplyQueryParameters(context, request, "resource");
  auto const timeout = options_.get<TransferStallTimeoutOption>();
  if (timeout.count() != 0) {
    context.set_deadline(std::chrono::system_clock::now() + timeout);
  }
  auto status = stub_->QueryWriteStatus(
      context, GrpcObjectRequestParser::ToProto(request));
  if (!status) return std::move(status).status();

  ResumableUploadResponse response;
  response.upload_state = ResumableUploadResponse::kInProgress;
  if (status->has_persisted_size()) {
    response.committed_size =
        static_cast<std::uint64_t>(status->persisted_size());
  }
  if (status->has_resource()) {
    response.payload =
        GrpcObjectMetadataParser::FromProto(status->resource(), options());
    response.upload_state = ResumableUploadResponse::kDone;
  }
  return response;
}

StatusOr<std::unique_ptr<ResumableUploadSession>>
GrpcClient::FullyRestoreResumableSession(ResumableUploadRequest const& request,
                                         std::string const& upload_url) {
  auto self = shared_from_this();
  auto upload_session_params = DecodeGrpcResumableUploadSessionUrl(upload_url);
  if (!upload_session_params) return std::move(upload_session_params).status();
  auto session = std::unique_ptr<ResumableUploadSession>(
      new GrpcResumableUploadSession(self, request, *upload_session_params));
  auto response = session->ResetSession();
  if (!response) std::move(response).status();
  return session;
}

ClientOptions const& GrpcClient::client_options() const {
  return backwards_compatibility_options_;
}

StatusOr<ListBucketsResponse> GrpcClient::ListBuckets(
    ListBucketsRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketMetadata> GrpcClient::CreateBucket(CreateBucketRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketMetadata> GrpcClient::GetBucketMetadata(
    GetBucketMetadataRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<EmptyResponse> GrpcClient::DeleteBucket(DeleteBucketRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketMetadata> GrpcClient::UpdateBucket(UpdateBucketRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketMetadata> GrpcClient::PatchBucket(PatchBucketRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<IamPolicy> GrpcClient::GetBucketIamPolicy(
    GetBucketIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<NativeIamPolicy> GrpcClient::GetNativeBucketIamPolicy(
    GetBucketIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<IamPolicy> GrpcClient::SetBucketIamPolicy(
    SetBucketIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<NativeIamPolicy> GrpcClient::SetNativeBucketIamPolicy(
    SetNativeBucketIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<TestBucketIamPermissionsResponse> GrpcClient::TestBucketIamPermissions(
    TestBucketIamPermissionsRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketMetadata> GrpcClient::LockBucketRetentionPolicy(
    LockBucketRetentionPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectMetadata> GrpcClient::InsertObjectMedia(
    InsertObjectMediaRequest const& request) {
  auto r = GrpcObjectRequestParser::ToProto(request);
  if (!r) return std::move(r).status();
  auto proto_request = *r;

  auto context = absl::make_unique<grpc::ClientContext>();
  // The REST response is just the object metadata (aka the "resource"). In the
  // gRPC response the object metadata is in a "resource" field. Passing an
  // extra prefix to ApplyQueryParameters sends the right filtering instructions
  // to the gRPC API.
  ApplyQueryParameters(*context, request, "resource");
  auto stream = stub_->WriteObject(std::move(context));

  auto const& contents = request.contents();
  auto const contents_size = static_cast<std::int64_t>(contents.size());
  std::int64_t const maximum_buffer_size =
      google::storage::v2::ServiceConstants::MAX_WRITE_CHUNK_BYTES;

  // This loop must run at least once because we need to send at least one
  // Write() call for empty objects.
  for (std::int64_t offset = 0, n = 0; offset <= contents_size; offset += n) {
    proto_request.set_write_offset(offset);
    auto& data = *proto_request.mutable_checksummed_data();
    n = (std::min)(contents_size - offset, maximum_buffer_size);
    data.set_content(
        contents.substr(static_cast<std::string::size_type>(offset),
                        static_cast<std::string::size_type>(n)));
    data.set_crc32c(crc32c::Crc32c(data.content()));

    if (offset + n >= contents_size) {
      proto_request.set_finish_write(true);
      stream->Write(proto_request, grpc::WriteOptions{}.set_last_message());
      break;
    }
    if (!stream->Write(proto_request, grpc::WriteOptions{})) break;
    // After the first message, clear the object specification and checksums,
    // there is no need to resend it.
    proto_request.clear_write_object_spec();
    proto_request.clear_object_checksums();
  }

  auto response = stream->Close();
  if (!response) return std::move(response).status();
  if (response->has_resource()) {
    return GrpcObjectMetadataParser::FromProto(response->resource(), options());
  }
  return ObjectMetadata{};
}

StatusOr<ObjectMetadata> GrpcClient::CopyObject(CopyObjectRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectMetadata> GrpcClient::GetObjectMetadata(
    GetObjectMetadataRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<std::unique_ptr<ObjectReadSource>> GrpcClient::ReadObject(
    ReadObjectRangeRequest const& request) {
  // With the REST API this condition was detected by the server as an error,
  // generally we prefer the server to detect errors because its answers are
  // authoritative. In this case, the server cannot: with gRPC '0' is the same
  // as "not set" and the server would send back the full file, which was
  // unlikely to be the customer's intent.
  if (request.HasOption<ReadLast>() &&
      request.GetOption<ReadLast>().value() == 0) {
    return Status(
        StatusCode::kOutOfRange,
        "ReadLast(0) is invalid in REST and produces incorrect output in gRPC");
  }
  auto context = absl::make_unique<grpc::ClientContext>();
  ApplyQueryParameters(*context, request);
  auto const timeout = options_.get<DownloadStallTimeoutOption>();
  if (timeout.count() != 0) {
    context->set_deadline(std::chrono::system_clock::now() + timeout);
  }
  auto proto_request = GrpcObjectRequestParser::ToProto(request);
  if (!proto_request) return std::move(proto_request).status();
  return std::unique_ptr<ObjectReadSource>(
      absl::make_unique<GrpcObjectReadSource>(
          stub_->ReadObject(std::move(context), *proto_request)));
}

StatusOr<ListObjectsResponse> GrpcClient::ListObjects(
    ListObjectsRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<EmptyResponse> GrpcClient::DeleteObject(DeleteObjectRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectMetadata> GrpcClient::UpdateObject(UpdateObjectRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectMetadata> GrpcClient::PatchObject(PatchObjectRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectMetadata> GrpcClient::ComposeObject(
    ComposeObjectRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<RewriteObjectResponse> GrpcClient::RewriteObject(
    RewriteObjectRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<std::unique_ptr<ResumableUploadSession>>
GrpcClient::CreateResumableSession(ResumableUploadRequest const& request) {
  auto session_id = request.GetOption<UseResumableUploadSession>().value_or("");
  if (!session_id.empty()) {
    return FullyRestoreResumableSession(request, session_id);
  }

  auto proto_request = GrpcObjectRequestParser::ToProto(request);
  if (!proto_request) return std::move(proto_request).status();

  grpc::ClientContext context;
  ApplyQueryParameters(context, request, "resource");
  auto const timeout = options_.get<TransferStallTimeoutOption>();
  if (timeout.count() != 0) {
    context.set_deadline(std::chrono::system_clock::now() + timeout);
  }
  auto response = stub_->StartResumableWrite(context, *proto_request);
  if (!response.ok()) return std::move(response).status();

  auto self = shared_from_this();
  return std::unique_ptr<ResumableUploadSession>(
      new GrpcResumableUploadSession(self, request, {response->upload_id()}));
}

StatusOr<EmptyResponse> GrpcClient::DeleteResumableUpload(
    DeleteResumableUploadRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ListBucketAclResponse> GrpcClient::ListBucketAcl(
    ListBucketAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketAccessControl> GrpcClient::GetBucketAcl(
    GetBucketAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketAccessControl> GrpcClient::CreateBucketAcl(
    CreateBucketAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<EmptyResponse> GrpcClient::DeleteBucketAcl(
    DeleteBucketAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ListObjectAclResponse> GrpcClient::ListObjectAcl(
    ListObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketAccessControl> GrpcClient::UpdateBucketAcl(
    UpdateBucketAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<BucketAccessControl> GrpcClient::PatchBucketAcl(
    PatchBucketAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::CreateObjectAcl(
    CreateObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<EmptyResponse> GrpcClient::DeleteObjectAcl(
    DeleteObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::GetObjectAcl(
    GetObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::UpdateObjectAcl(
    UpdateObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::PatchObjectAcl(
    PatchObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ListDefaultObjectAclResponse> GrpcClient::ListDefaultObjectAcl(
    ListDefaultObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::CreateDefaultObjectAcl(
    CreateDefaultObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<EmptyResponse> GrpcClient::DeleteDefaultObjectAcl(
    DeleteDefaultObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::GetDefaultObjectAcl(
    GetDefaultObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::UpdateDefaultObjectAcl(
    UpdateDefaultObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ObjectAccessControl> GrpcClient::PatchDefaultObjectAcl(
    PatchDefaultObjectAclRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ServiceAccount> GrpcClient::GetServiceAccount(
    GetProjectServiceAccountRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ListHmacKeysResponse> GrpcClient::ListHmacKeys(
    ListHmacKeysRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<CreateHmacKeyResponse> GrpcClient::CreateHmacKey(
    CreateHmacKeyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<EmptyResponse> GrpcClient::DeleteHmacKey(DeleteHmacKeyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<HmacKeyMetadata> GrpcClient::GetHmacKey(GetHmacKeyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<HmacKeyMetadata> GrpcClient::UpdateHmacKey(
    UpdateHmacKeyRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<SignBlobResponse> GrpcClient::SignBlob(SignBlobRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<ListNotificationsResponse> GrpcClient::ListNotifications(
    ListNotificationsRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<NotificationMetadata> GrpcClient::CreateNotification(
    CreateNotificationRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<NotificationMetadata> GrpcClient::GetNotification(
    GetNotificationRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

StatusOr<EmptyResponse> GrpcClient::DeleteNotification(
    DeleteNotificationRequest const&) {
  return Status(StatusCode::kUnimplemented, __func__);
}

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage
}  // namespace cloud
}  // namespace google
