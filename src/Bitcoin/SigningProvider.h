// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Script.h"
#include "../Hash.h"
#include "../PrivateKey.h"

#include <array>
#include <map>
#include <vector>

namespace TW {
namespace Bitcoin {

class SigningProvider {
public:
    std::vector<std::array<uint8_t, PrivateKey::size>> privateKeys;
    std::map<std::array<uint8_t, 20>, std::vector<uint8_t>> scripts;

    template<typename T>
    const std::array<uint8_t, PrivateKey::size>* keyForPublicKeyHash(const T& hash) const {
        for (auto& key : privateKeys) {
            auto publicKey = PrivateKey(key).getPublicKey(true);
            auto keyHash = TW::Hash::ripemd(TW::Hash::sha256(publicKey));
            if (std::equal(std::begin(keyHash), std::end(keyHash), std::begin(hash), std::end(hash))) {
                return &key;
            }
        }
        return {};
    }

    template<typename T>
    const std::vector<uint8_t>* scriptForScriptHash(const T& hash) const {
        auto array = std::array<uint8_t, 20>();
        std::copy(std::begin(hash), std::min(std::begin(hash) + 20, std::end(hash)), std::begin(array));
        auto it = scripts.find(array);
        if (it == scripts.end()) {
            return {};
        }

        return &(it->second);
    }
};

}} // namespace

/// Wrapper for C interface.
struct TWBitcoinSigningProvider {
    TW::Bitcoin::SigningProvider impl;
};
