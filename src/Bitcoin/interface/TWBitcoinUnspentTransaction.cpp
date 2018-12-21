// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>

#include "../Script.h"
#include "../TransactionOutput.h"
#include "../UnspentTransaction.h"

using namespace TW::Bitcoin;

struct TWBitcoinUnspentTransaction *_Nonnull TWBitcoinUnspentTransactionCreateWithOutput(struct TWBitcoinOutPoint outPoint, struct TWBitcoinTransactionOutput *_Nonnull output) {
    auto utxo = UnspentTransaction(reinterpret_cast<OutPoint&>(outPoint), output->impl.script, output->impl.value);
    return new TWBitcoinUnspentTransaction{ utxo };
}

struct TWBitcoinUnspentTransaction *_Nonnull TWBitcoinUnspentTransactionCreate(TWData *_Nonnull hash, uint32_t index, struct TWBitcoinScript *_Nonnull script, uint64_t amount) {
    auto hashVector = reinterpret_cast<const std::vector<uint8_t>*>(hash);
    auto utxo = UnspentTransaction(OutPoint(*hashVector, index), script->impl, amount);
    return new TWBitcoinUnspentTransaction{ utxo };
}

void TWBitcoinUnspentTransactionDelete(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    delete utxo;
}

struct TWBitcoinOutPoint TWBitcoinUnspentTransactionOutPoint(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    return reinterpret_cast<const TWBitcoinOutPoint&>(utxo->impl.outPoint);
}

struct TWBitcoinTransactionOutput *_Nonnull TWBitcoinUnspentTransactionOutput(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    return new TWBitcoinTransactionOutput{ TransactionOutput(utxo->impl.amount, utxo->impl.script) };
}

uint64_t TWBitcoinUnspentTransactionAmount(struct TWBitcoinUnspentTransaction *_Nonnull utxo) {
    return utxo->impl.amount;
}
