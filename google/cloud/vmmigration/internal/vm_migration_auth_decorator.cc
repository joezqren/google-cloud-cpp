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
// source: google/cloud/vmmigration/v1/vmmigration.proto

#include "google/cloud/vmmigration/internal/vm_migration_auth_decorator.h"
#include <google/cloud/vmmigration/v1/vmmigration.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace vmmigration_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

VmMigrationAuth::VmMigrationAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<VmMigrationStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::vmmigration::v1::ListSourcesResponse>
VmMigrationAuth::ListSources(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListSourcesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListSources(context, request);
}

StatusOr<google::cloud::vmmigration::v1::Source> VmMigrationAuth::GetSource(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetSourceRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetSource(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateSource(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateSourceRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateSource(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncUpdateSource(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateSourceRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateSource(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncDeleteSource(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteSourceRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteSource(cq, *std::move(context), request);
      });
}

StatusOr<google::cloud::vmmigration::v1::FetchInventoryResponse>
VmMigrationAuth::FetchInventory(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::FetchInventoryRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->FetchInventory(context, request);
}

StatusOr<google::cloud::vmmigration::v1::ListUtilizationReportsResponse>
VmMigrationAuth::ListUtilizationReports(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListUtilizationReportsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListUtilizationReports(context, request);
}

StatusOr<google::cloud::vmmigration::v1::UtilizationReport>
VmMigrationAuth::GetUtilizationReport(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetUtilizationReportRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetUtilizationReport(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateUtilizationReport(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateUtilizationReportRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateUtilizationReport(cq, *std::move(context),
                                                   request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncDeleteUtilizationReport(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteUtilizationReportRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteUtilizationReport(cq, *std::move(context),
                                                   request);
      });
}

StatusOr<google::cloud::vmmigration::v1::ListDatacenterConnectorsResponse>
VmMigrationAuth::ListDatacenterConnectors(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListDatacenterConnectorsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListDatacenterConnectors(context, request);
}

StatusOr<google::cloud::vmmigration::v1::DatacenterConnector>
VmMigrationAuth::GetDatacenterConnector(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetDatacenterConnectorRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetDatacenterConnector(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateDatacenterConnector(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateDatacenterConnectorRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateDatacenterConnector(cq, *std::move(context),
                                                     request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncDeleteDatacenterConnector(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteDatacenterConnectorRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteDatacenterConnector(cq, *std::move(context),
                                                     request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateMigratingVm(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateMigratingVmRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateMigratingVm(cq, *std::move(context), request);
      });
}

StatusOr<google::cloud::vmmigration::v1::ListMigratingVmsResponse>
VmMigrationAuth::ListMigratingVms(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListMigratingVmsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListMigratingVms(context, request);
}

StatusOr<google::cloud::vmmigration::v1::MigratingVm>
VmMigrationAuth::GetMigratingVm(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetMigratingVmRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetMigratingVm(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncUpdateMigratingVm(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateMigratingVmRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateMigratingVm(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncDeleteMigratingVm(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteMigratingVmRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteMigratingVm(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncStartMigration(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::StartMigrationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncStartMigration(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncResumeMigration(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::ResumeMigrationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncResumeMigration(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncPauseMigration(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::PauseMigrationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncPauseMigration(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncFinalizeMigration(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::FinalizeMigrationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncFinalizeMigration(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateCloneJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateCloneJobRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateCloneJob(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCancelCloneJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CancelCloneJobRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCancelCloneJob(cq, *std::move(context), request);
      });
}

StatusOr<google::cloud::vmmigration::v1::ListCloneJobsResponse>
VmMigrationAuth::ListCloneJobs(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListCloneJobsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListCloneJobs(context, request);
}

StatusOr<google::cloud::vmmigration::v1::CloneJob> VmMigrationAuth::GetCloneJob(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetCloneJobRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetCloneJob(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateCutoverJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateCutoverJobRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateCutoverJob(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCancelCutoverJob(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CancelCutoverJobRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCancelCutoverJob(cq, *std::move(context), request);
      });
}

StatusOr<google::cloud::vmmigration::v1::ListCutoverJobsResponse>
VmMigrationAuth::ListCutoverJobs(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListCutoverJobsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListCutoverJobs(context, request);
}

StatusOr<google::cloud::vmmigration::v1::CutoverJob>
VmMigrationAuth::GetCutoverJob(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetCutoverJobRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetCutoverJob(context, request);
}

StatusOr<google::cloud::vmmigration::v1::ListGroupsResponse>
VmMigrationAuth::ListGroups(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListGroupsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListGroups(context, request);
}

StatusOr<google::cloud::vmmigration::v1::Group> VmMigrationAuth::GetGroup(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetGroupRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetGroup(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateGroup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateGroupRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateGroup(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncUpdateGroup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateGroupRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateGroup(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncDeleteGroup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteGroupRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteGroup(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncAddGroupMigration(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::AddGroupMigrationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncAddGroupMigration(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncRemoveGroupMigration(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::RemoveGroupMigrationRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncRemoveGroupMigration(cq, *std::move(context),
                                                request);
      });
}

StatusOr<google::cloud::vmmigration::v1::ListTargetProjectsResponse>
VmMigrationAuth::ListTargetProjects(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListTargetProjectsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListTargetProjects(context, request);
}

StatusOr<google::cloud::vmmigration::v1::TargetProject>
VmMigrationAuth::GetTargetProject(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetTargetProjectRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetTargetProject(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncCreateTargetProject(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateTargetProjectRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateTargetProject(cq, *std::move(context),
                                               request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncUpdateTargetProject(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateTargetProjectRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateTargetProject(cq, *std::move(context),
                                               request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncDeleteTargetProject(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteTargetProjectRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteTargetProject(cq, *std::move(context),
                                               request);
      });
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context), request);
      });
}

future<Status> VmMigrationAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vmmigration_internal
}  // namespace cloud
}  // namespace google
