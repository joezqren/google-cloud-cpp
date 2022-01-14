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
// source: google/cloud/eventarc/v1/eventarc.proto

#include "google/cloud/eventarc/eventarc_client.h"
#include "google/cloud/eventarc/internal/eventarc_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace eventarc {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EventarcClient::EventarcClient(std::shared_ptr<EventarcConnection> connection,
                               Options options)
    : connection_(std::move(connection)),
      options_(eventarc_internal::EventarcDefaultOptions(std::move(options))) {}
EventarcClient::~EventarcClient() = default;

StatusOr<google::cloud::eventarc::v1::Trigger> EventarcClient::GetTrigger(
    std::string const& name, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::eventarc::v1::GetTriggerRequest request;
  request.set_name(name);
  return connection_->GetTrigger(request);
}

StatusOr<google::cloud::eventarc::v1::Trigger> EventarcClient::GetTrigger(
    google::cloud::eventarc::v1::GetTriggerRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetTrigger(request);
}

StreamRange<google::cloud::eventarc::v1::Trigger> EventarcClient::ListTriggers(
    std::string const& parent, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::eventarc::v1::ListTriggersRequest request;
  request.set_parent(parent);
  return connection_->ListTriggers(request);
}

StreamRange<google::cloud::eventarc::v1::Trigger> EventarcClient::ListTriggers(
    google::cloud::eventarc::v1::ListTriggersRequest request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListTriggers(std::move(request));
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcClient::CreateTrigger(
    std::string const& parent,
    google::cloud::eventarc::v1::Trigger const& trigger,
    std::string const& trigger_id, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::eventarc::v1::CreateTriggerRequest request;
  request.set_parent(parent);
  *request.mutable_trigger() = trigger;
  request.set_trigger_id(trigger_id);
  return connection_->CreateTrigger(request);
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcClient::CreateTrigger(
    google::cloud::eventarc::v1::CreateTriggerRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateTrigger(request);
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcClient::UpdateTrigger(
    google::cloud::eventarc::v1::Trigger const& trigger,
    google::protobuf::FieldMask const& update_mask, bool allow_missing,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::eventarc::v1::UpdateTriggerRequest request;
  *request.mutable_trigger() = trigger;
  *request.mutable_update_mask() = update_mask;
  request.set_allow_missing(allow_missing);
  return connection_->UpdateTrigger(request);
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcClient::UpdateTrigger(
    google::cloud::eventarc::v1::UpdateTriggerRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateTrigger(request);
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcClient::DeleteTrigger(std::string const& name, bool allow_missing,
                              Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::eventarc::v1::DeleteTriggerRequest request;
  request.set_name(name);
  request.set_allow_missing(allow_missing);
  return connection_->DeleteTrigger(request);
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcClient::DeleteTrigger(
    google::cloud::eventarc::v1::DeleteTriggerRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteTrigger(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace eventarc
}  // namespace cloud
}  // namespace google
