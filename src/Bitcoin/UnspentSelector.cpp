// Copyright © 2017-2019 Trust.
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

// Slice Array
// [0,1,2,3,4,5,6,7,8,9].eachSlices(3)
// >
// [[0, 1, 2], [1, 2, 3], [2, 3, 4], [3, 4, 5], [4, 5, 6], [5, 6, 7], [6, 7, 8], [7, 8, 9]]
template<typename T>
static inline std::vector<std::vector<T>> slice(const std::vector<T>& elements, size_t sliceSize) {
    std::vector<std::vector<T>> slices;
    for (auto i = 0; i <= elements.size() - sliceSize; i += 1) {
        slices.emplace_back();
        slices[i].reserve(sliceSize);
        for (auto j = i; j < i + sliceSize; j += 1) {
            slices[i].push_back(elements[j]);
        }
    }
    return slices;
}

static inline int64_t sum(const std::vector<UnspentTransaction>& utxos) {
    int64_t sum = 0;
    for (auto& utxo : utxos)
        sum += utxo.amount;
    return sum;
}

std::vector<UnspentTransaction> UnspentSelector::select(const std::vector<UnspentTransaction>& utxos, int64_t targetValue) {
    // if target value is zero, fee is zero
    if (targetValue == 0) {
        return {};
    }

    // total values of utxos should be greater than targetValue
    if (sum(utxos) < targetValue || utxos.empty()) {
        return {};
    }

    // definitions for the following caluculation
    const auto doubleTargetValue = targetValue * 2;
    auto numOutputs = 2; // if allow multiple output, it will be changed.

    // Get all possible utxo selections up to a maximum size, sort by total amount
    auto sortedUtxos = utxos;
    std::sort(sortedUtxos.begin(), sortedUtxos.end(), [](const UnspentTransaction& lhs, const UnspentTransaction& rhs) {
        return lhs.amount < rhs.amount;
    });

    // difference from 2x targetValue
    auto distFrom2x = [doubleTargetValue](int64_t val) -> int64_t {
        if (val > doubleTargetValue)
            return val - doubleTargetValue;
        else
            return doubleTargetValue - val;
    };

    // 1. Find a combination of the fewest outputs that is
    //    (1) bigger than what we need
    //    (2) closer to 2x the amount,
    //    (3) and does not produce dust change.
    for (auto numInputs = 1; numInputs <= sortedUtxos.size(); numInputs += 1) {
        const auto fee = calculateFee(numInputs, numOutputs);
        const auto targetWithFeeAndDust = targetValue + fee + dustThreshold;
        auto slices = slice(sortedUtxos, numInputs);
        slices.erase(std::remove_if(slices.begin(), slices.end(), [targetWithFeeAndDust](const std::vector<UnspentTransaction>& slice) {
            return sum(slice) < targetWithFeeAndDust;
        }), slices.end());
        if (!slices.empty()) {
            std::sort(slices.begin(), slices.end(), [distFrom2x](const std::vector<UnspentTransaction>& lhs, const std::vector<UnspentTransaction>& rhs) {
                return distFrom2x(sum(lhs)) < distFrom2x(sum(rhs));
            });
            return slices.front();
        }
    }

    // 2. If not, find a combination of outputs that may produce dust change.
    for (auto numInputs = 1; numInputs <= sortedUtxos.size(); numInputs += 1) {
        const auto fee = calculateFee(numInputs, numOutputs);
        const auto targetWithFee = targetValue + fee;
        auto slices = slice(sortedUtxos, numInputs);
        slices.erase(std::remove_if(slices.begin(), slices.end(), [targetWithFee](const std::vector<UnspentTransaction>& slice) {
            return sum(slice) < targetWithFee;
        }), slices.end());
        if (!slices.empty()) {
            return slices.front();
        }
    }

    return {};
}

int64_t UnspentSelector::calculateFee(size_t inputs, size_t outputs) {
    const auto txsize = ((148 * inputs) + (34 * outputs) + 10);
    return int64_t(txsize) * UnspentSelector::byteFee;
}
