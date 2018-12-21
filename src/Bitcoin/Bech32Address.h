// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../PublicKey.h"

#include <stdint.h>
#include <string>

namespace TW {
namespace Bitcoin {

class Bech32Address {
public:
    /// Address data.
    uint8_t data[33];

    /// Human-readable part.
    ///
    /// \see https://github.com/satoshilabs/slips/blob/master/slip-0173.md
    const char *_Nullable hrp;

    /// Determines whether a collection of bytes makes a valid Bech32 address.
    template<typename T>
    static bool isValid(const T& data) {
        return data.size() == 33 && data[0] == 0x00;
    }

    /// Determines whether a string makes a valid Bech32 address.
    static bool isValid(const std::string& string);

    /// Initializes a Bech32 address with a string representation.
    Bech32Address(const std::string& string);

    /// Initializes a Bech32 address with a collection of bytes and a HRP prefix.
    Bech32Address(const std::vector<uint8_t>& data, const std::string& hrp);

    /// Initializes a Bech32 address with a public key and a HRP prefix.
    Bech32Address(const PublicKey& publicKey, const std::string& hrp);

    /// Returns a string representation of the address.
    std::string string() const;
};

static inline bool operator==(const Bech32Address& lhs, const Bech32Address& rhs) {
    return memcmp(lhs.data, rhs.data, 33) == 0 && lhs.hrp == rhs.hrp;
}

}} // namespace
