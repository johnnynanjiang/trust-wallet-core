// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWPrivateKey.h>

#include <TrezorCrypto/ecdsa.h>

#include <stdlib.h>
#include <string.h>

struct TWPrivateKey {
    uint8_t bytes[TWPrivateKeySize];
};

struct TWPrivateKey *_Nullable TWPrivateKeyCreateWithData(const struct TWData *_Nonnull data) {
    if (!TWPrivateKeyIsValid(data)) {
        return NULL;
    }

    struct TWPrivateKey * pkp = (struct TWPrivateKey *)malloc(TWPrivateKeySize);
    memcpy(pkp->bytes, data->bytes, TWPrivateKeySize);
    return pkp;
}

void TWPrivateKeyDelete(struct TWPrivateKey *_Nonnull pk) {
    memset(pk->bytes, 0, TWPrivateKeySize);
    free(pk);
}

bool TWPrivateKeyIsValid(const struct TWData *_Nonnull data) {
    // Check length
    if (data->bytes == NULL || data->len != TWPrivateKeySize) {
        return false;
    }

    // Check for zero address
    for (size_t i = 0; i < TWPrivateKeySize; i += 1) {
        if (data->bytes[i] != 0) {
            return true;
        }
    }

    return false;
}

void TWPrivateKeyCopyBytes(struct TWPrivateKey *_Nonnull pk, uint8_t *_Nonnull output) {
    memcpy(output, pk->bytes, TWPrivateKeySize);
}
