// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionInput.h>
#include <TrustWalletCore/TWBitcoinOutPoint.h>

#include <vector>

#include "TWBinaryCoding.h"

struct TWBitcoinTransactionInput *_Nonnull TWBitcoinTransactionInputCreate(struct TWBitcoinOutPoint previousOutput, struct TWBitcoinScript *_Nullable script, uint32_t sequence) {
    auto input = new TWBitcoinTransactionInput(previousOutput, script ? *script : TWBitcoinScript(), sequence);
    return input;
}

void TWBitcoinTransactionInputDelete(struct TWBitcoinTransactionInput *_Nonnull input) {
    delete input;
}

struct TWBitcoinOutPoint TWBitcoinTransactionInputPreviousOutput(const struct TWBitcoinTransactionInput *_Nonnull input) {
    return input->previousOutput;
}

const struct TWBitcoinScript *TWBitcoinTransactionInputScript(const struct TWBitcoinTransactionInput *_Nonnull input) {
    return &input->script;
}

uint32_t TWBitcoinTransactionInputSequence(const struct TWBitcoinTransactionInput *_Nonnull input) {
    return input->sequence;
}

TWData *_Nonnull TWBitcoinTransactionInputEncode(const struct TWBitcoinTransactionInput *_Nonnull input) {
    auto data = std::vector<uint8_t>{};
    input->encode(data);
    return TWDataCreateWithBytes(data.data(), data.size());
}

void TWBitcoinTransactionInput::encode(std::vector<uint8_t>& data) const {
    auto& outpoint = reinterpret_cast<const TW::Bitcoin::OutPoint&>(previousOutput);
    outpoint.encode(data);
    script.encode(data);
    encode32(sequence, data);
}

void TWBitcoinTransactionInput::encodeWitness(std::vector<uint8_t>& data) const {
    TWWriteCompactSize(scriptWitness.size(), data);
    for (auto& item : scriptWitness) {
        TWWriteCompactSize(item.size(), data);
        std::copy(std::begin(item), std::end(item), std::back_inserter(data));
    }
}
