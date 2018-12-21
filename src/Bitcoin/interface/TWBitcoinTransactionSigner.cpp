// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionSigner.h>

#include "../OutPoint.h"
#include "../SigningProvider.h"
#include "../Transaction.h"
#include "../TransactionSigner.h"
#include "../UnspentTransaction.h"
#include "../TWBinaryCoding.h"

#include <TrustWalletCore/TWBitcoinOutPoint.h>

using namespace TW::Bitcoin;

struct TWBitcoinTransactionSigner *_Nonnull TWBitcoinTransactionSignerCreate(struct TWBitcoinSigningProvider *_Nonnull provider, struct TWBitcoinTransaction *_Nonnull transaction, uint32_t hashType) {
    return new TWBitcoinTransactionSigner{ TransactionSigner(provider->impl, transaction->impl, hashType) };
}

void TWBitcoinTransactionSignerDelete(struct TWBitcoinTransactionSigner *_Nonnull signer) {
    delete signer;
}

void TWBitcoinTransactionSignerAddUnspent(struct TWBitcoinTransactionSigner *_Nonnull signer, struct TWBitcoinOutPoint outPoint, struct TWBitcoinScript *_Nonnull script, uint64_t amount) {
    auto utxo = UnspentTransaction(reinterpret_cast<OutPoint&>(outPoint), script->impl, amount);
    signer->impl.utxos.push_back(std::move(utxo));
}

struct TWBitcoinTransaction *_Nullable TWBitcoinTransactionSignerSign(struct TWBitcoinTransactionSigner *_Nonnull signer) {
    auto tx = signer->impl.sign();
    if (!tx) {
        return nullptr;
    }
    return new TWBitcoinTransaction{ *tx };
}
