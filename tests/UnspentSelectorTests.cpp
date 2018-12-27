// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "../src/Bitcoin/OutPoint.h"
#include "../src/Bitcoin/UnspentSelector.h"
#include "../src/Bitcoin/UnspentTransaction.h"

using namespace TW;
using namespace TW::Bitcoin;

auto transactionOutPoint = OutPoint(std::vector<uint8_t>(32), 0);

inline auto sum(const std::vector<UnspentTransaction>& utxos) {
    int64_t s = 0u;
    for (auto& utxo : utxos) {
        s += utxo.amount;
    }
    return s;
}

TEST(UnspentSelector, SelectUnpsents1) {
    auto utxos = std::vector<UnspentTransaction>();
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 4000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 2000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 6000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 1000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 11000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 12000));

    auto selected = UnspentSelector::select(utxos, 5000);
    
    ASSERT_EQ(sum(selected), 10000);
}

TEST(UnspentSelector, SelectUnpsents2) {
    auto utxos = std::vector<UnspentTransaction>();
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 4000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 2000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 6000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 1000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 50000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 120000));

    auto selected = UnspentSelector::select(utxos, 13000);

    ASSERT_EQ(sum(selected), 50000);
}

TEST(UnspentSelector, SelectUnpsents3) {
    auto utxos = std::vector<UnspentTransaction>();
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 4000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 2000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 5000));

    auto selected = UnspentSelector::select(utxos, 6000);

    ASSERT_EQ(sum(selected), 11000);
}

TEST(UnspentSelector, SelectUnpsents4) {
    auto utxos = std::vector<UnspentTransaction>();
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 40000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 30000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 30000));

    auto selected = UnspentSelector::select(utxos, 50000);

    ASSERT_EQ(sum(selected), 100000);
}

TEST(UnspentSelector, SelectUnpsents5) {
    auto utxos = std::vector<UnspentTransaction>();
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 1000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 2000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 3000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 4000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 5000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 6000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 7000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 8000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 9000));

    auto selected = UnspentSelector::select(utxos, 28000);

    ASSERT_EQ(sum(selected), 35000);
}

TEST(UnspentSelector, SelectUnpsentsInsufficient) {
    auto utxos = std::vector<UnspentTransaction>();
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 4000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 4000));
    utxos.push_back(UnspentTransaction(transactionOutPoint, Script(), 4000));

    auto selected = UnspentSelector::select(utxos, 15000);

    ASSERT_TRUE(selected.empty());
}
