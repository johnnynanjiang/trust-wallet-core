// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBech32Address.h>

#include "../Bech32Address.h"

#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWPublicKey.h>
#include <TrustWalletCore/TWHRP.h>

#include <TrezorCrypto/ecdsa.h>
#include <TrezorCrypto/segwit_addr.h>
#include <string.h>
#include <memory>

using namespace TW::Bitcoin;

static bool TWBech32AddressInitHRPWithString(struct TWBech32Address *_Nonnull address, enum TWHRP hrp) {
    auto hrpString = stringForHRP(hrp);
    if (hrpString == nullptr) {
        return false;
    }

    address->hrp = hrp;
    return true;
}

bool TWBech32AddressEqual(struct TWBech32Address lhs, struct TWBech32Address rhs) {
    return memcmp(lhs.data, rhs.data, 33) == 0 && lhs.hrp == rhs.hrp;
}

bool TWBech32AddressIsValid(TWData *_Nonnull data) {
    auto d = reinterpret_cast<const std::vector<uint8_t>*>(data);
    return Bech32Address::isValid(*d);
}

bool TWBech32AddressIsValidString(TWString *_Nonnull string) {
    auto s = reinterpret_cast<const std::string*>(string);
    return Bech32Address::isValid(*s);
}

bool TWBech32AddressInitWithString(struct TWBech32Address *_Nonnull address, TWString *_Nonnull string) {
    char hrp[80];
    size_t dataLen;
    auto stringBytes = TWStringUTF8Bytes(string);
    if (bech32_decode(hrp, address->data, &dataLen, stringBytes) == 0 || dataLen != 33) {
        return false;
    }

    address->hrp = hrpForString(hrp);
    if (address->hrp == TWHRPUnknown) {
        return false;
    }

    return true;
}

bool TWBech32AddressInitWithData(struct TWBech32Address *_Nonnull address, TWData *_Nonnull data, enum TWHRP hrp) {
    if (!TWBech32AddressIsValid(data)) {
        return false;
    }

    TWDataCopyBytes(data, 0, 33, address->data);

    return TWBech32AddressInitHRPWithString(address, hrp);
}

bool TWBech32AddressInitWithPublicKey(struct TWBech32Address *_Nonnull address, struct TWPublicKey publicKey, enum TWHRP hrp) {
    uint8_t keyhash[20];
    ecdsa_get_pubkeyhash(publicKey.bytes, HASHER_SHA2_RIPEMD, keyhash);

    segwit_addr(address->data, 0, keyhash, 20);

    return TWBech32AddressInitHRPWithString(address, hrp);
}

TWString *_Nonnull TWBech32AddressDescription(struct TWBech32Address address) {
    auto hrpString = stringForHRP(address.hrp);
    char result[89];
    bech32_encode(result, hrpString, address.data, 33);
    return TWStringCreateWithUTF8Bytes(result);
}

TWData *_Nonnull TWBech32AddressData(struct TWBech32Address address) {
    return TWDataCreateWithBytes(address.data, 33);
}

enum TWHRP TWBech32AddressHRP(struct TWBech32Address address) {
    return address.hrp;
}
