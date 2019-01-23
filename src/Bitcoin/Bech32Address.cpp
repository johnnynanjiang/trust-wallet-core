// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Bech32Address.h"

#include <TrustWalletCore/TWHRP.h>
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

bool Bech32Address::isValid(const std::string& string) {
    char hrp[80];
    uint8_t data[Bech32Address::size];
    size_t dataLen;
    if (bech32_decode(hrp, data, &dataLen, string.c_str()) == 0 || dataLen != Bech32Address::size) {
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
    if (bech32_decode(hrp, bytes, &dataLen, string.c_str()) == 0 || dataLen != size) {
        assert(false && "Invalid Bech32 string");
    }
    this->hrp = resolveHRP(hrp);
}

Bech32Address::Bech32Address(const PublicKey& publicKey, const std::string& hrp) {
    uint8_t keyhash[20];
    ecdsa_get_pubkeyhash(publicKey.bytes.data(), HASHER_SHA2_RIPEMD, keyhash);
    segwit_addr(bytes, 0, keyhash, 20);
    this->hrp = resolveHRP(hrp.c_str());
}

Bech32Address Bech32Address::fromRaw(const std::vector<uint8_t>& data, const std::string& hrp) {
    Bech32Address address;

    assert(isValid(data));
    std::copy(data.begin(), data.end(), address.bytes);
    address.hrp = resolveHRP(hrp.c_str());

    return address;
}

Bech32Address Bech32Address::fromKeyhash(const std::vector<uint8_t>& keyhash, const std::string& hrp) {
    Bech32Address address;

    assert(keyhash.size() == 20);
    segwit_addr(address.bytes, 0, keyhash.data(), keyhash.size());
    address.hrp = resolveHRP(hrp.c_str());

    return address;
}

std::string Bech32Address::string() const {
    char result[89];
    bech32_encode(result, hrp, bytes, size);
    return result;
}

std::vector<uint8_t> Bech32Address::keyHash() const {
    int witver;
    std::vector<uint8_t> result(40);
    size_t resultlen;
    segwit_data(&witver, result.data(), &resultlen, bytes, Bech32Address::size);
    result.resize(resultlen);
    return result;
}
