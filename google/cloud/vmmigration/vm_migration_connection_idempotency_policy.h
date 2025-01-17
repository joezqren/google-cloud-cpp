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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VMMIGRATION_VM_MIGRATION_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VMMIGRATION_VM_MIGRATION_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/future.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/vmmigration/v1/vmmigration.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace vmmigration {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class VmMigrationConnectionIdempotencyPolicy {
 public:
  virtual ~VmMigrationConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<VmMigrationConnectionIdempotencyPolicy> clone()
      const = 0;

  virtual google::cloud::internal::Idempotency ListSources(
      google::cloud::vmmigration::v1::ListSourcesRequest request) = 0;

  virtual google::cloud::internal::Idempotency GetSource(
      google::cloud::vmmigration::v1::GetSourceRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CreateSource(
      google::cloud::vmmigration::v1::CreateSourceRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency UpdateSource(
      google::cloud::vmmigration::v1::UpdateSourceRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency DeleteSource(
      google::cloud::vmmigration::v1::DeleteSourceRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency FetchInventory(
      google::cloud::vmmigration::v1::FetchInventoryRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency ListUtilizationReports(
      google::cloud::vmmigration::v1::ListUtilizationReportsRequest
          request) = 0;

  virtual google::cloud::internal::Idempotency GetUtilizationReport(
      google::cloud::vmmigration::v1::GetUtilizationReportRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency CreateUtilizationReport(
      google::cloud::vmmigration::v1::CreateUtilizationReportRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency DeleteUtilizationReport(
      google::cloud::vmmigration::v1::DeleteUtilizationReportRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency ListDatacenterConnectors(
      google::cloud::vmmigration::v1::ListDatacenterConnectorsRequest
          request) = 0;

  virtual google::cloud::internal::Idempotency GetDatacenterConnector(
      google::cloud::vmmigration::v1::GetDatacenterConnectorRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency CreateDatacenterConnector(
      google::cloud::vmmigration::v1::CreateDatacenterConnectorRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency DeleteDatacenterConnector(
      google::cloud::vmmigration::v1::DeleteDatacenterConnectorRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency CreateMigratingVm(
      google::cloud::vmmigration::v1::CreateMigratingVmRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency ListMigratingVms(
      google::cloud::vmmigration::v1::ListMigratingVmsRequest request) = 0;

  virtual google::cloud::internal::Idempotency GetMigratingVm(
      google::cloud::vmmigration::v1::GetMigratingVmRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency UpdateMigratingVm(
      google::cloud::vmmigration::v1::UpdateMigratingVmRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency DeleteMigratingVm(
      google::cloud::vmmigration::v1::DeleteMigratingVmRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency StartMigration(
      google::cloud::vmmigration::v1::StartMigrationRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency ResumeMigration(
      google::cloud::vmmigration::v1::ResumeMigrationRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency PauseMigration(
      google::cloud::vmmigration::v1::PauseMigrationRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency FinalizeMigration(
      google::cloud::vmmigration::v1::FinalizeMigrationRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency CreateCloneJob(
      google::cloud::vmmigration::v1::CreateCloneJobRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CancelCloneJob(
      google::cloud::vmmigration::v1::CancelCloneJobRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency ListCloneJobs(
      google::cloud::vmmigration::v1::ListCloneJobsRequest request) = 0;

  virtual google::cloud::internal::Idempotency GetCloneJob(
      google::cloud::vmmigration::v1::GetCloneJobRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CreateCutoverJob(
      google::cloud::vmmigration::v1::CreateCutoverJobRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency CancelCutoverJob(
      google::cloud::vmmigration::v1::CancelCutoverJobRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency ListCutoverJobs(
      google::cloud::vmmigration::v1::ListCutoverJobsRequest request) = 0;

  virtual google::cloud::internal::Idempotency GetCutoverJob(
      google::cloud::vmmigration::v1::GetCutoverJobRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency ListGroups(
      google::cloud::vmmigration::v1::ListGroupsRequest request) = 0;

  virtual google::cloud::internal::Idempotency GetGroup(
      google::cloud::vmmigration::v1::GetGroupRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CreateGroup(
      google::cloud::vmmigration::v1::CreateGroupRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency UpdateGroup(
      google::cloud::vmmigration::v1::UpdateGroupRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency DeleteGroup(
      google::cloud::vmmigration::v1::DeleteGroupRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency AddGroupMigration(
      google::cloud::vmmigration::v1::AddGroupMigrationRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency RemoveGroupMigration(
      google::cloud::vmmigration::v1::RemoveGroupMigrationRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency ListTargetProjects(
      google::cloud::vmmigration::v1::ListTargetProjectsRequest request) = 0;

  virtual google::cloud::internal::Idempotency GetTargetProject(
      google::cloud::vmmigration::v1::GetTargetProjectRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency CreateTargetProject(
      google::cloud::vmmigration::v1::CreateTargetProjectRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency UpdateTargetProject(
      google::cloud::vmmigration::v1::UpdateTargetProjectRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency DeleteTargetProject(
      google::cloud::vmmigration::v1::DeleteTargetProjectRequest const&
          request) = 0;
};

std::unique_ptr<VmMigrationConnectionIdempotencyPolicy>
MakeDefaultVmMigrationConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vmmigration
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VMMIGRATION_VM_MIGRATION_CONNECTION_IDEMPOTENCY_POLICY_H
