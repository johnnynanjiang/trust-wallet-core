// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Amount.h"
#include "OutPoint.h"
#include "Script.h"

#include <memory>

namespace TW {
namespace Bitcoin {

struct UnspentTransaction {
    /// Transaction out point.
    OutPoint outPoint;

    /// Script setting up conditions to claim this output.
    Script script;

    /// Output amount.
    Amount amount;

    /// Initializes an empty unspent transaction.
    UnspentTransaction() = default;

    /// Initializes an unspent transaction with an out-point reference, a script and an amount.
    UnspentTransaction(const OutPoint& outPoint, const Script& script, Amount amount) : outPoint(outPoint), script(script), amount(amount) {
        assert(isValidAmount(amount));
    }
};

}} // namespace

/// Wrapper for C interface.
struct TWBitcoinUnspentTransaction {
    TW::Bitcoin::UnspentTransaction impl;
};
