// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Transaction.h"
#include "UnspentSelector.h"
#include "../TrustWalletCore.pb.h"

namespace TW {
namespace Bitcoin {

struct TransactionBuilder {
    template<typename Transaction>
    static std::pair<Transaction, std::vector<TW::proto::BitcoinUnspentTransaction>> build(TW::proto::BitcoinSigningInput input) {
        auto utxos = UnspentSelector::select(input.utxo(), input.amount(), input.byte_fee());
        if (utxos.empty()) {
            return {};
        }

        const auto fee = UnspentSelector::calculateFee(utxos.size(), 2, input.byte_fee());
        Amount totalAmount = 0;
        for (auto& utxo : utxos) {
            totalAmount += utxo.amount();
        }
        assert(totalAmount >= input.amount() + fee);

        auto lockingScriptTo = Script::buildForAddress(input.to_address());
        if (lockingScriptTo.empty()) {
            return {};
        }

        Transaction tx;
        tx.outputs.push_back(TransactionOutput(input.amount(), lockingScriptTo));

        auto change = totalAmount - input.amount() - fee;
        if (change > 0) {
            auto lockingScriptChange = Script::buildForAddress(input.change_address());
            tx.outputs.push_back(TransactionOutput(change, lockingScriptChange));
        }

        const auto emptyScript = Script();
        for (auto& utxo : utxos) {
            tx.inputs.emplace_back(utxo.out_point(), emptyScript, utxo.out_point().sequence());
        }

        return std::make_pair(tx, utxos);
    }
};

}} //namespace
