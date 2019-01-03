// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include <TrustWalletCore/TWBech32Address.h>
#include <TrustWalletCore/TWBitcoinScript.h>
#include <TrustWalletCore/TWBitcoinSigningProvider.h>
#include <TrustWalletCore/TWBitcoinTransaction.h>
#include <TrustWalletCore/TWBitcoinTransactionSigner.h>
#include <TrustWalletCore/TWBitcoinUnspentTransaction.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWPrivateKey.h>

TEST(BitcoinSigning, EncodeP2WPKH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0x11));

    auto hash0 = DATA("fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f");
    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, hash0.get(), 0);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), 0xffffffee);

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

TEST(BitcoinSigning, SignP2WPKH) {
    // Build transaction
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0x11));

    auto hash0 = DATA("fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f");
    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, hash0.get(), 0);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), 0xffffffee);

    auto hash1 = DATA("ef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a");
    auto outpoint1 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint1, hash1.get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint1, emptyScript.get(), UINT32_MAX);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 112'340'000, outScript0.get());

    auto outScript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 223'450'000, outScript1.get());

    // Setup signing provider
    auto provider = WRAP(TWBitcoinSigningProvider, TWBitcoinSigningProviderCreate());
    auto utxoKey0 = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("bbc27228ddcb9209d7fd6f36b02f7dfa6252af40bb2f1cbc7a557da8027ff866").get()));
    TWBitcoinSigningProviderAddKey(provider.get(), utxoKey0.get());

    auto utxoKey1 = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("619c335025c7f4012e556c2a58b2506e30b8511b53ade95ea316fd8c3286feb9").get()));
    TWBitcoinSigningProviderAddKey(provider.get(), utxoKey1.get());

    auto scriptPub1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("00141d0f172a0ecb48aee1be1f2687d2963ae33f71a1").get()));
    auto scriptHash = WRAPD(TWBitcoinScriptMatchPayToWitnessPublicKeyHash(scriptPub1.get()));
    assertHexEqual(scriptHash, "1d0f172a0ecb48aee1be1f2687d2963ae33f71a1");

    auto redeemScript = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToPublicKeyHash(scriptHash.get()));
    TWBitcoinSigningProviderAddRedeemScript(provider.get(), scriptHash.get(), redeemScript.get());

    auto signer = WRAP(TWBitcoinTransactionSigner, TWBitcoinTransactionSignerCreate(provider.get(), unsignedTx.get(), TWSignatureHashTypeAll));
    auto utxo0Script = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("2103c9f4836b9a4f77fc0d81f7bcb01b7f1b35916864b9476c241ce9fc198bd25432ac").get()));
    TWBitcoinTransactionSignerAddUnspent(signer.get(), outpoint0, utxo0Script.get(), 625'000'000);
    auto utxo1Script = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("00141d0f172a0ecb48aee1be1f2687d2963ae33f71a1").get()));
    TWBitcoinTransactionSignerAddUnspent(signer.get(), outpoint1, utxo1Script.get(), 600'000'000);
    
    // Sign
    auto signedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionSignerSign(signer.get()));

    auto txid = WRAPS(TWBitcoinTransactionIdentifier(signedTx.get()));
    assertStringsEqual(txid, "e8151a2af31c368a35053ddd4bdb285a8595c769a3ad83e0fa02314a602d4609");

    auto witid = WRAPS(TWBitcoinTransactionWitnessIdentifier(signedTx.get()));
    assertStringsEqual(witid, "c36c38370907df2324d9ce9d149d191192f338b37665a82e78e76a12c909b762");

    auto serialized = WRAPD(TWBitcoinTransactionEncode(signedTx.get(), true));
    assertHexEqual(serialized, "01000000000102fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f00000000494830450221008b9d1dc26ba6a9cb62127b02742fa9d754cd3bebf337f7a55d114c8e5cdd30be022040529b194ba3f9281a99f2b1c0a19c0489bc22ede944ccf4ecbab4cc618ef3ed01eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac000247304402203609e17b84f6a7d30c80bfa610b5b4542f32a8a0d5447a12fb1366d7f01cc44a0220573a954c4518331561406f90300e8f3358f51928d43c212a8caed02de67eebee0121025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee635711000000");
}

TEST(BitcoinSigning, EncodeP2WSH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0));

    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, DATA("0001000000000000000000000000000000000000000000000000000000000000").get(), 0);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), UINT32_MAX);

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

