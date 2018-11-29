// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinScript.h>

#include <vector>

struct TWBitcoinScript {
    std::vector<uint8_t> bytes;
};

struct TWBitcoinScript *_Nonnull TWBitcoinScriptCreate(struct TWData data) {
    auto script = new TWBitcoinScript{};
    std::copy(data.bytes, data.bytes + data.len, std::begin(script->bytes));
    return script;
}

void TWBitcoinScriptDelete(struct TWBitcoinScript *_Nonnull script) {
    delete script;
}

size_t TWBitcoinScriptSize(struct TWBitcoinScript *_Nonnull script) {
    return script->bytes.size();
}

size_t TWBitcoinScriptData(struct TWBitcoinScript *_Nonnull script, uint8_t *_Nullable result) {
    if (result == nullptr)
        return script->bytes.size();
    std::copy(std::begin(script->bytes), std::end(script->bytes), result);
    return script->bytes.size();
}
