// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include <TrustWalletCore/TWBitcoinScript.h>

TEST(BitcoinScript, ScriptHash) {
    auto pkData = DATA("cf5007e19af3641199f21f3fa54dff2fa2627471");
    auto script = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToPublicKeyHash(pkData.get()));

    auto size = TWBitcoinScriptSize(script.get());
    auto data = WRAPD(TWBitcoinScriptData(script.get()));

    auto scriptHex = WRAPS(TWStringCreateWithHexData(data.get()));
    ASSERT_STREQ(TWStringUTF8Bytes(scriptHex.get()), "76a914cf5007e19af3641199f21f3fa54dff2fa262747188ac");

    auto scriptHash = WRAPD(TWBitcoinScriptScriptHash(script.get()));

    auto hexData = WRAPS(TWStringCreateWithHexData(scriptHash.get()));
    ASSERT_STREQ(TWStringUTF8Bytes(hexData.get()), "c470d22e69a2a967f2cec0cd5a5aebb955cdd395");
}

TEST(BitcoinScript, RedeemScript) {
    auto pkData = DATA("cf5007e19af3641199f21f3fa54dff2fa2627471");
    auto embeddedScript = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToPublicKeyHash(pkData.get()));

    auto scriptHash = WRAPD(TWBitcoinScriptScriptHash(embeddedScript.get()));

    auto scriptPub1 = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToScriptHash(scriptHash.get()));

    auto size = TWBitcoinScriptSize(scriptPub1.get());
    auto data = WRAPD(TWBitcoinScriptData(scriptPub1.get()));

    auto hexData = WRAPS(TWStringCreateWithHexData(data.get()));
    ASSERT_STREQ(TWStringUTF8Bytes(hexData.get()), "a914c470d22e69a2a967f2cec0cd5a5aebb955cdd39587");
}
