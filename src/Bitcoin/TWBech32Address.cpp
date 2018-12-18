// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBech32Address.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWPublicKey.h>
#include <TrustWalletCore/TWSLIP.h>

#include <TrezorCrypto/ecdsa.h>
#include <TrezorCrypto/segwit_addr.h>
#include <string.h>
#include <memory>

static bool TWBech32AddressInitHRPWithString(struct TWBech32Address *_Nonnull address, TWString *hrp) {
    auto hrpBytes = TWStringUTF8Bytes(hrp);
    for (auto s : HRP) {
        if (strcmp(hrpBytes, s) == 0) {
            address->hrp = s;
            return true;
        }
    }
    return false;
}

bool TWBech32AddressEqual(struct TWBech32Address lhs, struct TWBech32Address rhs) {
    return memcmp(lhs.data, rhs.data, 33) == 0 && strcmp(lhs.hrp, rhs.hrp) == 0;
}

bool TWBech32AddressIsValid(TWData *_Nonnull data) {
    return TWDataSize(data) == 33 && TWDataGet(data, 0) == 0x00;
}

bool TWBech32AddressInitWithString(struct TWBech32Address *_Nonnull address, TWString *_Nonnull string) {
    char hrp[80];
    size_t dataLen;
    auto stringBytes = TWStringUTF8Bytes(string);
    if (bech32_decode(hrp, address->data, &dataLen, stringBytes) == 0 || dataLen != 33) {
        return false;
    }

    for (auto s : HRP) {
        if (strcmp(hrp, s) == 0) {
            address->hrp = s;
            return true;
        }
    }

    return false;
}

bool TWBech32AddressInitWithData(struct TWBech32Address *_Nonnull address, TWData *_Nonnull data, TWString *_Nonnull hrp) {
    if (!TWBech32AddressIsValid(data)) {
        return false;
    }

    TWDataCopyBytes(data, 0, 33, address->data);

    return TWBech32AddressInitHRPWithString(address, hrp);
}

bool TWBech32AddressInitWithPublicKey(struct TWBech32Address *_Nonnull address, struct TWPublicKey publicKey, TWString *_Nonnull hrp) {
    uint8_t keyhash[20];
    ecdsa_get_pubkeyhash(publicKey.bytes, HASHER_SHA2_RIPEMD, keyhash);

    segwit_addr(address->data, 0, keyhash, 20);

    return TWBech32AddressInitHRPWithString(address, hrp);
}

TWString *_Nonnull TWBech32AddressDescription(struct TWBech32Address address) {
    char result[89];
    bech32_encode(result, address.hrp, address.data, 33);
    return TWStringCreateWithUTF8Bytes(result);
}

TWData *_Nonnull TWBech32AddressData(struct TWBech32Address address) {
    return TWDataCreateWithBytes(address.data, 33);
}
