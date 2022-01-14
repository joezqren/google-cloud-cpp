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
// source: google/cloud/talent/v4/event_service.proto

#include "google/cloud/talent/event_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace talent {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::internal::Idempotency;

EventServiceConnectionIdempotencyPolicy::
    ~EventServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultEventServiceConnectionIdempotencyPolicy
    : public EventServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultEventServiceConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<EventServiceConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<DefaultEventServiceConnectionIdempotencyPolicy>(
        *this);
  }

  Idempotency CreateClientEvent(
      google::cloud::talent::v4::CreateClientEventRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<EventServiceConnectionIdempotencyPolicy>
MakeDefaultEventServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<DefaultEventServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace talent
}  // namespace cloud
}  // namespace google
