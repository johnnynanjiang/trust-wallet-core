// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "UnspentSelector.h"

#include <algorithm>

using namespace TW;
using namespace TW::Bitcoin;

const int64_t UnspentSelector::byteFee = 1;
const int64_t UnspentSelector::dustThreshold = 3 * 182;

/// A selection of unspent transactions.
struct Selection {
    std::vector<UnspentTransaction> utxos;
    int64_t total;
};

std::vector<Selection> buildSelections(const std::vector<UnspentTransaction>& utxos, size_t maxSize, int64_t targetValue) {
    std::vector<Selection> selections{ Selection{{}, {}} };
    std::vector<UnspentTransaction> stack = utxos;
    while (!stack.empty()) {
        auto utxo = stack.back();
        stack.pop_back();

        // For every existing selection add a new one that inclues this utxo
        const auto count = selections.size();
        for (auto i = 0; i < count; i += 1) {
            if (selections[i].utxos.size() == maxSize) {
                // Limit selection size to avoid combinatorial explosion
                continue;
            }
            auto newSelection = selections[i];
            newSelection.utxos.push_back(utxo);
            newSelection.total += utxo.amount;
            selections.push_back(newSelection);
        }
    }

    // Remove selections that are outside the target range
    selections.erase(std::remove_if(selections.begin(), selections.end(), [targetValue](const Selection& s) {
        auto fee = UnspentSelector::calculateFee(s.utxos.size(), 2);
        return s.total < targetValue + fee;
    }), selections.end());
    return selections;
}

std::vector<UnspentTransaction> UnspentSelector::select(const std::vector<UnspentTransaction>& utxos, int64_t targetValue) {
    // if target value is zero, fee is zero
    if (targetValue == 0) {
        return {};
    }

    int64_t sum = 0;
    for (auto& utxo : utxos) {
        sum += utxo.amount;
    }

    // total values of utxos should be greater than targetValue
    if (sum < targetValue || utxos.empty()) {
        return {};
    }

    // difference from 2x targetValue
    const auto doubleTargetValue = targetValue * 2;
    auto distFrom2x = [doubleTargetValue](int64_t val) -> int64_t {
        if (val > doubleTargetValue)
            return val - doubleTargetValue;
        else
            return doubleTargetValue - val;
    };

    // Get all possible utxo selections up to a maximum size, sort by total amount
    auto selections = buildSelections(utxos, 5, targetValue);
    std::sort(selections.begin(), selections.end(), [distFrom2x](const Selection& lhs, const Selection& rhs) {
        return distFrom2x(lhs.total) < distFrom2x(rhs.total);
    });

    if (selections.empty()) {
        return {};
    }
    return selections.front().utxos;
}

int64_t UnspentSelector::calculateFee(size_t inputs, size_t outputs) {
    const auto txsize = ((148 * inputs) + (34 * outputs) + 10);
    return int64_t(txsize) * UnspentSelector::byteFee;
}
