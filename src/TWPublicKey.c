// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWPublicKey.h>

#include <TrezorCrypto/ecdsa.h>

#include <stdlib.h>
#include <string.h>

bool TWPublicKeyInitWithData(struct TWPublicKey *_Nonnull pk, struct TWData data) {
    if (!TWPublicKeyIsValid(data)) {
        return false;
    }

    memcpy(pk->bytes, data.bytes, TWPublicKeyUncompressedSize);
    return true;
}

bool TWPublicKeyIsValid(struct TWData data) {
    switch (data.bytes[0]) {
    case 2:
    case 3:
        return data.len == TWPublicKeyCompressedSize;
    case 4:
    case 6:
    case 7:
        return data.len == TWPublicKeyUncompressedSize;
    default:
        return false;
    }
}

bool TWPublicKeyIsCompressed(struct TWPublicKey pk) {
    return pk.bytes[0] == 2 || pk.bytes[0] == 3;
}

void TWPublicKeyCopyBytes(struct TWPublicKey pk, uint8_t *_Nonnull output) {
    if (TWPublicKeyIsCompressed(pk)) {
        memcpy(output, pk.bytes, TWPublicKeyCompressedSize);
    } else {
        memcpy(output, pk.bytes, TWPublicKeyUncompressedSize);
    }
}

void TWPublicKeyCompressedCopy(struct TWPublicKey from, struct TWPublicKey *_Nonnull to) {
    if (TWPublicKeyIsCompressed(from)) {
        memcpy(to->bytes, from.bytes, TWPublicKeyCompressedSize);
    } else {
        to->bytes[0] = 0x02 | (from.bytes[64] & 0x01);
        memcpy(to->bytes + 1, from.bytes + 1, TWPublicKeyCompressedSize - 1);
    }
}
