// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TransactionInput.h"

#include "TWBinaryCoding.h"

using namespace TW::Bitcoin;

void TransactionInput::encode(std::vector<uint8_t>& data) const {
    auto& outpoint = reinterpret_cast<const TW::Bitcoin::OutPoint&>(previousOutput);
    outpoint.encode(data);
    script.encode(data);
    encode32(sequence, data);
}

void TransactionInput::encodeWitness(std::vector<uint8_t>& data) const {
    TWWriteCompactSize(scriptWitness.size(), data);
    for (auto& item : scriptWitness) {
        TWWriteCompactSize(item.size(), data);
        std::copy(std::begin(item), std::end(item), std::back_inserter(data));
    }
}
