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
// source: google/storagetransfer/v1/transfer.proto

#include "google/cloud/storagetransfer/storage_transfer_client.h"
#include "google/cloud/storagetransfer/internal/storage_transfer_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace storagetransfer {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

StorageTransferServiceClient::StorageTransferServiceClient(
    std::shared_ptr<StorageTransferServiceConnection> connection,
    Options options)
    : connection_(std::move(connection)),
      options_(storagetransfer_internal::StorageTransferServiceDefaultOptions(
          std::move(options))) {}
StorageTransferServiceClient::~StorageTransferServiceClient() = default;

StatusOr<google::storagetransfer::v1::GoogleServiceAccount>
StorageTransferServiceClient::GetGoogleServiceAccount(
    google::storagetransfer::v1::GetGoogleServiceAccountRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetGoogleServiceAccount(request);
}

StatusOr<google::storagetransfer::v1::TransferJob>
StorageTransferServiceClient::CreateTransferJob(
    google::storagetransfer::v1::CreateTransferJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateTransferJob(request);
}

StatusOr<google::storagetransfer::v1::TransferJob>
StorageTransferServiceClient::UpdateTransferJob(
    google::storagetransfer::v1::UpdateTransferJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateTransferJob(request);
}

StatusOr<google::storagetransfer::v1::TransferJob>
StorageTransferServiceClient::GetTransferJob(
    google::storagetransfer::v1::GetTransferJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetTransferJob(request);
}

StreamRange<google::storagetransfer::v1::TransferJob>
StorageTransferServiceClient::ListTransferJobs(
    google::storagetransfer::v1::ListTransferJobsRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListTransferJobs(std::move(request));
}

Status StorageTransferServiceClient::PauseTransferOperation(
    google::storagetransfer::v1::PauseTransferOperationRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->PauseTransferOperation(request);
}

Status StorageTransferServiceClient::ResumeTransferOperation(
    google::storagetransfer::v1::ResumeTransferOperationRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ResumeTransferOperation(request);
}

future<StatusOr<google::storagetransfer::v1::TransferOperation>>
StorageTransferServiceClient::RunTransferJob(
    google::storagetransfer::v1::RunTransferJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->RunTransferJob(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storagetransfer
}  // namespace cloud
}  // namespace google