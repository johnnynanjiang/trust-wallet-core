// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include <TrustWalletCore/TWBech32Address.h>
#include <TrustWalletCore/TWBitcoinAddress.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWHex.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWSLIP.h>

TEST(BitcoinCash, LegacyAddress) {
    auto privateKey = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("a22ddec5c567b4488bb00f69b6146c50da2ee883e2c096db098726394d585730").get()));
    auto publicKey = TWPrivateKeyGetPublicKey(privateKey.get(), true);
    auto address = TWBitcoinAddress();
    TWBitcoinAddressInitWithPublicKey(&address, publicKey, P2PKHPrefixLitecoin);
    auto addressString = WRAPS(TWBitcoinAddressDescription(address));
    assertStringsEqual(addressString, "LV7LV7Z4bWDEjYkfx9dQo6k6RjGbXsg6hS");
}

TEST(BitcoinCash, Address) {
    auto privateKey = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("55f9cbb0376c422946fa28397c1219933ac60b312ede41bfacaf701ecd546625").get()));
    auto publicKey = TWPrivateKeyGetPublicKey(privateKey.get(), true);
    auto address = TWBech32Address();
    auto hrp = STRING("ltc");
    TWBech32AddressInitWithPublicKey(&address, publicKey, hrp.get());
    auto string = WRAPS(TWBech32AddressDescription(address));

    assertStringsEqual(string, "ltc1qytnqzjknvv03jwfgrsmzt0ycmwqgl0asjnaxwu");
}

TEST(Litecoin, BuildForAddressL) {
    auto script = WRAP(TWBitcoinScript, TWBitcoinScriptBuildForAddress(STRING("LgKiekick9Ka7gYoYzAWGrEq8rFBJzYiyf").get()));
    auto scriptData = WRAPD(TWBitcoinScriptData(script.get()));
    assertHexEqual(scriptData, "76a914e771c6695c5dd189ccc4ef00cd0f3db3096d79bd88ac");
}

TEST(Litecoin, BuildForAddressM) {
    auto script = WRAP(TWBitcoinScript, TWBitcoinScriptBuildForAddress(STRING("MHhghmmCTASDnuwpgsPUNJVPTFaj61GzaG").get()));
    auto scriptData = WRAPD(TWBitcoinScriptData(script.get()));
    assertHexEqual(scriptData, "a9146b85b3dac9340f36b9d32bbacf2ffcb0851ef17987");
}
