// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Script.h"

#include <memory>

namespace TW {
namespace Bitcoin {

/// Bitcoin transaction output.
struct TransactionOutput {
    /// Transaction amount.
    int64_t value;

    /// Usually contains the public key as a Bitcoin script setting up conditions to claim this output.
    Script script;

    /// Initializes an empty transaction output.
    TransactionOutput() = default;

    /// Initializes a transaction output with a value and a script.
    TransactionOutput(uint64_t value, const Script& script) : value(value), script(script) {}

    /// Encodes the output into the provided buffer.
    void encode(std::vector<uint8_t>& data) const;
};

}} // namespace

/// Wrapper for C interface.
struct TWBitcoinTransactionOutput {
    TW::Bitcoin::TransactionOutput impl;
};
