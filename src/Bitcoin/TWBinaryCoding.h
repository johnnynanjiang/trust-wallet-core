// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <stddef.h>
#include <stdint.h>

#define CAST32(x)    ((uint32_t)(x))
#define CAST64(x)    ((uint64_t)(x))

/// Encodes a 16-bit value into the provided buffer.
static inline void encode16(uint16_t val, uint8_t *_Nonnull dst) {
    dst[0] = val;
    dst[1] = val >> 8;
}

/// Decodes a 16-bit value from the provided buffer.
static inline uint16_t decode16(const uint8_t *_Nonnull src) {
    return (uint16_t)(src[0]) | ((uint16_t)(src[1]) << 8);
}

/// Encodes a 32-bit value into the provided buffer.
static inline void encode32(uint32_t val, uint8_t *_Nonnull dst) {
    dst[0] = val;
    dst[1] = (val >> 8);
    dst[2] = (val >> 16);
    dst[3] = (val >> 24);
}

/// Decodes a 32-bit value from the provided buffer.
static inline uint32_t decode32(const uint8_t *_Nonnull src)
{
    return CAST32(src[0])
        | (CAST32(src[1]) << 8)
        | (CAST32(src[2]) << 16)
        | (CAST32(src[3]) << 24);
}

/// Encodes a 64-bit value into the provided buffer.
static inline void encode64(uint64_t val, uint8_t *_Nonnull dst) {
    dst[0] = val;
    dst[1] = (val >> 8);
    dst[2] = (val >> 16);
    dst[3] = (val >> 24);
    dst[4] = (val >> 32);
    dst[5] = (val >> 40);
    dst[6] = (val >> 48);
    dst[7] = (val >> 56);
}

/// Decodes a 64-bit value from the provided buffer.
static inline uint64_t decode64(const uint8_t *_Nonnull src) {
    return CAST64(src[0])
        | (CAST64(src[1]) << 8)
        | (CAST64(src[2]) << 16)
        | (CAST64(src[3]) << 24)
        | (CAST64(src[4]) << 32)
        | (CAST64(src[5]) << 40)
        | (CAST64(src[6]) << 48)
        | (CAST64(src[7]) << 56);
}

/// Encodes a size into the provided buffer using Bitcoin's compact representation.
inline size_t TWWriteCompactSize(uint64_t size, uint8_t *_Nullable result) {
    if (size < 253) {
        if (result) {
            *result = (uint8_t) size;
        }
        return 1;
    }
    
    if (size <= UINT16_MAX) {
        if (result) {
            result[0] = 253;
            encode16((uint16_t) size, result + 1);
        }
        return 3;
    }
    
    if (size <= UINT32_MAX) {
        if (result) {
            result[0] = 254;
            encode32((uint32_t) size, result + 1);
        }
        return 5;
    }
    
    if (result) {
        result[0] = 255;
        encode64((uint64_t) size, result + 1);
    }
    return 9;
}
