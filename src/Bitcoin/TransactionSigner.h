// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Script.h"
#include "SigningProvider.h"
#include "Transaction.h"
#include "TransactionInput.h"
#include "UnspentTransaction.h"

#include <TrustWalletCore/TWBitcoinOpCodes.h>

#include <memory>
#include <string>
#include <vector>

namespace TW {
namespace Bitcoin {

/// Helper class that performs Bitcoin transaction signing.
class TransactionSigner {
public:
    /// Private key and redeem script provider for signing.
    const SigningProvider& provider;

    /// Transaction to sign.
    const Transaction& transaction;

    /// Hash type to use when signing.
    const uint32_t hashType;

    /// List of available unspent transactions.
    std::vector<UnspentTransaction> utxos;

    /// Initializes a transaction signer with a signing provider, a transaction, and a hash type.
    TransactionSigner(const SigningProvider& provider, const Transaction& transaction, uint32_t hashType) : provider(provider), transaction(transaction), hashType(hashType) {}

    /// Signs the transaction.
    ///
    /// \returns the signed transaction or nullptr if there is an error.
    std::unique_ptr<Transaction> sign();

    /// Builds a new transaction.
    ///
    /// \param toAddress destination address.
    /// \param amount transaction amount.
    /// \param changeAddress change address.
    /// \param availableUtxos all available unspent transactions, only the appropriate ones will be used.
    /// \returns a new transaction ready to be signed, or an empty transaction if there are insufficient funds.
    static Transaction build(const std::string& toAddress, int64_t amount, const std::string& changeAddress, const std::vector<UnspentTransaction>& availableUtxos);

private:
    /// List of signed inputs.
    std::vector<TransactionInput> signedInputs;

    bool sign(Script script, size_t index, UnspentTransaction& utxo);
    std::vector<std::vector<uint8_t>> signStep(Script script, size_t index, const UnspentTransaction& utxo, uint32_t version);
    std::vector<uint8_t> createSignature(const Transaction& transaction, const Script& script, const std::array<uint8_t, PrivateKey::size>& key, size_t index, uint64_t amount, uint32_t version);
    std::vector<uint8_t> pushAll(const std::vector<std::vector<uint8_t>>& results);

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
    TW::Bitcoin::TransactionSigner impl;
};
