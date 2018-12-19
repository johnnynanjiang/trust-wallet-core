// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include <TrustWalletCore/TWBitcoinAddress.h>
#include <TrustWalletCore/TWBitcoinCashAddress.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWHex.h>
#include <TrustWalletCore/TWPrivateKey.h>

TEST(BitcoinCash, LegacyToCashAddr) {
    auto privateKey = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("28071bf4e2b0340db41b807ed8a5514139e5d6427ff9d58dbd22b7ed187103a4").get()));
    auto publicKey = TWPrivateKeyGetPublicKey(privateKey.get(), true);
    auto address = TWBitcoinAddress();
    TWBitcoinAddressInitWithPublicKey(&address, publicKey, 0);
    auto addressString = WRAPS(TWBitcoinAddressDescription(address));
    assertStringsEqual(addressString, "1PeUvjuxyf31aJKX6kCXuaqxhmG78ZUdL1");

    auto cashAddress = TWBitcoinCashAddress();
    TWBitcoinCashAddressInitWithPublicKey(&cashAddress, publicKey);
    auto cashAddressString = WRAPS(TWBitcoinCashAddressDescription(cashAddress));
    assertStringsEqual(cashAddressString, "bitcoincash:qruxj7zq6yzpdx8dld0e9hfvt7u47zrw9gfr5hy0vh");
}

TEST(BitcoinCash, LockScript) {
    auto address = TWBitcoinCashAddress();
    TWBitcoinCashAddressInitWithString(&address, STRING("bitcoincash:qpk05r5kcd8uuzwqunn8rlx5xvuvzjqju5rch3tc0u").get());

    auto legacyAddress = TWBitcoinCashAddressLegacyAddress(address);
    auto legacyString = WRAPS(TWBitcoinAddressDescription(legacyAddress));
    assertStringsEqual(legacyString, "1AwDXywmyhASpCCFWkqhySgZf8KiswFoGh");

    auto keyHash = WRAPD(TWDataCreateWithBytes(legacyAddress.bytes + 1, 20));
    auto script = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToPublicKeyHash(keyHash.get()));
    auto scriptData = WRAPD(TWBitcoinScriptData(script.get()));
    assertHexEqual(scriptData, "76a9146cfa0e96c34fce09c0e4e671fcd43338c14812e588ac");
}
