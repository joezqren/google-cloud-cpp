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
// source: google/cloud/resourcemanager/v3/projects.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_INTERNAL_PROJECTS_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_INTERNAL_PROJECTS_METADATA_DECORATOR_H

#include "google/cloud/resourcemanager/internal/projects_stub.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace resourcemanager_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ProjectsMetadata : public ProjectsStub {
 public:
  ~ProjectsMetadata() override = default;
  explicit ProjectsMetadata(std::shared_ptr<ProjectsStub> child);

  StatusOr<google::cloud::resourcemanager::v3::Project> GetProject(
      grpc::ClientContext& context,
      google::cloud::resourcemanager::v3::GetProjectRequest const& request)
      override;

  StatusOr<google::cloud::resourcemanager::v3::ListProjectsResponse>
  ListProjects(grpc::ClientContext& context,
               google::cloud::resourcemanager::v3::ListProjectsRequest const&
                   request) override;

  StatusOr<google::cloud::resourcemanager::v3::SearchProjectsResponse>
  SearchProjects(
      grpc::ClientContext& context,
      google::cloud::resourcemanager::v3::SearchProjectsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateProject(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::resourcemanager::v3::CreateProjectRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateProject(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::resourcemanager::v3::UpdateProjectRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncMoveProject(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::resourcemanager::v3::MoveProjectRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteProject(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::resourcemanager::v3::DeleteProjectRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUndeleteProject(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::resourcemanager::v3::UndeleteProjectRequest const& request)
      override;

  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      grpc::ClientContext& context,
      google::iam::v1::GetIamPolicyRequest const& request) override;

  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      grpc::ClientContext& context,
      google::iam::v1::SetIamPolicyRequest const& request) override;

  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      grpc::ClientContext& context,
      google::iam::v1::TestIamPermissionsRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  void SetMetadata(grpc::ClientContext& context,
                   std::string const& request_params);
  std::shared_ptr<ProjectsStub> child_;
  std::string api_client_header_;
};  // ProjectsMetadata

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_INTERNAL_PROJECTS_METADATA_DECORATOR_H