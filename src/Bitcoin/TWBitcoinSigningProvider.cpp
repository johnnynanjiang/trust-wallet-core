// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TWBitcoinSigningProvider_Internal.h"

#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWPrivateKey.h>

struct TWBitcoinSigningProvider *_Nonnull TWBitcoinSigningProviderCreate() {
    return new TWBitcoinSigningProvider{};
}

void TWBitcoinSigningProviderDelete(struct TWBitcoinSigningProvider *_Nonnull provider) {
    delete provider;
}

void TWBitcoinSigningProviderAddKey(struct TWBitcoinSigningProvider *_Nonnull provider, struct TWPrivateKey *_Nonnull key) {
    provider->privateKeys.emplace_back(key->bytes);
}

void TWBitcoinSigningProviderAddRedeemScript(struct TWBitcoinSigningProvider *_Nonnull provider, TWData *_Nonnull hash, struct TWBitcoinScript *_Nonnull script) {
    auto array = std::array<uint8_t, 20>();
    std::copy(TWDataBytes(hash), TWDataBytes(hash) + 20, std::begin(array));
    auto scriptData = std::vector<uint8_t>();
    std::copy(std::begin(script->bytes), std::end(script->bytes), std::back_inserter(scriptData));
    provider->scripts[std::move(array)] = std::move(scriptData);
}
