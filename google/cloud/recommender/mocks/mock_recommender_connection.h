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
// source: google/cloud/recommender/v1/recommender_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RECOMMENDER_MOCKS_MOCK_RECOMMENDER_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RECOMMENDER_MOCKS_MOCK_RECOMMENDER_CONNECTION_H

#include "google/cloud/recommender/recommender_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace recommender_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockRecommenderConnection : public recommender::RecommenderConnection {
 public:
  MOCK_METHOD(StreamRange<google::cloud::recommender::v1::Insight>,
              ListInsights,
              (google::cloud::recommender::v1::ListInsightsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::recommender::v1::Insight>, GetInsight,
      (google::cloud::recommender::v1::GetInsightRequest const& request),
      (override));

  MOCK_METHOD(StatusOr<google::cloud::recommender::v1::Insight>,
              MarkInsightAccepted,
              (google::cloud::recommender::v1::MarkInsightAcceptedRequest const&
                   request),
              (override));

  MOCK_METHOD(
      StreamRange<google::cloud::recommender::v1::Recommendation>,
      ListRecommendations,
      (google::cloud::recommender::v1::ListRecommendationsRequest request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::recommender::v1::Recommendation>,
      GetRecommendation,
      (google::cloud::recommender::v1::GetRecommendationRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::recommender::v1::Recommendation>,
      MarkRecommendationClaimed,
      (google::cloud::recommender::v1::MarkRecommendationClaimedRequest const&
           request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::recommender::v1::Recommendation>,
      MarkRecommendationSucceeded,
      (google::cloud::recommender::v1::MarkRecommendationSucceededRequest const&
           request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::recommender::v1::Recommendation>,
      MarkRecommendationFailed,
      (google::cloud::recommender::v1::MarkRecommendationFailedRequest const&
           request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace recommender_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RECOMMENDER_MOCKS_MOCK_RECOMMENDER_CONNECTION_H
