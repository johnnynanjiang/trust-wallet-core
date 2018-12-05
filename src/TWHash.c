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

#include <string.h>


TWData *_Nonnull TWHashSHA1(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashSHA1Length];
    uint8_t *dataBytes = TWDataBytes(data);
    sha1_Raw(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA1Length);
}

TWData *_Nonnull TWHashSHA256(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashSHA256Length];
    uint8_t *dataBytes = TWDataBytes(data);
    sha256_Raw(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA256Length);
}

TWData *_Nonnull TWHashSHA512(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashSHA512Length];
    uint8_t *dataBytes = TWDataBytes(data);
    sha512_Raw(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA512Length);
}

TWData *_Nonnull TWHashKeccak256(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashSHA256Length];
    uint8_t *dataBytes = TWDataBytes(data);
    keccak_256(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA256Length);
}

TWData *_Nonnull TWHashKeccak512(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashSHA512Length];
    uint8_t *dataBytes = TWDataBytes(data);
    keccak_512(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA512Length);
}

TWData *_Nonnull TWHashSHA3_256(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashSHA256Length];
    uint8_t *dataBytes = TWDataBytes(data);
    sha3_256(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA256Length);
}

TWData *_Nonnull TWHashSHA3_512(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashSHA512Length];
    uint8_t *dataBytes = TWDataBytes(data);
    sha3_512(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA512Length);
}

TWData *_Nonnull TWHashRIPEMD(TWData *_Nonnull data) {
    uint8_t resultBytes[TWHashRipemdLength];
    uint8_t *dataBytes = TWDataBytes(data);
    ripemd160(dataBytes, TWDataSize(data), resultBytes);
    TWDataReleaseBytes(data, dataBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashRipemdLength);
}

TWData *_Nonnull TWHashBlake2b(TWData *_Nonnull data, size_t outlen) {
    uint8_t *resultBytes = malloc(outlen);
    uint8_t *dataBytes = TWDataBytes(data);
    blake2b(dataBytes, TWDataSize(data), resultBytes, outlen);
    TWDataReleaseBytes(data, dataBytes);
    TWData *result = TWDataCreateWithBytes(resultBytes, outlen);
    free(resultBytes);
    return result;
}

TWData *_Nonnull TWHashSHA256RIPEMD(TWData *_Nonnull data) {
    uint8_t ripemd[TWHashRipemdLength];
    uint8_t *dataBytes = TWDataBytes(data);
    ripemd160(dataBytes, TWDataSize(data), ripemd);
    TWDataReleaseBytes(data, dataBytes);

    uint8_t resultBytes[TWHashSHA256Length];
    sha256_Raw(ripemd, TWHashRipemdLength, resultBytes);
    return TWDataCreateWithBytes(resultBytes, TWHashSHA256Length);
}
