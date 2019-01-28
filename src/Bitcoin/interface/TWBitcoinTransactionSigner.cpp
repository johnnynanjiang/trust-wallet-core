// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionSigner.h>

#include "../OutPoint.h"
#include "../Transaction.h"
#include "../TransactionSigner.h"
#include "../TWBinaryCoding.h"
#include "../../TrustWalletCore.pb.h"

using namespace TW::Bitcoin;

struct TWBitcoinTransactionSigner *_Nonnull TWBitcoinTransactionSignerCreate(ProtoBitcoinSigningInput data) {
    TW::proto::BitcoinSigningInput input;
    input.ParseFromArray(TWDataBytes(data), TWDataSize(data));
    return new TWBitcoinTransactionSigner{ TransactionSigner(std::move(input)) };
}

void TWBitcoinTransactionSignerDelete(struct TWBitcoinTransactionSigner *_Nonnull signer) {
    delete signer;
}

struct TWBitcoinTransaction *_Nullable TWBitcoinTransactionSignerSign(struct TWBitcoinTransactionSigner *_Nonnull signer) {
    auto tx = signer->impl.sign();
    if (!tx) {
        return nullptr;
    }
    return new TWBitcoinTransaction{ *tx };
}
