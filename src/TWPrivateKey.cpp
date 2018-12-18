// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWPrivateKey.h>

#include <TrezorCrypto/ecdsa.h>
#include <TrezorCrypto/rand.h>
#include <TrezorCrypto/secp256k1.h>

#include <string.h>

struct TWPrivateKey *TWPrivateKeyCreate() {
    struct TWPrivateKey *pk = (struct TWPrivateKey *)malloc(TWPrivateKeySize);
    random_buffer(pk->bytes.data(), TWPrivateKeySize);

    TWData *data = TWDataCreateWithBytes(pk->bytes.data(), TWPrivateKeySize);
    if (!TWPrivateKeyIsValid(data)) {
        abort();
    }

    TWDataDelete(data);
    return pk;
}

struct TWPrivateKey *_Nullable TWPrivateKeyCreateWithData(TWData *_Nonnull data) {
    if (!TWPrivateKeyIsValid(data)) {
        return NULL;
    }

    struct TWPrivateKey *pk = (struct TWPrivateKey *)malloc(TWPrivateKeySize);
    TWDataCopyBytes(data, 0, TWPrivateKeySize, pk->bytes.data());
    return pk;
}

struct TWPrivateKey *_Nullable TWPrivateKeyCreateCopy(struct TWPrivateKey *_Nonnull key) {
    struct TWPrivateKey *pk = (struct TWPrivateKey *)malloc(TWPrivateKeySize);
    memcpy(pk->bytes.data(), key->bytes.data(), TWPrivateKeySize);
    return pk;
}

void TWPrivateKeyDelete(struct TWPrivateKey *_Nonnull pk) {
    if (pk != NULL) {
        memset(pk->bytes.data(), 0, TWPrivateKeySize);
    }
    free(pk);
}

bool TWPrivateKeyIsValid(TWData *_Nonnull data) {
    // Check length
    if (TWDataSize(data) != TWPrivateKeySize) {
        return false;
    }

    // Check for zero address
    for (size_t i = 0; i < TWPrivateKeySize; i += 1) {
        if (TWDataGet(data, i) != 0) {
            return true;
        }
    }

    return false;
}

TWData *TWPrivateKeyData(struct TWPrivateKey *_Nonnull pk) {
    return TWDataCreateWithBytes(pk->bytes.data(), TWPrivateKeySize);
}

struct TWPublicKey TWPrivateKeyGetPublicKey(struct TWPrivateKey *_Nonnull pk, bool compressed) {
    struct TWPublicKey result;
    if (compressed)  {
        ecdsa_get_public_key33(&secp256k1, pk->bytes.data(), result.bytes);
     } else {
        ecdsa_get_public_key65(&secp256k1, pk->bytes.data(), result.bytes);
     }

    return result;
}

std::vector<uint8_t> TWPrivateKey::getPublicKey(bool compressed) const {
    std::vector<uint8_t> result;
    if (compressed)  {
        result.resize(TWPublicKeyCompressedSize);
        ecdsa_get_public_key33(&secp256k1, bytes.data(), result.data());
     } else {
        result.resize(TWPublicKeyUncompressedSize);
        ecdsa_get_public_key65(&secp256k1, bytes.data(), result.data());
     }

    return result;
}

TWData *TWPrivateKeySign(struct TWPrivateKey *_Nonnull pk, TWData *_Nonnull digest) {
    uint8_t result[65];
    uint8_t *bytes = TWDataBytes(digest);
    bool success = ecdsa_sign_digest(&secp256k1, pk->bytes.data(), bytes, result, result + 64, NULL) == 0;
    if (success) {
        return TWDataCreateWithBytes(result, 65);
    } else {
        return NULL;
    }
}

TWData *TWPrivateKeySignAsDER(struct TWPrivateKey *_Nonnull pk, TWData *_Nonnull digest) {
    uint8_t sig[64];
    uint8_t *bytes = TWDataBytes(digest);
    bool success = ecdsa_sign_digest(&secp256k1, pk->bytes.data(), bytes, sig, NULL, NULL) == 0;

    if (!success) {
        return NULL;
    }

    uint8_t result[72];
    size_t size = ecdsa_sig_to_der(sig, result);

    return TWDataCreateWithBytes(result, size);
}

std::array<uint8_t, 65> TWPrivateKey::sign(const std::vector<uint8_t>& digest) const {
    std::array<uint8_t, 65> result;
    bool success = ecdsa_sign_digest(&secp256k1, bytes.data(), digest.data(), result.data(), result.data() + 64, NULL) == 0;
    if (!success) {
        return {};
    }
    return result;
}

std::vector<uint8_t> TWPrivateKey::signAsDER(const std::vector<uint8_t>&  digest) const {
    std::array<uint8_t, 64> sig;
    bool success = ecdsa_sign_digest(&secp256k1, bytes.data(), digest.data(), sig.data(), NULL, NULL) == 0;
    if (!success) {
        return {};
    }

    uint8_t resultBytes[72];
    size_t size = ecdsa_sig_to_der(sig.data(), resultBytes);

    auto result = std::vector<uint8_t>{};
    std::copy(resultBytes, resultBytes + size, std::back_inserter(result));
    return result;
}
