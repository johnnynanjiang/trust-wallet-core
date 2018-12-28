// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Amount.h"
#include "Script.h"
#include "Transaction.h"
#include "TransactionInput.h"
#include "../Hash.h"
#include "../PrivateKey.h"
#include "../TrustWalletCore.pb.h"

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
    TW::proto::BitcoinSigningInput input;

    /// Transaction to sign.
    Transaction transaction;

    /// Selected coins.
    std::vector<TW::proto::BitcoinUnspentTransaction> utxos;

    /// Initializes a transaction signer with a signing provider, a transaction, and a hash type.
    TransactionSigner(TW::proto::BitcoinSigningInput&& input) : input(input) {
        transaction = build();
    }

    /// Signs the transaction.
    ///
    /// \returns the signed transaction or nullptr if there is an error.
    std::unique_ptr<Transaction> sign();

private:
    /// Builds a new transaction.
    Transaction build();

private:
    /// List of signed inputs.
    std::vector<TransactionInput> signedInputs;

    bool sign(Script script, size_t index, const TW::proto::BitcoinUnspentTransaction& utxo);
    std::vector<std::vector<uint8_t>> signStep(Script script, size_t index, const TW::proto::BitcoinUnspentTransaction& utxo, uint32_t version);
    std::vector<uint8_t> createSignature(const Transaction& transaction, const Script& script, const std::vector<uint8_t>& key, size_t index, Amount amount, uint32_t version);
    std::vector<uint8_t> pushAll(const std::vector<std::vector<uint8_t>>& results);

    /// Returns the private key for the given public key hash.
    std::vector<uint8_t> keyForPublicKeyHash(const std::vector<uint8_t>& hash) const;
    
    /// Returns the redeem script for the given script hash.
    std::vector<uint8_t> scriptForScriptHash(const std::vector<uint8_t>& hash) const;

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
