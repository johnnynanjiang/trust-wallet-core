// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Bech32Address.h"

#include <TrustWalletCore/TWSLIP.h>
#include <TrezorCrypto/ecdsa.h>
#include <TrezorCrypto/segwit_addr.h>

using namespace TW::Bitcoin;

static const char* resolveHRP(const char* hrp) {
    for (auto s : HRP) {
        if (strcmp(hrp, s) == 0) {
            return s;
        }
    }
    return nullptr;
}

static bool isValid(const std::string& string) {
    char hrp[80];
    uint8_t data[33];
    size_t dataLen;
    if (bech32_decode(hrp, data, &dataLen, string.c_str()) == 0 || dataLen != 33) {
        return false;
    }
    if (resolveHRP(hrp) == nullptr) {
        return false;
    }
    return true;
}

Bech32Address::Bech32Address(const std::string& string) {
    char hrp[80];
    size_t dataLen;
    if (bech32_decode(hrp, data, &dataLen, string.c_str()) == 0 || dataLen != 33) {
        assert(false && "Invalid Bech32 string");
    }
    this->hrp = resolveHRP(hrp);
}

Bech32Address::Bech32Address(const std::vector<uint8_t>& data, const std::string& hrp) {
    assert(isValid(data));
    std::copy(data.begin(), data.end(), this->data);
    this->hrp = resolveHRP(hrp.c_str());
}

Bech32Address::Bech32Address(const PublicKey& publicKey, const std::string& hrp) {
    uint8_t keyhash[20];
    ecdsa_get_pubkeyhash(publicKey.bytes.data(), HASHER_SHA2_RIPEMD, keyhash);

    segwit_addr(data, 0, keyhash, 20);
    this->hrp = resolveHRP(hrp.c_str());
}

std::string Bech32Address::string() const {
    char result[89];
    bech32_encode(result, hrp, data, 33);
    return result;
}
