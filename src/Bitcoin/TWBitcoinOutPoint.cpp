// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinOutPoint.h>
#include <string.h>

#include "TWBinaryCoding.h"

bool TWBitcoinOutPointInitWithHash(struct TWBitcoinOutPoint *_Nonnull outPoint, TWData *_Nonnull hash, uint32_t index) {
    if (TWDataSize(hash) != 32) {
        return false;
    }

    TWDataCopyBytes(hash, 0, 32, outPoint->hash);
    outPoint->index = index;
    return true;
}

bool TWBitcoinOutPointEqual(struct TWBitcoinOutPoint lhs, struct TWBitcoinOutPoint rhs) {
    return memcmp(lhs.hash, rhs.hash, 32) == 0 && lhs.index == rhs.index;
}

TWData *_Nonnull TWBitcoinOutPointHash(struct TWBitcoinOutPoint outPoint) {
    return TWDataCreateWithBytes(outPoint.hash, 32);
}

uint32_t TWBitcoinOutPointIndex(struct TWBitcoinOutPoint outPoint) {
    return outPoint.index;
}

TWData *_Nonnull TWBitcoinOutPointEncode(struct TWBitcoinOutPoint outPoint) {
    std::vector<uint8_t> data;
    reinterpret_cast<const TW::Bitcoin::OutPoint&>(outPoint).encode(data);
    return TWDataCreateWithBytes(data.data(), data.size());
}

void TW::Bitcoin::OutPoint::encode(std::vector<uint8_t>& data) const {
    std::copy(std::begin(hash), std::end(hash), std::back_inserter(data));
    encode32(index, data);
}