TEST(BitcoinSigning, SignP2WSH) {
    // Build transaction
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0));

    auto hash0 = DATA("0001000000000000000000000000000000000000000000000000000000000000");
    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, hash0.get(), 0);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), UINT32_MAX);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9144c9c3dfac4207d5d8cb89df5722cb3d712385e3f88ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 1000, outScript0.get());

    // Setup signing provider
    auto provider = WRAP(TWBitcoinSigningProvider, TWBitcoinSigningProviderCreate());
    auto utxoKey0 = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("ed00a0841cd53aedf89b0c616742d1d2a930f8ae2b0fb514765a17bb62c7521a").get()));
    TWBitcoinSigningProviderAddKey(provider.get(), utxoKey0.get());

    auto redeemScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("2103596d3451025c19dbbdeb932d6bf8bfb4ad499b95b6f88db8899efac102e5fc71ac").get()));
    auto scriptHash = DATA("593128f9f90e38b706c18623151e37d2da05c229");
    TWBitcoinSigningProviderAddRedeemScript(provider.get(), scriptHash.get(), redeemScript.get());

    auto signer = WRAP(TWBitcoinTransactionSigner, TWBitcoinTransactionSignerCreate(provider.get(), unsignedTx.get(), TWSignatureHashTypeAll));

    auto p2wsh = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToWitnessScriptHash(DATA("ff25429251b5a84f452230a3c75fd886b7fc5a7865ce4a7bb7a9d7c5be6da3db").get()));
    TWBitcoinTransactionSignerAddUnspent(signer.get(), outpoint0, p2wsh.get(), 1000);
    
    // Sign
    auto signedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionSignerSign(signer.get()));

    auto txid = WRAPS(TWBitcoinTransactionIdentifier(signedTx.get()));
    assertStringsEqual(txid, "b2ce556154e5ab22bec0a2f990b2b843f4f4085486c0d2cd82873685c0012004");

    auto witid = WRAPS(TWBitcoinTransactionWitnessIdentifier(signedTx.get()));
    assertStringsEqual(witid, "0df178d21afc9e8a46195c7c2e328aafd8544a1dbd67cf983214cad401966cf3");

    auto serialized = WRAPD(TWBitcoinTransactionEncode(signedTx.get(), true));
    assertHexEqual(serialized, "0100000000010100010000000000000000000000000000000000000000000000000000000000000000000000ffffffff01e8030000000000001976a9144c9c3dfac4207d5d8cb89df5722cb3d712385e3f88ac02483045022100aa5d8aa40a90f23ce2c3d11bc845ca4a12acd99cbea37de6b9f6d86edebba8cb022022dedc2aa0a255f74d04c0b76ece2d7c691f9dd11a64a8ac49f62a99c3a05f9d01232103596d3451025c19dbbdeb932d6bf8bfb4ad499b95b6f88db8899efac102e5fc71ac00000000");
}

TEST(BitcoinSigning, EncodeP2SH_P2WPKH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0x492));

    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, DATA("db6b1b20aa0fd7b23880be2ecbd4a98130974cf4748fb66092ac4d3ceb1a5477").get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), 0xfffffffe);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914a457b684d7f0d539a46a45bbc043f35b59d0d96388ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 199'996'600, outScript0.get());

    auto outScript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914fd270b1ee6abcaea97fea7ad0402e8bd8ad6d77c88ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 800'000'000, outScript1.get());

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

