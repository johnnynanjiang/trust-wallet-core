// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWBitcoinScript.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWBitcoinTransactionOutput;

/// Creates a transaction output with a value and a script.
TW_EXPORT_STATIC_METHOD
struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinTransactionOutputCreate(uint64_t value, struct TWBitcoinScript *_Nullable script);

TW_EXPORT_METHOD
void TWBitcoinTransactionOutputDelete(struct TWBitcoinTransactionOutput *_Nonnull output);

/// Compares two outputs for equality.
TW_EXPORT_STATIC_METHOD
bool TWBitcoinTransactionOutputEqual(const struct TWBitcoinTransactionOutput *_Nonnull lhs, const struct TWBitcoinTransactionOutput *_Nonnull rhs);

/// Output amount.
TW_EXPORT_PROPERTY
uint64_t TWBitcoinTransactionOutputAmount(const struct TWBitcoinTransactionOutput *_Nonnull output);

/// Script with the conditions to get this output.
TW_EXPORT_PROPERTY
const struct TWBitcoinScript *_Nonnull TWBitcoinTransactionOutputScript(const struct TWBitcoinTransactionOutput *_Nonnull output);

/// Encodes the output.
TW_EXPORT_METHOD
TWData *_Nonnull TWBitcoinTransactionOutputEncode(const struct TWBitcoinTransactionOutput *_Nonnull output);

TW_EXTERN_C_END

#if defined(__cplusplus)
#include <memory>

struct TWBitcoinTransactionOutput {
    /// Transaction amount.
    uint64_t value;

    /// Usually contains the public key as a Bitcoin script setting up conditions to claim this output.
    TWBitcoinScript script;

    TWBitcoinTransactionOutput() = default;
    TWBitcoinTransactionOutput(uint64_t value, const TWBitcoinScript& script) : value(value), script(script) {}

    /// Encodes the output for the signature pre-image.
    void encode(std::vector<uint8_t>& data) const;
};

using TWBitcoinTransactionOutputUniquePtr = std::unique_ptr<TWBitcoinTransactionOutput, void (*)(TWBitcoinTransactionOutput *_Nonnull)>;
using TWBitcoinTransactionOutputSharedPtr = std::shared_ptr<TWBitcoinTransactionOutput>;

static inline TWBitcoinTransactionOutputUniquePtr TWBitcoinTransactionOutputMakeUnique(TWBitcoinTransactionOutput *_Nonnull raw) {
    return TWBitcoinTransactionOutputUniquePtr(raw, TWBitcoinTransactionOutputDelete);
}

static inline TWBitcoinTransactionOutputSharedPtr TWBitcoinTransactionOutputMakeShared(TWBitcoinTransactionOutput *_Nonnull raw) {
    return TWBitcoinTransactionOutputSharedPtr(raw, TWBitcoinTransactionOutputDelete);
}

#endif
