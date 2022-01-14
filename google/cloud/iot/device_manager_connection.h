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
// source: google/cloud/iot/v1/device_manager.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IOT_DEVICE_MANAGER_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IOT_DEVICE_MANAGER_CONNECTION_H

#include "google/cloud/iot/device_manager_connection_idempotency_policy.h"
#include "google/cloud/iot/internal/device_manager_retry_traits.h"
#include "google/cloud/iot/internal/device_manager_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace iot {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using DeviceManagerRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        iot_internal::DeviceManagerRetryTraits>;

using DeviceManagerLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        iot_internal::DeviceManagerRetryTraits>;

using DeviceManagerLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        iot_internal::DeviceManagerRetryTraits>;

class DeviceManagerConnection {
 public:
  virtual ~DeviceManagerConnection() = 0;

  virtual StatusOr<google::cloud::iot::v1::DeviceRegistry> CreateDeviceRegistry(
      google::cloud::iot::v1::CreateDeviceRegistryRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::DeviceRegistry> GetDeviceRegistry(
      google::cloud::iot::v1::GetDeviceRegistryRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::DeviceRegistry> UpdateDeviceRegistry(
      google::cloud::iot::v1::UpdateDeviceRegistryRequest const& request);

  virtual Status DeleteDeviceRegistry(
      google::cloud::iot::v1::DeleteDeviceRegistryRequest const& request);

  virtual StreamRange<google::cloud::iot::v1::DeviceRegistry>
  ListDeviceRegistries(
      google::cloud::iot::v1::ListDeviceRegistriesRequest request);

  virtual StatusOr<google::cloud::iot::v1::Device> CreateDevice(
      google::cloud::iot::v1::CreateDeviceRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::Device> GetDevice(
      google::cloud::iot::v1::GetDeviceRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::Device> UpdateDevice(
      google::cloud::iot::v1::UpdateDeviceRequest const& request);

  virtual Status DeleteDevice(
      google::cloud::iot::v1::DeleteDeviceRequest const& request);

  virtual StreamRange<google::cloud::iot::v1::Device> ListDevices(
      google::cloud::iot::v1::ListDevicesRequest request);

  virtual StatusOr<google::cloud::iot::v1::DeviceConfig>
  ModifyCloudToDeviceConfig(
      google::cloud::iot::v1::ModifyCloudToDeviceConfigRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::ListDeviceConfigVersionsResponse>
  ListDeviceConfigVersions(
      google::cloud::iot::v1::ListDeviceConfigVersionsRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::ListDeviceStatesResponse>
  ListDeviceStates(
      google::cloud::iot::v1::ListDeviceStatesRequest const& request);

  virtual StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request);

  virtual StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request);

  virtual StatusOr<google::iam::v1::TestIamPermissionsResponse>
  TestIamPermissions(google::iam::v1::TestIamPermissionsRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::SendCommandToDeviceResponse>
  SendCommandToDevice(
      google::cloud::iot::v1::SendCommandToDeviceRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::BindDeviceToGatewayResponse>
  BindDeviceToGateway(
      google::cloud::iot::v1::BindDeviceToGatewayRequest const& request);

  virtual StatusOr<google::cloud::iot::v1::UnbindDeviceFromGatewayResponse>
  UnbindDeviceFromGateway(
      google::cloud::iot::v1::UnbindDeviceFromGatewayRequest const& request);
};

std::shared_ptr<DeviceManagerConnection> MakeDeviceManagerConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iot
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace iot_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<iot::DeviceManagerConnection> MakeDeviceManagerConnection(
    std::shared_ptr<DeviceManagerStub> stub, Options options);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iot_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IOT_DEVICE_MANAGER_CONNECTION_H
