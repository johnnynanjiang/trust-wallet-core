// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWHash.h>

#include <TrezorCrypto/blake2b.h>
#include <TrezorCrypto/ripemd160.h>
#include <TrezorCrypto/sha2.h>
#include <TrezorCrypto/sha3.h>

#include <stdlib.h>
#include <string.h>


void TWHashSHA1(struct TWData data, uint8_t result[_Nonnull TWHashSHA1Length]) {
    sha1_Raw(data.bytes, data.len, result);
}

void TWHashSHA256(struct TWData data, uint8_t result[_Nonnull TWHashSHA256Length]) {
    sha256_Raw(data.bytes, data.len, result);
}

void TWHashSHA512(struct TWData data, uint8_t result[_Nonnull TWHashSHA512Length]) {
    sha512_Raw(data.bytes, data.len, result);
}

void TWHashKeccak256(struct TWData data, uint8_t *_Nonnull result) {
    keccak_256(data.bytes, data.len, result);
}

void TWHashKeccak512(struct TWData data, uint8_t *_Nonnull result) {
    keccak_512(data.bytes, data.len, result);
}

void TWHashSHA3_256(struct TWData data, uint8_t *_Nonnull result) {
    sha3_256(data.bytes, data.len, result);
}

void TWHashSHA3_512(struct TWData data, uint8_t *_Nonnull result) {
    sha3_512(data.bytes, data.len, result);
}

void TWHashRIPEMD(struct TWData data, uint8_t result[_Nonnull TWHashRipemdLength]) {
    ripemd160(data.bytes, data.len, result);
}

void TWHashBlake2b(struct TWData data, uint8_t *_Nonnull result, size_t outlen) {
    blake2b(data.bytes, data.len, result, outlen);
}