TEST(BitcoinSigning, SignP2SH_P2WPKH) {
    // Build transaction
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0x492));

    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, DATA("db6b1b20aa0fd7b23880be2ecbd4a98130974cf4748fb66092ac4d3ceb1a5477").get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), 0xfffffffe);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914a457b684d7f0d539a46a45bbc043f35b59d0d96388ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 199'996'600, outScript0.get());

    auto outScript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914fd270b1ee6abcaea97fea7ad0402e8bd8ad6d77c88ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 800'000'000, outScript1.get());

    // Setup signing provider
    auto provider = WRAP(TWBitcoinSigningProvider, TWBitcoinSigningProviderCreate());

    auto utxoKey0 = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("eb696a065ef48a2192da5b28b694f87544b30fae8327c4510137a922f32c6dcf").get()));
    auto pubKey0 = TWPrivateKeyGetPublicKey(utxoKey0.get(), true);
    auto pubKey0Data = WRAPD(TWPublicKeyData(pubKey0));
    auto utxoPubkeyHash = WRAPD(TWHashSHA256RIPEMD(pubKey0Data.get()));
    assertHexEqual(utxoPubkeyHash, "79091972186c449eb1ded22b78e40d009bdf0089");
    TWBitcoinSigningProviderAddKey(provider.get(), utxoKey0.get());

    auto redeemScript = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToWitnessPubkeyHash(utxoPubkeyHash.get()));
    auto scriptHash = WRAPD(TWHashSHA256RIPEMD(TWBitcoinScriptData(redeemScript.get())));
    assertHexEqual(scriptHash, "4733f37cf4db86fbc2efed2500b4f4e49f312023");
    TWBitcoinSigningProviderAddRedeemScript(provider.get(), scriptHash.get(), redeemScript.get());

    auto signer = WRAP(TWBitcoinTransactionSigner, TWBitcoinTransactionSignerCreate(provider.get(), unsignedTx.get(), TWSignatureHashTypeAll));
    auto utxo0Script = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("a9144733f37cf4db86fbc2efed2500b4f4e49f31202387").get()));
    TWBitcoinTransactionSignerAddUnspent(signer.get(), outpoint0, utxo0Script.get(), 1000'000'000);
    
    // Sign
    auto signedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionSignerSign(signer.get()));

    auto txid = WRAPS(TWBitcoinTransactionIdentifier(signedTx.get()));
    assertStringsEqual(txid, "ef48d9d0f595052e0f8cdcf825f7a5e50b6a388a81f206f3f4846e5ecd7a0c23");

    auto witid = WRAPS(TWBitcoinTransactionWitnessIdentifier(signedTx.get()));
    assertStringsEqual(witid, "680f483b2bf6c5dcbf111e69e885ba248a41a5e92070cfb0afec3cfc49a9fabb");

    auto serialized = WRAPD(TWBitcoinTransactionEncode(signedTx.get(), true));
    assertHexEqual(serialized, "01000000000101db6b1b20aa0fd7b23880be2ecbd4a98130974cf4748fb66092ac4d3ceb1a5477010000001716001479091972186c449eb1ded22b78e40d009bdf0089feffffff02b8b4eb0b000000001976a914a457b684d7f0d539a46a45bbc043f35b59d0d96388ac0008af2f000000001976a914fd270b1ee6abcaea97fea7ad0402e8bd8ad6d77c88ac02473044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb012103ad1d8e89212f0b92c74d23bb710c00662ad1470198ac48c43f7d6f93a2a2687392040000");
}

TEST(BitcoinSigning, EncodeP2SH_P2WSH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0));

    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, DATA("36641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e").get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), 0xffffffff);

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

