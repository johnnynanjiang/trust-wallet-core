// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include <TrustWalletCore/TWBech32Address.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinTransaction.h>
#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>

TEST(BitcoinSigning, EncodeP2WPKH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0x11));

    auto hash0 = DATA("fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f");
    auto unspentOutpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&unspentOutpoint0, hash0.get(), 0);
    TWBitcoinTransactionAddInput(unsignedTx.get(), unspentOutpoint0, emptyScript.get(), 0xffffffee);

    auto hash1 = DATA("ef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a");
    auto unspentOutpoint1 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&unspentOutpoint1, hash1.get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), unspentOutpoint1, emptyScript.get(), UINT32_MAX);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 112340000, outScript0.get());

    auto outScript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 223450000, outScript1.get());

    auto unsignedData = WRAPD(TWBitcoinTransactionEncode(unsignedTx.get(), false));
    assertHexEqual(unsignedData, ""
        "01000000"
        "02"
            "fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffff"
            "ef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff"
        "02"
            "202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac"
            "9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac"
        "11000000");
}

TEST(BitcoinSigning, EncodeP2WSH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0));

    auto unspentOutpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&unspentOutpoint0, DATA("0001000000000000000000000000000000000000000000000000000000000000").get(), 0);
    TWBitcoinTransactionAddInput(unsignedTx.get(), unspentOutpoint0, emptyScript.get(), UINT32_MAX);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9144c9c3dfac4207d5d8cb89df5722cb3d712385e3f88ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 1000, outScript0.get());

    auto unsignedData = WRAPD(TWBitcoinTransactionEncode(unsignedTx.get(), false));
    assertHexEqual(unsignedData, ""
        "01000000"
        "01"
            "00010000000000000000000000000000000000000000000000000000000000000000000000ffffffff"
        "01"
            "e8030000000000001976a9144c9c3dfac4207d5d8cb89df5722cb3d712385e3f88ac"
        "00000000");
}

TEST(BitcoinSigning, EncodeP2SH_P2WPKH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0x492));

    auto unspentOutpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&unspentOutpoint0, DATA("db6b1b20aa0fd7b23880be2ecbd4a98130974cf4748fb66092ac4d3ceb1a5477").get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), unspentOutpoint0, emptyScript.get(), 0xfffffffe);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914a457b684d7f0d539a46a45bbc043f35b59d0d96388ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 199996600, outScript0.get());

    auto outScript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914fd270b1ee6abcaea97fea7ad0402e8bd8ad6d77c88ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 800000000, outScript1.get());

    auto unsignedData = WRAPD(TWBitcoinTransactionEncode(unsignedTx.get(), false));
    assertHexEqual(unsignedData, ""
        "01000000"
        "01"
            "db6b1b20aa0fd7b23880be2ecbd4a98130974cf4748fb66092ac4d3ceb1a54770100000000feffffff"
        "02"
            "b8b4eb0b000000001976a914a457b684d7f0d539a46a45bbc043f35b59d0d96388ac"
            "0008af2f000000001976a914fd270b1ee6abcaea97fea7ad0402e8bd8ad6d77c88ac"
        "92040000");
}

TEST(BitcoinSigning, EncodeP2SH_P2WSH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0));

    auto unspentOutpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&unspentOutpoint0, DATA("36641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e").get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), unspentOutpoint0, emptyScript.get(), 0xffffffff);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 0x0000000035a4e900, outScript0.get());

    auto outScript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 0x00000000052f83c0, outScript1.get());

    auto unsignedData = WRAPD(TWBitcoinTransactionEncode(unsignedTx.get(), false));
    assertHexEqual(unsignedData, ""
        "01000000"
        "01"
            "36641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e0100000000ffffffff"
        "02"
            "00e9a435000000001976a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688ac"
            "c0832f05000000001976a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac"
        "00000000");
}
