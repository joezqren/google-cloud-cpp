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
// source: google/cloud/kms/v1/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_KEY_MANAGEMENT_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_KEY_MANAGEMENT_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/kms/v1/service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace kms {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class KeyManagementServiceConnectionIdempotencyPolicy {
 public:
  virtual ~KeyManagementServiceConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<KeyManagementServiceConnectionIdempotencyPolicy>
  clone() const = 0;

  virtual google::cloud::internal::Idempotency ListKeyRings(
      google::cloud::kms::v1::ListKeyRingsRequest request) = 0;

  virtual google::cloud::internal::Idempotency ListCryptoKeys(
      google::cloud::kms::v1::ListCryptoKeysRequest request) = 0;

  virtual google::cloud::internal::Idempotency ListCryptoKeyVersions(
      google::cloud::kms::v1::ListCryptoKeyVersionsRequest request) = 0;

  virtual google::cloud::internal::Idempotency ListImportJobs(
      google::cloud::kms::v1::ListImportJobsRequest request) = 0;

  virtual google::cloud::internal::Idempotency GetKeyRing(
      google::cloud::kms::v1::GetKeyRingRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency GetCryptoKey(
      google::cloud::kms::v1::GetCryptoKeyRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency GetCryptoKeyVersion(
      google::cloud::kms::v1::GetCryptoKeyVersionRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency GetPublicKey(
      google::cloud::kms::v1::GetPublicKeyRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency GetImportJob(
      google::cloud::kms::v1::GetImportJobRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CreateKeyRing(
      google::cloud::kms::v1::CreateKeyRingRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CreateCryptoKey(
      google::cloud::kms::v1::CreateCryptoKeyRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CreateCryptoKeyVersion(
      google::cloud::kms::v1::CreateCryptoKeyVersionRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency ImportCryptoKeyVersion(
      google::cloud::kms::v1::ImportCryptoKeyVersionRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency CreateImportJob(
      google::cloud::kms::v1::CreateImportJobRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency UpdateCryptoKey(
      google::cloud::kms::v1::UpdateCryptoKeyRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency UpdateCryptoKeyVersion(
      google::cloud::kms::v1::UpdateCryptoKeyVersionRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency UpdateCryptoKeyPrimaryVersion(
      google::cloud::kms::v1::UpdateCryptoKeyPrimaryVersionRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency DestroyCryptoKeyVersion(
      google::cloud::kms::v1::DestroyCryptoKeyVersionRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency RestoreCryptoKeyVersion(
      google::cloud::kms::v1::RestoreCryptoKeyVersionRequest const&
          request) = 0;

  virtual google::cloud::internal::Idempotency Encrypt(
      google::cloud::kms::v1::EncryptRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency Decrypt(
      google::cloud::kms::v1::DecryptRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency AsymmetricSign(
      google::cloud::kms::v1::AsymmetricSignRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency AsymmetricDecrypt(
      google::cloud::kms::v1::AsymmetricDecryptRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency MacSign(
      google::cloud::kms::v1::MacSignRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency MacVerify(
      google::cloud::kms::v1::MacVerifyRequest const& request) = 0;

  virtual google::cloud::internal::Idempotency GenerateRandomBytes(
      google::cloud::kms::v1::GenerateRandomBytesRequest const& request) = 0;
};

std::unique_ptr<KeyManagementServiceConnectionIdempotencyPolicy>
MakeDefaultKeyManagementServiceConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace kms
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_KEY_MANAGEMENT_CONNECTION_IDEMPOTENCY_POLICY_H
