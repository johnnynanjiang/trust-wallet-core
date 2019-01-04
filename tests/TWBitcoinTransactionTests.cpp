// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinTransaction.h>
#include <TrustWalletCore/TWBitcoinTransactionInput.h>
#include <TrustWalletCore/TWBitcoinTransactionOutput.h>

TEST(BitcoinTransaction, Encode) {
    auto transaction = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(2, 0));

    auto po0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&po0, DATA("5897de6bd6027a475eadd57019d4e6872c396d0716c4875a5f1a6fcfdf385c1f").get(), 0);
    auto script0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    TWBitcoinTransactionAddInput(transaction.get(), po0, script0.get(), 4294967295);

    auto po1 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&po1, DATA("bf829c6bcf84579331337659d31f89dfd138f7f7785802d5501c92333145ca7c").get(), 18);
    auto script1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    TWBitcoinTransactionAddInput(transaction.get(), po1, script1.get(), 4294967295);

    auto po2 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&po2, DATA("22a6f904655d53ae2ff70e701a0bbd90aa3975c0f40bfc6cc996a9049e31cdfc").get(), 1);
    auto script2 = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    TWBitcoinTransactionAddInput(transaction.get(), po2, script2.get(), 4294967295);

    auto oscript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9141fc11f39be1729bf973a7ab6a615ca4729d6457488ac").get()));
    TWBitcoinTransactionAddOutput(transaction.get(), 18000000, oscript0.get());

    auto oscript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("0x76a914f2d4db28cad6502226ee484ae24505c2885cb12d88ac").get()));
    TWBitcoinTransactionAddOutput(transaction.get(), 400000000, oscript1.get());
   
    auto data = WRAPD(TWBitcoinTransactionEncode(transaction.get(), false));
    auto hex = WRAPS(TWStringCreateWithHexData(data.get()));

    ASSERT_STREQ(TWStringUTF8Bytes(hex.get()), "02000000035897de6bd6027a475eadd57019d4e6872c396d0716c4875a5f1a6fcfdf385c1f0000000000ffffffffbf829c6bcf84579331337659d31f89dfd138f7f7785802d5501c92333145ca7c1200000000ffffffff22a6f904655d53ae2ff70e701a0bbd90aa3975c0f40bfc6cc996a9049e31cdfc0100000000ffffffff0280a81201000000001976a9141fc11f39be1729bf973a7ab6a615ca4729d6457488ac0084d717000000001976a914f2d4db28cad6502226ee484ae24505c2885cb12d88ac00000000");
}
