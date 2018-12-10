// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionInput.h>
#include <TrustWalletCore/TWBitcoinOutPoint.h>
#include <TrustWalletCore/TWBitcoinScript.h>

#include <vector>

#include "TWBinaryCoding.h"

struct TWBitcoinTransactionInput {
    /// The previous output transaction reference, as an OutPoint structure
    struct TWBitcoinOutPoint previousOutput;

    /// Computational Script for confirming transaction authorization
    struct TWBitcoinScript *script;

    /// Transaction version as defined by the sender.
    ///
    /// Intended for "replacement" of transactions when information is updated before inclusion into a block.
    uint32_t sequence;

    /// Witness stack.
    std::vector<std::vector<uint8_t>> scriptWitness;
};

struct TWBitcoinTransactionInput *_Nonnull TWBitcoinTransactionInputCreate(struct TWBitcoinOutPoint previousOutput, struct TWBitcoinScript *_Nonnull script, uint32_t sequence) {
    auto output = new TWBitcoinTransactionInput{
        .previousOutput = previousOutput,
        .script = TWBitcoinScriptCreateCopy(script),
        .sequence = sequence
    };
    return output;
}

void TWBitcoinTransactionInputDelete(struct TWBitcoinTransactionInput *_Nonnull input) {
    TWBitcoinScriptDelete(input->script);
    delete input;
}

struct TWBitcoinOutPoint TWBitcoinTransactionInputPreviousOutput(struct TWBitcoinTransactionInput *_Nonnull input) {
    return input->previousOutput;
}

struct TWBitcoinScript *TWBitcoinTransactionInputScript(struct TWBitcoinTransactionInput *_Nonnull input) {
    return input->script;
}

uint32_t TWBitcoinTransactionInputSequence(struct TWBitcoinTransactionInput *_Nonnull input) {
    return input->sequence;
}

TWData *_Nonnull TWBitcoinTransactionInputEncode(struct TWBitcoinTransactionInput *_Nonnull input) {
    auto data = TWDataCreateWithSize(0);
    TWBitcoinTransactionInputEncodeRaw(input, data);
    return data;
}

void TWBitcoinTransactionInputEncodeRaw(struct TWBitcoinTransactionInput *_Nonnull input, TWData *_Nonnull data) {
    TWBitcoinOutPointEncodeRaw(input->previousOutput, data);
    TWBitcoinScriptEncodeRaw(input->script, data);

    uint8_t sequenceData[4];
    encode32(input->sequence, sequenceData);
    TWDataAppendBytes(data, sequenceData, 4);
}

void TWBitcoinTransactionInputEncodeWitness(struct TWBitcoinTransactionInput *_Nonnull input, TWData *_Nonnull data) {
    TWWriteCompactSize(input->scriptWitness.size(), data);
    for (auto& item : input->scriptWitness) {
        TWWriteCompactSize(item.size(), data);
        TWDataAppendBytes(data, item.data(), item.size());
    }
}
