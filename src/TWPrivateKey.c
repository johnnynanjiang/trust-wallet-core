// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWPrivateKey.h>

#include <TrezorCrypto/ecdsa.h>
#include <TrezorCrypto/secp256k1.h>

#include <stdlib.h>
#include <string.h>

struct TWPrivateKey {
    uint8_t bytes[TWPrivateKeySize];
};

struct TWPrivateKey *_Nullable TWPrivateKeyCreateWithData(struct TWData data) {
    if (!TWPrivateKeyIsValid(data)) {
        return NULL;
    }

    struct TWPrivateKey * pkp = (struct TWPrivateKey *)malloc(TWPrivateKeySize);
    memcpy(pkp->bytes, data.bytes, TWPrivateKeySize);
    return pkp;
}

void TWPrivateKeyDelete(struct TWPrivateKey *_Nonnull pk) {
    memset(pk->bytes, 0, TWPrivateKeySize);
    free(pk);
}

bool TWPrivateKeyIsValid(struct TWData data) {
    // Check length
    if (data.bytes == NULL || data.len != TWPrivateKeySize) {
        return false;
    }

    // Check for zero address
    for (size_t i = 0; i < TWPrivateKeySize; i += 1) {
        if (data.bytes[i] != 0) {
            return true;
        }
    }

    return false;
}

void TWPrivateKeyCopyBytes(struct TWPrivateKey *_Nonnull pk, uint8_t *_Nonnull output) {
    memcpy(output, pk->bytes, TWPrivateKeySize);
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

bool TWPrivateKeySign(struct TWPrivateKey *_Nonnull pk, struct TWData digest, uint8_t *_Nonnull output) {
    return ecdsa_sign_digest(&secp256k1, pk->bytes, digest.bytes, output, output + 64, NULL) == 0;
}

size_t TWPrivateKeySignAsDER(struct TWPrivateKey *_Nonnull pk, struct TWData digest, uint8_t *_Nonnull output) {
    uint8_t sig[64];
    ecdsa_sign_digest(&secp256k1, pk->bytes, digest.bytes, sig, NULL, NULL);
    return ecdsa_sig_to_der(sig, output);
}
