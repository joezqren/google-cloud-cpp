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
// source: google/cloud/workflows/v1/workflows.proto

#include "google/cloud/workflows/workflows_connection.h"
#include "google/cloud/workflows/internal/workflows_option_defaults.h"
#include "google/cloud/workflows/internal/workflows_stub_factory.h"
#include "google/cloud/workflows/workflows_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace workflows {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

WorkflowsConnection::~WorkflowsConnection() = default;

StreamRange<google::cloud::workflows::v1::Workflow>
WorkflowsConnection::ListWorkflows(
    google::cloud::workflows::v1::ListWorkflowsRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::workflows::v1::Workflow>>(
      std::move(request),
      [](google::cloud::workflows::v1::ListWorkflowsRequest const&) {
        return StatusOr<google::cloud::workflows::v1::ListWorkflowsResponse>{};
      },
      [](google::cloud::workflows::v1::ListWorkflowsResponse const&) {
        return std::vector<google::cloud::workflows::v1::Workflow>();
      });
}

StatusOr<google::cloud::workflows::v1::Workflow>
WorkflowsConnection::GetWorkflow(
    google::cloud::workflows::v1::GetWorkflowRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::workflows::v1::Workflow>>
WorkflowsConnection::CreateWorkflow(
    google::cloud::workflows::v1::CreateWorkflowRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::workflows::v1::Workflow>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::workflows::v1::OperationMetadata>>
WorkflowsConnection::DeleteWorkflow(
    google::cloud::workflows::v1::DeleteWorkflowRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::workflows::v1::OperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::workflows::v1::Workflow>>
WorkflowsConnection::UpdateWorkflow(
    google::cloud::workflows::v1::UpdateWorkflowRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::workflows::v1::Workflow>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

namespace {
class WorkflowsConnectionImpl : public WorkflowsConnection {
 public:
  WorkflowsConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<workflows_internal::WorkflowsStub> stub,
      Options const& options)
      : background_(std::move(background)),
        stub_(std::move(stub)),
        retry_policy_prototype_(
            options.get<WorkflowsRetryPolicyOption>()->clone()),
        backoff_policy_prototype_(
            options.get<WorkflowsBackoffPolicyOption>()->clone()),
        polling_policy_prototype_(
            options.get<WorkflowsPollingPolicyOption>()->clone()),
        idempotency_policy_(
            options.get<WorkflowsConnectionIdempotencyPolicyOption>()
                ->clone()) {}

  ~WorkflowsConnectionImpl() override = default;

  StreamRange<google::cloud::workflows::v1::Workflow> ListWorkflows(
      google::cloud::workflows::v1::ListWorkflowsRequest request) override {
    request.clear_page_token();
    auto stub = stub_;
    auto retry = std::shared_ptr<WorkflowsRetryPolicy const>(
        retry_policy_prototype_->clone());
    auto backoff = std::shared_ptr<BackoffPolicy const>(
        backoff_policy_prototype_->clone());
    auto idempotency = idempotency_policy_->ListWorkflows(request);
    char const* function_name = __func__;
    return google::cloud::internal::MakePaginationRange<
        StreamRange<google::cloud::workflows::v1::Workflow>>(
        std::move(request),
        [stub, retry, backoff, idempotency, function_name](
            google::cloud::workflows::v1::ListWorkflowsRequest const& r) {
          return google::cloud::internal::RetryLoop(
              retry->clone(), backoff->clone(), idempotency,
              [stub](grpc::ClientContext& context,
                     google::cloud::workflows::v1::ListWorkflowsRequest const&
                         request) {
                return stub->ListWorkflows(context, request);
              },
              r, function_name);
        },
        [](google::cloud::workflows::v1::ListWorkflowsResponse r) {
          std::vector<google::cloud::workflows::v1::Workflow> result(
              r.workflows().size());
          auto& messages = *r.mutable_workflows();
          std::move(messages.begin(), messages.end(), result.begin());
          return result;
        });
  }

  StatusOr<google::cloud::workflows::v1::Workflow> GetWorkflow(
      google::cloud::workflows::v1::GetWorkflowRequest const& request)
      override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->GetWorkflow(request),
        [this](
            grpc::ClientContext& context,
            google::cloud::workflows::v1::GetWorkflowRequest const& request) {
          return stub_->GetWorkflow(context, request);
        },
        request, __func__);
  }

  future<StatusOr<google::cloud::workflows::v1::Workflow>> CreateWorkflow(
      google::cloud::workflows::v1::CreateWorkflowRequest const& request)
      override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::workflows::v1::Workflow>(
        background_->cq(), request,
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::cloud::workflows::v1::CreateWorkflowRequest const&
                   request) {
          return stub->AsyncCreateWorkflow(cq, std::move(context), request);
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
            google::cloud::workflows::v1::Workflow>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->CreateWorkflow(request),
        polling_policy_prototype_->clone(), __func__);
  }

  future<StatusOr<google::cloud::workflows::v1::OperationMetadata>>
  DeleteWorkflow(google::cloud::workflows::v1::DeleteWorkflowRequest const&
                     request) override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::workflows::v1::OperationMetadata>(
        background_->cq(), request,
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::cloud::workflows::v1::DeleteWorkflowRequest const&
                   request) {
          return stub->AsyncDeleteWorkflow(cq, std::move(context), request);
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
        &google::cloud::internal::ExtractLongRunningResultMetadata<
            google::cloud::workflows::v1::OperationMetadata>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->DeleteWorkflow(request),
        polling_policy_prototype_->clone(), __func__);
  }

  future<StatusOr<google::cloud::workflows::v1::Workflow>> UpdateWorkflow(
      google::cloud::workflows::v1::UpdateWorkflowRequest const& request)
      override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::workflows::v1::Workflow>(
        background_->cq(), request,
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::cloud::workflows::v1::UpdateWorkflowRequest const&
                   request) {
          return stub->AsyncUpdateWorkflow(cq, std::move(context), request);
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
            google::cloud::workflows::v1::Workflow>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->UpdateWorkflow(request),
        polling_policy_prototype_->clone(), __func__);
  }

 private:
  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<workflows_internal::WorkflowsStub> stub_;
  std::unique_ptr<WorkflowsRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<PollingPolicy const> polling_policy_prototype_;
  std::unique_ptr<WorkflowsConnectionIdempotencyPolicy> idempotency_policy_;
};
}  // namespace

std::shared_ptr<WorkflowsConnection> MakeWorkflowsConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 WorkflowsPolicyOptionList>(options, __func__);
  options = workflows_internal::WorkflowsDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub =
      workflows_internal::CreateDefaultWorkflowsStub(background->cq(), options);
  return std::make_shared<WorkflowsConnectionImpl>(std::move(background),
                                                   std::move(stub), options);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace workflows
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace workflows_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<workflows::WorkflowsConnection> MakeWorkflowsConnection(
    std::shared_ptr<WorkflowsStub> stub, Options options) {
  options = WorkflowsDefaultOptions(std::move(options));
  return std::make_shared<workflows::WorkflowsConnectionImpl>(
      internal::MakeBackgroundThreadsFactory(options)(), std::move(stub),
      std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace workflows_internal
}  // namespace cloud
}  // namespace google
