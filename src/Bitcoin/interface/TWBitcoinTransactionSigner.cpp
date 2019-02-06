// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinTransactionSigner.h>

#include "../../Data.h"
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

ProtoResult TWBitcoinTransactionSignerSign(struct TWBitcoinTransactionSigner *_Nonnull signer) {
    auto result = signer->impl.sign();
    auto protoResult = TW::proto::Result();
    if (!result) {
        protoResult.set_success(false);
        protoResult.set_error(result.error());
        auto serialized = protoResult.SerializeAsString();
        return TWDataCreateWithBytes(reinterpret_cast<const uint8_t *>(serialized.data()), serialized.size());
    }

    const auto& tx = result.payload();
    auto protoOutput = TW::proto::BitcoinSigningOutput();
    auto protoTx = protoOutput.mutable_transaction();
    protoTx->set_version(tx.version);
    protoTx->set_locktime(tx.lockTime);

    for (const auto& input : tx.inputs) {
        auto protoInput = protoTx->add_inputs();
        protoInput->mutable_previousoutput()->set_hash(input.previousOutput.hash, 32);
        protoInput->mutable_previousoutput()->set_index(input.previousOutput.index);
        protoInput->set_sequence(input.sequence);
        protoInput->set_script(input.script.bytes.data(), input.script.bytes.size());
    }

    for (const auto& output : tx.outputs) {
        auto protoOutput = protoTx->add_outputs();
        protoOutput->set_value(output.value);
        protoOutput->set_script(output.script.bytes.data(), output.script.bytes.size());
    }

    TW::Data encoded;
    auto hasWitness = std::any_of(tx.inputs.begin(), tx.inputs.end(), [](auto& input) { return !input.scriptWitness.empty(); });
    tx.encode(hasWitness, encoded);
    protoOutput.set_encoded(encoded.data(), encoded.size());

    protoResult.set_success(true);
    protoResult.add_objects()->PackFrom(protoOutput);

    auto serialized = protoResult.SerializeAsString();
    return TWDataCreateWithBytes(reinterpret_cast<const uint8_t *>(serialized.data()), serialized.size());
}
