// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Amount.h"
#include "Script.h"
#include "Transaction.h"
#include "TransactionBuilder.h"
#include "TransactionInput.h"
#include "../Hash.h"
#include "../PrivateKey.h"
#include "../Result.h"
#include "../TrustWalletCore.pb.h"

#include <TrustWalletCore/TWBitcoinOpCodes.h>

#include <memory>
#include <string>
#include <vector>

namespace TW {
namespace Bitcoin {

/// Helper class that performs Bitcoin transaction signing.
template<typename Transaction>
class TransactionSigner {
private:
    /// Private key and redeem script provider for signing.
    TW::proto::BitcoinSigningInput input;

public:
    /// Transaction to sign.
    Transaction transaction;

    /// Selected coins.
    std::vector<TW::proto::BitcoinUnspentTransaction> utxos;

private:
    /// List of signed inputs.
    std::vector<TransactionInput> signedInputs;

public:
    /// Initializes a transaction signer with signing input.
    TransactionSigner(TW::proto::BitcoinSigningInput&& input) : input(input), transaction(), utxos() {
        std::tie(transaction, utxos) = TransactionBuilder::build<Transaction>(input);
    }

    /// Initializes a transaction signer with signing input, a transaction, and a hash type.
    TransactionSigner(TW::proto::BitcoinSigningInput&& input, Transaction transaction, std::vector<TW::proto::BitcoinUnspentTransaction> utxos)
        : input(input), transaction(transaction), utxos(utxos) {}

    /// Signs the transaction.
    ///
    /// \returns the signed transaction or an error.
    Result<Transaction> sign();

private:

    Result<void> sign(Script script, size_t index, const TW::proto::BitcoinUnspentTransaction& utxo);
    Result<std::vector<Data>> signStep(Script script, size_t index, const TW::proto::BitcoinUnspentTransaction& utxo, uint32_t version);
    Data createSignature(const Transaction& transaction, const Script& script, const Data& key, size_t index, Amount amount, uint32_t version);
    Data pushAll(const std::vector<Data>& results);

    /// Returns the private key for the given public key hash.
    Data keyForPublicKeyHash(const Data& hash) const;

    /// Returns the redeem script for the given script hash.
    Data scriptForScriptHash(const Data& hash) const;

    /// Encodes a small integer
    static uint8_t encodeNumber(int n) {
        assert(n >= 0 && n <= 16);
        if (n == 0) {
            return OP_0;
        }
        return OP_1 + uint8_t(n - 1);
    }
};

}} // namespace

/// Wrapper for C interface.
struct TWBitcoinTransactionSigner {
    TW::Bitcoin::TransactionSigner<TW::Bitcoin::Transaction> impl;
};
