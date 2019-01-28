// Copyright © 2017 Pieter Wuille
// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Bech32Address.h"

#include "../Bech32.h"
#include <TrustWalletCore/TWHRP.h>
#include <TrezorCrypto/ecdsa.h>

using namespace TW::Bitcoin;
typedef std::vector<uint8_t> Data;

/** Convert from one power-of-2 number base to another. */
template<int frombits, int tobits, bool pad>
static inline bool convertbits(Data& out, const Data& in) {
    int acc = 0;
    int bits = 0;
    const int maxv = (1 << tobits) - 1;
    const int max_acc = (1 << (frombits + tobits - 1)) - 1;
    for (size_t i = 0; i < in.size(); ++i) {
        int value = in[i];
        acc = ((acc << frombits) | value) & max_acc;
        bits += frombits;
        while (bits >= tobits) {
            bits -= tobits;
            out.push_back((acc >> bits) & maxv);
        }
    }
    if (pad) {
        if (bits) out.push_back((acc << (tobits - bits)) & maxv);
    } else if (bits >= frombits || ((acc << (tobits - bits)) & maxv)) {
        return false;
    }
    return true;
}

bool Bech32Address::isValid(const std::string& addr) {
    auto dec = Bech32::decode(addr);
    if (dec.second.empty()) {
        return false;
    }

    Data conv;
    if (!convertbits<5, 8, false>(conv, Data(dec.second.begin() + 1, dec.second.end())) ||
        conv.size() < 2 || conv.size() > 40 || dec.second[0] > 16 || (dec.second[0] == 0 &&
        conv.size() != 20 && conv.size() != 32)) {
        return false;
    }

    return true;
}

Bech32Address::Bech32Address(const PublicKey& publicKey, const std::string& hrp) : hrp(hrp), witnessVersion(), witnessProgram() {
    witnessProgram.resize(20);
    ecdsa_get_pubkeyhash(publicKey.bytes.data(), HASHER_SHA2_RIPEMD, witnessProgram.data());
}

std::pair<Bech32Address, bool> Bech32Address::decode(const std::string& addr) {
    auto dec = Bech32::decode(addr);
    if (dec.second.empty()) {
        return std::make_pair(Bech32Address(), false);
    }

    Data conv;
    if (!convertbits<5, 8, false>(conv, Data(dec.second.begin() + 1, dec.second.end())) ||
        conv.size() < 2 || conv.size() > 40 || dec.second[0] > 16 || (dec.second[0] == 0 &&
        conv.size() != 20 && conv.size() != 32)) {
        return std::make_pair(Bech32Address(), false);
    }

    return std::make_pair(Bech32Address(dec.first, dec.second[0], conv), true);
}

std::string Bech32Address::encode() const {
    Data enc;
    enc.push_back(witnessVersion);
    convertbits<8, 5, true>(enc, witnessProgram);
    std::string result = Bech32::encode(hrp, enc);
    if (!decode(result).second) {
        return {};
    }
    return result;
}

std::pair<Bech32Address, bool> Bech32Address::fromRaw(const std::string& hrp, const std::vector<uint8_t>& data) {
    Data conv;
    if (!convertbits<5, 8, false>(conv, Data(data.begin() + 1, data.end())) ||
        conv.size() < 2 || conv.size() > 40 || data[0] > 16 || (data[0] == 0 &&
        conv.size() != 20 && conv.size() != 32)) {
        return std::make_pair(Bech32Address(), false);
    }

    return std::make_pair(Bech32Address(hrp, data[0], conv), true);
}
