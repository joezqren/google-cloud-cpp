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
// source: google/cloud/vpcaccess/v1/vpc_access.proto

#include "google/cloud/vpcaccess/vpc_access_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace vpcaccess {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::internal::Idempotency;

VpcAccessServiceConnectionIdempotencyPolicy::
    ~VpcAccessServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultVpcAccessServiceConnectionIdempotencyPolicy
    : public VpcAccessServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultVpcAccessServiceConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<VpcAccessServiceConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<
        DefaultVpcAccessServiceConnectionIdempotencyPolicy>(*this);
  }

  Idempotency CreateConnector(
      google::cloud::vpcaccess::v1::CreateConnectorRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetConnector(
      google::cloud::vpcaccess::v1::GetConnectorRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListConnectors(
      google::cloud::vpcaccess::v1::ListConnectorsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency DeleteConnector(
      google::cloud::vpcaccess::v1::DeleteConnectorRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<VpcAccessServiceConnectionIdempotencyPolicy>
MakeDefaultVpcAccessServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<
      DefaultVpcAccessServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vpcaccess
}  // namespace cloud
}  // namespace google
