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

#include "google/cloud/talent/job_connection.h"
#include "google/cloud/talent/internal/job_option_defaults.h"
#include "google/cloud/talent/internal/job_stub_factory.h"
#include "google/cloud/talent/job_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace talent {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

JobServiceConnection::~JobServiceConnection() = default;

StatusOr<google::cloud::talent::v4::Job> JobServiceConnection::CreateJob(
    google::cloud::talent::v4::CreateJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::talent::v4::BatchCreateJobsResponse>>
JobServiceConnection::BatchCreateJobs(
    google::cloud::talent::v4::BatchCreateJobsRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::talent::v4::BatchCreateJobsResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::talent::v4::Job> JobServiceConnection::GetJob(
    google::cloud::talent::v4::GetJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::talent::v4::Job> JobServiceConnection::UpdateJob(
    google::cloud::talent::v4::UpdateJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::talent::v4::BatchUpdateJobsResponse>>
JobServiceConnection::BatchUpdateJobs(
    google::cloud::talent::v4::BatchUpdateJobsRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::talent::v4::BatchUpdateJobsResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

Status JobServiceConnection::DeleteJob(
    google::cloud::talent::v4::DeleteJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::talent::v4::BatchDeleteJobsResponse>>
JobServiceConnection::BatchDeleteJobs(
    google::cloud::talent::v4::BatchDeleteJobsRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::talent::v4::BatchDeleteJobsResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StreamRange<google::cloud::talent::v4::Job> JobServiceConnection::ListJobs(
    google::cloud::talent::v4::ListJobsRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::talent::v4::Job>>(
      std::move(request),
      [](google::cloud::talent::v4::ListJobsRequest const&) {
        return StatusOr<google::cloud::talent::v4::ListJobsResponse>{};
      },
      [](google::cloud::talent::v4::ListJobsResponse const&) {
        return std::vector<google::cloud::talent::v4::Job>();
      });
}

StatusOr<google::cloud::talent::v4::SearchJobsResponse>
JobServiceConnection::SearchJobs(
    google::cloud::talent::v4::SearchJobsRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::talent::v4::SearchJobsResponse>
JobServiceConnection::SearchJobsForAlert(
    google::cloud::talent::v4::SearchJobsRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

namespace {
class JobServiceConnectionImpl : public JobServiceConnection {
 public:
  JobServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<talent_internal::JobServiceStub> stub,
      Options const& options)
      : background_(std::move(background)),
        stub_(std::move(stub)),
        retry_policy_prototype_(
            options.get<JobServiceRetryPolicyOption>()->clone()),
        backoff_policy_prototype_(
            options.get<JobServiceBackoffPolicyOption>()->clone()),
        polling_policy_prototype_(
            options.get<JobServicePollingPolicyOption>()->clone()),
        idempotency_policy_(
            options.get<JobServiceConnectionIdempotencyPolicyOption>()
                ->clone()) {}

  ~JobServiceConnectionImpl() override = default;

  StatusOr<google::cloud::talent::v4::Job> CreateJob(
      google::cloud::talent::v4::CreateJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->CreateJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::talent::v4::CreateJobRequest const& request) {
          return stub_->CreateJob(context, request);
        },
        request, __func__);
  }

  future<StatusOr<google::cloud::talent::v4::BatchCreateJobsResponse>>
  BatchCreateJobs(google::cloud::talent::v4::BatchCreateJobsRequest const&
                      request) override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::talent::v4::BatchCreateJobsResponse>(
        background_->cq(), request,
        [stub](
            google::cloud::CompletionQueue& cq,
            std::unique_ptr<grpc::ClientContext> context,
            google::cloud::talent::v4::BatchCreateJobsRequest const& request) {
          return stub->AsyncBatchCreateJobs(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::GetOperationRequest const& request) {
          return stub->AsyncGetOperation(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::CancelOperationRequest const& request) {
          return stub->AsyncCancelOperation(cq, std::move(context), request);
        },
        &google::cloud::internal::ExtractLongRunningResultResponse<
            google::cloud::talent::v4::BatchCreateJobsResponse>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->BatchCreateJobs(request),
        polling_policy_prototype_->clone(), __func__);
  }

  StatusOr<google::cloud::talent::v4::Job> GetJob(
      google::cloud::talent::v4::GetJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->GetJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::talent::v4::GetJobRequest const& request) {
          return stub_->GetJob(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::talent::v4::Job> UpdateJob(
      google::cloud::talent::v4::UpdateJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->UpdateJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::talent::v4::UpdateJobRequest const& request) {
          return stub_->UpdateJob(context, request);
        },
        request, __func__);
  }

  future<StatusOr<google::cloud::talent::v4::BatchUpdateJobsResponse>>
  BatchUpdateJobs(google::cloud::talent::v4::BatchUpdateJobsRequest const&
                      request) override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::talent::v4::BatchUpdateJobsResponse>(
        background_->cq(), request,
        [stub](
            google::cloud::CompletionQueue& cq,
            std::unique_ptr<grpc::ClientContext> context,
            google::cloud::talent::v4::BatchUpdateJobsRequest const& request) {
          return stub->AsyncBatchUpdateJobs(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::GetOperationRequest const& request) {
          return stub->AsyncGetOperation(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::CancelOperationRequest const& request) {
          return stub->AsyncCancelOperation(cq, std::move(context), request);
        },
        &google::cloud::internal::ExtractLongRunningResultResponse<
            google::cloud::talent::v4::BatchUpdateJobsResponse>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->BatchUpdateJobs(request),
        polling_policy_prototype_->clone(), __func__);
  }

  Status DeleteJob(
      google::cloud::talent::v4::DeleteJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->DeleteJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::talent::v4::DeleteJobRequest const& request) {
          return stub_->DeleteJob(context, request);
        },
        request, __func__);
  }

  future<StatusOr<google::cloud::talent::v4::BatchDeleteJobsResponse>>
  BatchDeleteJobs(google::cloud::talent::v4::BatchDeleteJobsRequest const&
                      request) override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::talent::v4::BatchDeleteJobsResponse>(
        background_->cq(), request,
        [stub](
            google::cloud::CompletionQueue& cq,
            std::unique_ptr<grpc::ClientContext> context,
            google::cloud::talent::v4::BatchDeleteJobsRequest const& request) {
          return stub->AsyncBatchDeleteJobs(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::GetOperationRequest const& request) {
          return stub->AsyncGetOperation(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::CancelOperationRequest const& request) {
          return stub->AsyncCancelOperation(cq, std::move(context), request);
        },
        &google::cloud::internal::ExtractLongRunningResultResponse<
            google::cloud::talent::v4::BatchDeleteJobsResponse>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->BatchDeleteJobs(request),
        polling_policy_prototype_->clone(), __func__);
  }

  StreamRange<google::cloud::talent::v4::Job> ListJobs(
      google::cloud::talent::v4::ListJobsRequest request) override {
    request.clear_page_token();
    auto stub = stub_;
    auto retry = std::shared_ptr<JobServiceRetryPolicy const>(
        retry_policy_prototype_->clone());
    auto backoff = std::shared_ptr<BackoffPolicy const>(
        backoff_policy_prototype_->clone());
    auto idempotency = idempotency_policy_->ListJobs(request);
    char const* function_name = __func__;
    return google::cloud::internal::MakePaginationRange<
        StreamRange<google::cloud::talent::v4::Job>>(
        std::move(request),
        [stub, retry, backoff, idempotency,
         function_name](google::cloud::talent::v4::ListJobsRequest const& r) {
          return google::cloud::internal::RetryLoop(
              retry->clone(), backoff->clone(), idempotency,
              [stub](
                  grpc::ClientContext& context,
                  google::cloud::talent::v4::ListJobsRequest const& request) {
                return stub->ListJobs(context, request);
              },
              r, function_name);
        },
        [](google::cloud::talent::v4::ListJobsResponse r) {
          std::vector<google::cloud::talent::v4::Job> result(r.jobs().size());
          auto& messages = *r.mutable_jobs();
          std::move(messages.begin(), messages.end(), result.begin());
          return result;
        });
  }

  StatusOr<google::cloud::talent::v4::SearchJobsResponse> SearchJobs(
      google::cloud::talent::v4::SearchJobsRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->SearchJobs(request),
        [this](grpc::ClientContext& context,
               google::cloud::talent::v4::SearchJobsRequest const& request) {
          return stub_->SearchJobs(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::talent::v4::SearchJobsResponse> SearchJobsForAlert(
      google::cloud::talent::v4::SearchJobsRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->SearchJobsForAlert(request),
        [this](grpc::ClientContext& context,
               google::cloud::talent::v4::SearchJobsRequest const& request) {
          return stub_->SearchJobsForAlert(context, request);
        },
        request, __func__);
  }

 private:
  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<talent_internal::JobServiceStub> stub_;
  std::unique_ptr<JobServiceRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<PollingPolicy const> polling_policy_prototype_;
  std::unique_ptr<JobServiceConnectionIdempotencyPolicy> idempotency_policy_;
};
}  // namespace

std::shared_ptr<JobServiceConnection> MakeJobServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 JobServicePolicyOptionList>(options, __func__);
  options = talent_internal::JobServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub =
      talent_internal::CreateDefaultJobServiceStub(background->cq(), options);
  return std::make_shared<JobServiceConnectionImpl>(std::move(background),
                                                    std::move(stub), options);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace talent
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace talent_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<talent::JobServiceConnection> MakeJobServiceConnection(
    std::shared_ptr<JobServiceStub> stub, Options options) {
  options = JobServiceDefaultOptions(std::move(options));
  return std::make_shared<talent::JobServiceConnectionImpl>(
      internal::MakeBackgroundThreadsFactory(options)(), std::move(stub),
      std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace talent_internal
}  // namespace cloud
}  // namespace google
