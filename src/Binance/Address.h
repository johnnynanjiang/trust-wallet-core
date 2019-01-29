// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../PublicKey.h"

#include <stdint.h>
#include <string>

namespace TW {
namespace Binance {

class Address {
public:
    /// Public key hash.
    std::vector<uint8_t> keyHash;

    /// Whether this is a testnet address.
    bool test = false;

    /// Determines whether a string makes a valid Binance address.
    static bool isValid(const std::string& string);

    /// Initializes an address with a key hash.
    Address(const std::vector<uint8_t>& keyHash, bool test = false) : keyHash(keyHash), test(test) {}

    /// Initializes an address with a key hash.
    Address(std::vector<uint8_t>&& keyHash, bool test = false) : keyHash(keyHash), test(test) {}

    /// Initializes an address with a public key.
    Address(const PublicKey& publicKey, bool test = false);

    /// Decodes an address.
    ///
    /// \returns a pair with the address and a success flag.
    static std::pair<Address, bool> decode(const std::string& addr);

    /// Encodes the address.
    ///
    /// \returns encoded address string, or empty string on failure.
    std::string encode() const;

    bool operator==(const Address& rhs) const {
        return keyHash == rhs.keyHash && test == rhs.test;
    }

private:
    Address() = default;
};

}} // namespace

/// Wrapper for C interface.
struct TWBinanceAddress {
    TW::Binance::Address impl;
};
