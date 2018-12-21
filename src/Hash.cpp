// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Hash.h"

#include <TrezorCrypto/blake2b.h>
#include <TrezorCrypto/ripemd160.h>
#include <TrezorCrypto/sha2.h>
#include <TrezorCrypto/sha3.h>

using namespace TW;

std::vector<uint8_t> Hash::sha1(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(sha1Size);
    sha1_Raw(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::sha256(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(sha256Size);
    sha256_Raw(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::sha512(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(sha512Size);
    sha512_Raw(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::keccak256(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(sha256Size);
    keccak_256(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::keccak512(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(sha512Size);
    keccak_512(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::sha3_256(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(sha256Size);
    ::sha3_256(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::sha3_512(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(sha512Size);
    ::sha3_512(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::ripemd(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result(ripemdSize);
    ripemd160(data.data(), data.size(), result.data());
    return result;
}

std::vector<uint8_t> Hash::blake2b(const std::vector<uint8_t>& data, size_t size) {
    std::vector<uint8_t> result(size);
    ::blake2b(data.data(), data.size(), result.data(), size);
    return result;
}
