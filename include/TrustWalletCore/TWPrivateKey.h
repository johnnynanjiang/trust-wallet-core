// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWPublicKey.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWPrivateKey;

static const size_t TWPrivateKeySize = 32;

TW_EXPORT_STATIC_METHOD
struct TWPrivateKey *_Nonnull TWPrivateKeyCreate(void);

TW_EXPORT_STATIC_METHOD
struct TWPrivateKey *_Nullable TWPrivateKeyCreateWithData(TWData *_Nonnull data);

TW_EXPORT_STATIC_METHOD
struct TWPrivateKey *_Nullable TWPrivateKeyCreateCopy(struct TWPrivateKey *_Nonnull key);

TW_EXPORT_METHOD
void TWPrivateKeyDelete(struct TWPrivateKey *_Nonnull pk);

TW_EXPORT_STATIC_METHOD
bool TWPrivateKeyIsValid(TWData *_Nonnull data);

TW_EXPORT_PROPERTY
TWData *_Nonnull TWPrivateKeyData(struct TWPrivateKey *_Nonnull pk);

/// Returns the public key associated with this pirvate key.
TW_EXPORT_METHOD
struct TWPublicKey TWPrivateKeyGetPublicKey(struct TWPrivateKey *_Nonnull pk, bool compressed);

/// Signs a digest using ECDSA secp256k1.
TW_EXPORT_METHOD
TWData *_Nullable TWPrivateKeySign(struct TWPrivateKey *_Nonnull pk, TWData *_Nonnull digest);

/// Signs a digest using ECDSA secp256k1. The result is encoded with DER.
TW_EXPORT_METHOD
TWData *_Nullable TWPrivateKeySignAsDER(struct TWPrivateKey *_Nonnull pk, TWData *_Nonnull digest);

TW_EXTERN_C_END

#if defined(__cplusplus)
#include <array>
#include <memory>
#include <vector>

struct TWPrivateKey {
    std::array<uint8_t, TWPrivateKeySize> bytes;

    template<typename T>
    static bool isValid(const T& data) {
        // Check length
        if (data.size() != TWPrivateKeySize) {
            return false;
        }

        // Check for zero address
        for (size_t i = 0; i < TWPrivateKeySize; i += 1) {
            if (data[i] != 0) {
                return true;
            }
        }

        return false;
    }

    template<typename T>
    TWPrivateKey(const T& data) {
        assert(data.size() == TWPrivateKeySize);
        std::copy(std::begin(data), std::end(data), std::begin(bytes));
    }

    /// Returns the public key data for this private key.
    std::vector<uint8_t> getPublicKey(bool compressed) const;

    /// Signs a digest using ECDSA secp256k1.
    std::array<uint8_t, 65> sign(const std::vector<uint8_t>&  digest) const;

    /// Signs a digest using ECDSA secp256k1. The result is encoded with DER.
    std::vector<uint8_t> signAsDER(const std::vector<uint8_t>&  digest) const;
};

inline bool operator==(const TWPrivateKey& lhs, const TWPrivateKey& rhs) { return lhs.bytes == rhs.bytes; }
inline bool operator!=(const TWPrivateKey& lhs, const TWPrivateKey& rhs) { return lhs.bytes != rhs.bytes; }

using TWPrivateKeyUniquePtr = std::unique_ptr<TWPrivateKey, void (*)(TWPrivateKey *_Nonnull)>;
using TWPrivateKeySharedPtr = std::shared_ptr<TWPrivateKey>;

static inline TWPrivateKeyUniquePtr TWPrivateKeyMakeUnique(TWPrivateKey *_Nonnull raw) {
    return TWPrivateKeyUniquePtr(raw, TWPrivateKeyDelete);
}

static inline TWPrivateKeySharedPtr TWPrivateKeyMakeShared(TWPrivateKey *_Nonnull raw) {
    return TWPrivateKeySharedPtr(raw, TWPrivateKeyDelete);
}

#endif