TEST(BitcoinSigning, SignP2SH_P2WSH) {
    auto emptyScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreate());
    auto unsignedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionCreate(1, 0));

    auto outpoint0 = TWBitcoinOutPoint{};
    TWBitcoinOutPointInitWithHash(&outpoint0, DATA("36641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e").get(), 1);
    TWBitcoinTransactionAddInput(unsignedTx.get(), outpoint0, emptyScript.get(), 0xffffffff);

    auto outScript0 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 0x0000000035a4e900, outScript0.get());

    auto outScript1 = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("76a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac").get()));
    TWBitcoinTransactionAddOutput(unsignedTx.get(), 0x00000000052f83c0, outScript1.get());

    // Setup signing provider
    auto provider = WRAP(TWBitcoinSigningProvider, TWBitcoinSigningProviderCreate());

    TWBitcoinSigningProviderAddKey(provider.get(), WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("730fff80e1413068a05b57d6a58261f07551163369787f349438ea38ca80fac6").get())).get());
    TWBitcoinSigningProviderAddKey(provider.get(), WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("730fff80e1413068a05b57d6a58261f07551163369787f349438ea38ca80fac6").get())).get());
    TWBitcoinSigningProviderAddKey(provider.get(), WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("11fa3d25a17cbc22b29c44a484ba552b5a53149d106d3d853e22fdd05a2d8bb3").get())).get());
    TWBitcoinSigningProviderAddKey(provider.get(), WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("77bf4141a87d55bdd7f3cd0bdccf6e9e642935fec45f2f30047be7b799120661").get())).get());
    TWBitcoinSigningProviderAddKey(provider.get(), WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("14af36970f5025ea3e8b5542c0f8ebe7763e674838d08808896b63c3351ffe49").get())).get());
    TWBitcoinSigningProviderAddKey(provider.get(), WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("fe9a95c19eef81dde2b95c1284ef39be497d128e2aa46916fb02d552485e0323").get())).get());
    TWBitcoinSigningProviderAddKey(provider.get(), WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(DATA("428a7aee9f0c2af0cd19af3cf1c78149951ea528726989b2e83e4778d2c3f890").get())).get());
    
    auto redeemScript = WRAP(TWBitcoinScript, TWBitcoinScriptBuildPayToWitnessScriptHash(DATA("a16b5755f7f6f96dbd65f5f0d6ab9418b89af4b1f14a1bb8a09062c35f0dcb54").get()));
    auto scriptHash = WRAPD(TWHashSHA256RIPEMD(TWBitcoinScriptData(redeemScript.get())));
    TWBitcoinSigningProviderAddRedeemScript(provider.get(), scriptHash.get(), redeemScript.get());

    auto witnessScript = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA(""
        "56"
            "210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba3"
            "2103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b"
            "21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a"
            "21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f4"
            "2103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac16"
            "2102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b"
        "56ae"
    ).get()));
    auto witnessScriptHash = WRAPD(TWHashSHA256RIPEMD(TWBitcoinScriptData(witnessScript.get())));
    TWBitcoinSigningProviderAddRedeemScript(provider.get(), witnessScriptHash.get(), witnessScript.get());
    
    auto signer = WRAP(TWBitcoinTransactionSigner, TWBitcoinTransactionSignerCreate(provider.get(), unsignedTx.get(), TWSignatureHashTypeAll));
    auto utxo0Script = WRAP(TWBitcoinScript, TWBitcoinScriptCreateWithData(DATA("a9149993a429037b5d912407a71c252019287b8d27a587").get()));
    TWBitcoinTransactionSignerAddUnspent(signer.get(), outpoint0, utxo0Script.get(), 987654321);
    
    // Sign
    auto signedTx = WRAP(TWBitcoinTransaction, TWBitcoinTransactionSignerSign(signer.get()));
    
    auto expected = ""
            "010000000001"
            "01"
              "36641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e" "01000000" "23220020a16b5755f7f6f96dbd65f5f0d6ab9418b89af4b1f14a1bb8a09062c35f0dcb54" "ffffffff"
            "02"
              "00e9a43500000000" "1976a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688ac"
              "c0832f0500000000" "1976a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac"
            "08"
              "00"
              "47304402206ac44d672dac41f9b00e28f4df20c52eeb087207e8d758d76d92c6fab3b73e2b0220367750dbbe19290069cba53d096f44530e4f98acaa594810388cf7409a1870ce01"
              "483045022100e9f86758f957f93c091b0cda0e34ad834a95af95e6ad5a0353c70a4e366095c602203a271f79ca9ce19d24d03f69dc182f5cbc975351377fd06fd338c8d0357c9cb201"
              "483045022100f549882966c090b7f03797b0554bcc909e96a72721bb46a41a65927920e0705502203db0ef7478ed39fdce848bc7f780560512e09d70ac18ae63b310882813cb4f1f01"
              "47304402207cd6069c036ec1381aea80626d46654d2d8d79e741843419f40db52b8e3f8f2602204e8e2e3b0a813a88129cac8c0c04b243a93059e0f112ace79af07f59ac890b7c01"
              "4730440220073b838d03f0327668718d5d9199f6f0dbe96859a050040e6aa0083975a1b00302201ebe35c4bee7d4faf80131690b542e6b6403123cf5786422a1d656f8f47c615b01"
              "473044022067cf6aa9f9882343be509eac35ab0b78b27416a2be95ff41f23f3d7384c2be6502201a586bfba827e76e2d941b4118ed147e338fa407a26e2476c9daf4f875b53fce01"
              "cf56"
                "210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba3"
                "2103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b"
                "21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a"
                "21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f4"
                "2103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac16"
                "2102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b"
              "56ae"
            "00000000";
    
    auto serialized = WRAPD(TWBitcoinTransactionEncode(signedTx.get(), true));
    assertHexEqual(serialized, expected);
}
