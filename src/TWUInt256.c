// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWUInt256.h>

#include <TrezorCrypto/bignum.h>
#include <stdlib.h>
#include <string.h>

struct TWUInt256 {
    bignum256 number;
};

struct TWUInt256 *_Nonnull TWUInt256Zero() {
    struct TWUInt256 * ptr = (struct TWUInt256 *)malloc(sizeof(struct TWUInt256));
    bn_zero(&ptr->number);
    return ptr;
}

struct TWUInt256 *_Nonnull TWUInt256One(void) {
    struct TWUInt256 * ptr = (struct TWUInt256 *)malloc(sizeof(struct TWUInt256));
    bn_one(&ptr->number);
    return ptr;
}

struct TWUInt256 *_Nullable TWUInt256CreateWithData(struct TWData data) {
    uint8_t padded[32];
    if (data.len < 32) {
        memset(padded, 0, 32);
        memcpy(padded + 32 - data.len, data.bytes, data.len);
    } else {
        memcpy(padded, data.bytes, 32);
    }

    struct TWUInt256 * ptr = (struct TWUInt256 *)malloc(sizeof(struct TWUInt256));
    bn_read_be(padded, &ptr->number);
    return ptr;
}

struct TWUInt256 *_Nonnull TWUInt256CreateWithUInt32(uint32_t number) {
    struct TWUInt256 * ptr = (struct TWUInt256 *)malloc(sizeof(struct TWUInt256));
    bn_read_uint32(number, &ptr->number);
    return ptr;
}

struct TWUInt256 *_Nonnull TWUInt256CreateWithUInt64(uint64_t number) {
    struct TWUInt256 * ptr = (struct TWUInt256 *)malloc(sizeof(struct TWUInt256));
    bn_read_uint64(number, &ptr->number);
    return ptr;
}

void TWUInt256Delete(struct TWUInt256 *_Nonnull ptr) {
    free(ptr);
}

bool TWUInt256IsZero(struct TWUInt256 *_Nonnull ptr) {
    return bn_is_zero(&ptr->number) != 0;
}

uint32_t TWUInt256UInt32Value(struct TWUInt256 *_Nonnull ptr) {
    return bn_write_uint32(&ptr->number);
}

uint64_t TWUInt256UInt64Value(struct TWUInt256 *_Nonnull ptr) {
    return bn_write_uint64(&ptr->number);
}

void TWUInt256Data(struct TWUInt256 *_Nonnull ptr, uint8_t *_Nonnull data) {
    bn_write_be(&ptr->number, data);
}

bool TWUInt256Equal(struct TWUInt256 *_Nonnull lhs, struct TWUInt256 *_Nonnull rhs) {
    return bn_is_equal(&lhs->number, &rhs->number) != 0;
}

bool TWUInt256Less(struct TWUInt256 *_Nonnull lhs, struct TWUInt256 *_Nonnull rhs) {
    return bn_is_less(&lhs->number, &rhs->number) != 0;
}

size_t TWUInt256Format(struct TWUInt256 *_Nonnull ptr, int decimals, int exponent, char *_Nonnull output, size_t outlen) {
    return bn_format(&ptr->number, NULL, NULL, decimals, exponent, false, output, outlen);
}
