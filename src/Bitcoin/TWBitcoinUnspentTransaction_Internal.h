// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinTransactionOutput.h>

#include <memory>

struct TWBitcoinUnspentTransaction {
    /// Transaction out point.
    TWBitcoinOutPoint outPoint;

    /// Script setting up conditions to claim this output.
    TWBitcoinScriptSharedPtr script;

    /// Output amount.
    uint64_t amount;
};
