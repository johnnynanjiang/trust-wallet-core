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

struct TWPrivateKey {
    uint8_t bytes[TWPrivateKeySize];
};

struct TWPrivateKey *_Nullable TWPrivateKeyCreate() {
    struct TWPrivateKey *pk = (struct TWPrivateKey *)malloc(TWPrivateKeySize);
    random_buffer(pk->bytes, TWPrivateKeySize);

    TWData *data = TWDataCreateWithBytes(pk->bytes, TWPrivateKeySize);
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
    TWDataCopyBytes(data, 0, TWPrivateKeySize, pk->bytes);
    return pk;
}

void TWPrivateKeyDelete(struct TWPrivateKey *_Nonnull pk) {
    memset(pk->bytes, 0, TWPrivateKeySize);
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
    return TWDataCreateWithBytes(pk->bytes, TWPrivateKeySize);
}

struct TWPublicKey TWPrivateKeyGetPublicKey(struct TWPrivateKey *_Nonnull pk, bool compressed) {
    struct TWPublicKey result;
    if (compressed)  {
         ecdsa_get_public_key33(&secp256k1, pk->bytes, result.bytes);
     } else {
         ecdsa_get_public_key65(&secp256k1, pk->bytes, result.bytes);
     }

    return result;
}

TWData *TWPrivateKeySign(struct TWPrivateKey *_Nonnull pk, TWData *_Nonnull digest) {
    uint8_t result[65];
    uint8_t *bytes = TWDataBytes(digest);
    bool success = ecdsa_sign_digest(&secp256k1, pk->bytes, bytes, result, result + 64, NULL) == 0;
    TWDataReleaseBytes(digest, bytes);
    if (success) {
        return TWDataCreateWithBytes(result, 65);
    } else {
        return NULL;
    }
}

TWData *TWPrivateKeySignAsDER(struct TWPrivateKey *_Nonnull pk, TWData *_Nonnull digest) {
    uint8_t sig[64];
    uint8_t *bytes = TWDataBytes(digest);
    bool success = ecdsa_sign_digest(&secp256k1, pk->bytes, bytes, sig, NULL, NULL);
    TWDataReleaseBytes(digest, bytes);

    if (!success) {
        return NULL;
    }

    uint8_t result[72];
    size_t size = ecdsa_sig_to_der(sig, result);

    return TWDataCreateWithBytes(result, size);
}
