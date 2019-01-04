// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWBitcoinSigningProvider.h>

#include "../Script.h"
#include "../SigningProvider.h"
#include "../../PrivateKey.h"


struct TWBitcoinSigningProvider *_Nonnull TWBitcoinSigningProviderCreate() {
    return new TWBitcoinSigningProvider{};
}

void TWBitcoinSigningProviderDelete(struct TWBitcoinSigningProvider *_Nonnull provider) {
    delete provider;
}

void TWBitcoinSigningProviderAddKey(struct TWBitcoinSigningProvider *_Nonnull provider, struct TWPrivateKey *_Nonnull key) {
    provider->impl.privateKeys.emplace_back(key->impl.bytes);
}

void TWBitcoinSigningProviderAddRedeemScript(struct TWBitcoinSigningProvider *_Nonnull provider, TWData *_Nonnull hash, struct TWBitcoinScript *_Nonnull script) {
    auto array = std::array<uint8_t, 20>();
    std::copy(TWDataBytes(hash), TWDataBytes(hash) + 20, std::begin(array));
    auto scriptData = std::vector<uint8_t>();
    std::copy(std::begin(script->impl.bytes), std::end(script->impl.bytes), std::back_inserter(scriptData));
    provider->impl.scripts[std::move(array)] = std::move(scriptData);
}
