#include "gtest/gtest.h"
#include <TrustWalletCore/TWBitcoinScript.h>

TEST(BitcoinScript, ScriptHash) {
    auto pkData = TWDataCreateWithHexString({ .bytes = "cf5007e19af3641199f21f3fa54dff2fa2627471", .len = 40 });
    auto script = TWBitcoinScriptBuildPayToPublicKeyHash(pkData);

    auto size = TWBitcoinScriptSize(script);
    auto data = new uint8_t[size];
    TWBitcoinScriptData(script, data);

    auto scriptHex = TWStringCreateWithHexData({ .bytes = data, .len = 25 });
    ASSERT_STREQ(scriptHex.bytes, "76a914cf5007e19af3641199f21f3fa54dff2fa262747188ac");

    uint8_t scriptHash[20];
    TWBitcoinScriptScriptHash(script, scriptHash);

    auto hexData = TWStringCreateWithHexData({ .bytes = scriptHash, .len = 20 });
    ASSERT_STREQ(hexData.bytes, "c470d22e69a2a967f2cec0cd5a5aebb955cdd395");

    TWBitcoinScriptDelete(script);
    TWDataDelete(pkData);
}

TEST(BitcoinScript, RedeemScript) {
    auto pkData = TWDataCreateWithHexString({ .bytes = "cf5007e19af3641199f21f3fa54dff2fa2627471", .len = 40 });
    auto embeddedScript = TWBitcoinScriptBuildPayToPublicKeyHash(pkData);

    uint8_t scriptHash[20];
    TWBitcoinScriptScriptHash(embeddedScript, scriptHash);

    auto scriptPub1 = TWBitcoinScriptBuildPayToScriptHash({ .bytes = scriptHash, .len = 20 });

    auto size = TWBitcoinScriptSize(scriptPub1);
    auto data = new uint8_t[size];
    TWBitcoinScriptData(scriptPub1, data);

    auto hexData = TWStringCreateWithHexData({ .bytes = data, .len = size });
    ASSERT_STREQ(hexData.bytes, "a914c470d22e69a2a967f2cec0cd5a5aebb955cdd39587");

    TWBitcoinScriptDelete(scriptPub1);
    TWBitcoinScriptDelete(embeddedScript);
    TWDataDelete(pkData);
}
