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
// source: google/cloud/talent/v4/job_service.proto

#include "google/cloud/talent/internal/job_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/talent/v4/job_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace talent_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

JobServiceLogging::JobServiceLogging(std::shared_ptr<JobServiceStub> child,
                                     TracingOptions tracing_options,
                                     std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::talent::v4::Job> JobServiceLogging::CreateJob(
    grpc::ClientContext& context,
    google::cloud::talent::v4::CreateJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::talent::v4::CreateJobRequest const& request) {
        return child_->CreateJob(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
JobServiceLogging::AsyncBatchCreateJobs(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::talent::v4::BatchCreateJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::talent::v4::BatchCreateJobsRequest const& request) {
        return child_->AsyncBatchCreateJobs(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::talent::v4::Job> JobServiceLogging::GetJob(
    grpc::ClientContext& context,
    google::cloud::talent::v4::GetJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::talent::v4::GetJobRequest const& request) {
        return child_->GetJob(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::talent::v4::Job> JobServiceLogging::UpdateJob(
    grpc::ClientContext& context,
    google::cloud::talent::v4::UpdateJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::talent::v4::UpdateJobRequest const& request) {
        return child_->UpdateJob(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
JobServiceLogging::AsyncBatchUpdateJobs(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::talent::v4::BatchUpdateJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::talent::v4::BatchUpdateJobsRequest const& request) {
        return child_->AsyncBatchUpdateJobs(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

Status JobServiceLogging::DeleteJob(
    grpc::ClientContext& context,
    google::cloud::talent::v4::DeleteJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::talent::v4::DeleteJobRequest const& request) {
        return child_->DeleteJob(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
JobServiceLogging::AsyncBatchDeleteJobs(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::talent::v4::BatchDeleteJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::talent::v4::BatchDeleteJobsRequest const& request) {
        return child_->AsyncBatchDeleteJobs(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::talent::v4::ListJobsResponse>
JobServiceLogging::ListJobs(
    grpc::ClientContext& context,
    google::cloud::talent::v4::ListJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::talent::v4::ListJobsRequest const& request) {
        return child_->ListJobs(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::talent::v4::SearchJobsResponse>
JobServiceLogging::SearchJobs(
    grpc::ClientContext& context,
    google::cloud::talent::v4::SearchJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::talent::v4::SearchJobsRequest const& request) {
        return child_->SearchJobs(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::talent::v4::SearchJobsResponse>
JobServiceLogging::SearchJobsForAlert(
    grpc::ClientContext& context,
    google::cloud::talent::v4::SearchJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::talent::v4::SearchJobsRequest const& request) {
        return child_->SearchJobsForAlert(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
JobServiceLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<Status> JobServiceLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace talent_internal
}  // namespace cloud
}  // namespace google
