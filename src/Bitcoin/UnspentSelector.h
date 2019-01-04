// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "UnspentTransaction.h"

#include <numeric>
#include <vector>

namespace TW {
namespace Bitcoin {

class UnspentSelector {
public:
    /// Network fee for each transaction byte.
    static const int64_t byteFee;

    /// Maximum allowable transaction dust.
    static const int64_t dustThreshold;

    /// Selects unspent transactions to use given a target transaction value.
    ///
    /// \returns the list of selected utxos or an empty list if there are insufficient funds.
    static std::vector<UnspentTransaction> select(const std::vector<UnspentTransaction>& utxos, int64_t targetValue);

    static int64_t calculateFee(size_t inputs, size_t outputs = 2);
};

}} // namespace
