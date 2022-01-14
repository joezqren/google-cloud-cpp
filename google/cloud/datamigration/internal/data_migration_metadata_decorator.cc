// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/clouddms/v1/clouddms.proto

#include "google/cloud/datamigration/internal/data_migration_metadata_decorator.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/clouddms/v1/clouddms.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace datamigration_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DataMigrationServiceMetadata::DataMigrationServiceMetadata(
    std::shared_ptr<DataMigrationServiceStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::clouddms::v1::ListMigrationJobsResponse>
DataMigrationServiceMetadata::ListMigrationJobs(
    grpc::ClientContext& context,
    google::cloud::clouddms::v1::ListMigrationJobsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListMigrationJobs(context, request);
}

StatusOr<google::cloud::clouddms::v1::MigrationJob>
DataMigrationServiceMetadata::GetMigrationJob(
    grpc::ClientContext& context,
    google::cloud::clouddms::v1::GetMigrationJobRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetMigrationJob(context, request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncCreateMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::CreateMigrationJobRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncCreateMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncUpdateMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::UpdateMigrationJobRequest const& request) {
  SetMetadata(*context, "migration_job.name=" + request.migration_job().name());
  return child_->AsyncUpdateMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncDeleteMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::DeleteMigrationJobRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncStartMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::StartMigrationJobRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncStartMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncStopMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::StopMigrationJobRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncStopMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncResumeMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::ResumeMigrationJobRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncResumeMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncPromoteMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::PromoteMigrationJobRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncPromoteMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncVerifyMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::VerifyMigrationJobRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncVerifyMigrationJob(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncRestartMigrationJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::RestartMigrationJobRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncRestartMigrationJob(cq, std::move(context), request);
}

StatusOr<google::cloud::clouddms::v1::SshScript>
DataMigrationServiceMetadata::GenerateSshScript(
    grpc::ClientContext& context,
    google::cloud::clouddms::v1::GenerateSshScriptRequest const& request) {
  SetMetadata(context, "migration_job=" + request.migration_job());
  return child_->GenerateSshScript(context, request);
}

StatusOr<google::cloud::clouddms::v1::ListConnectionProfilesResponse>
DataMigrationServiceMetadata::ListConnectionProfiles(
    grpc::ClientContext& context,
    google::cloud::clouddms::v1::ListConnectionProfilesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListConnectionProfiles(context, request);
}

StatusOr<google::cloud::clouddms::v1::ConnectionProfile>
DataMigrationServiceMetadata::GetConnectionProfile(
    grpc::ClientContext& context,
    google::cloud::clouddms::v1::GetConnectionProfileRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetConnectionProfile(context, request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncCreateConnectionProfile(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::CreateConnectionProfileRequest const&
        request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncCreateConnectionProfile(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncUpdateConnectionProfile(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::UpdateConnectionProfileRequest const&
        request) {
  SetMetadata(*context,
              "connection_profile.name=" + request.connection_profile().name());
  return child_->AsyncUpdateConnectionProfile(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncDeleteConnectionProfile(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::clouddms::v1::DeleteConnectionProfileRequest const&
        request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteConnectionProfile(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataMigrationServiceMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> DataMigrationServiceMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void DataMigrationServiceMetadata::SetMetadata(
    grpc::ClientContext& context, std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  context.AddMetadata("x-goog-api-client", api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datamigration_internal
}  // namespace cloud
}  // namespace google
