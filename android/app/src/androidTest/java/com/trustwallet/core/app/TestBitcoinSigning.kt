package com.trustwallet.core.app

import com.google.protobuf.ByteString
import com.trustwallet.core.app.utils.Numeric
import com.trustwallet.core.app.utils.toHex
import com.trustwallet.core.app.utils.toHexBytes
import com.wallet.crypto.trustapp.jni.BitcoinTransactionSigner
import com.wallet.crypto.trustapp.proto.TrustWalletCore
import org.junit.Assert.assertEquals
import org.junit.Test

class TestBitcoinSigning {

    init {
        System.loadLibrary("TrustWalletCore")
    }

    @Test
    fun testSignP2WPKH() {
        val signerBuilder = TrustWalletCore.BitcoinSigningInput.newBuilder()
            .setAmount(335_790_000)
            .setHashType(0x01)
            .setToAddress("1Bp9U1ogV3A14FMvKbRJms7ctyso4Z4Tcx")
            .setChangeAddress("1FQc5LdgGHMHEN9nwkjmz6tWkxhPpxBvBU")
            .setByteFee(1)

        // Setting Private Keys

        val utxoKey0 =
            (Numeric.hexStringToByteArray("bbc27228ddcb9209d7fd6f36b02f7dfa6252af40bb2f1cbc7a557da8027ff866"))
        signerBuilder.addPrivateKey(ByteString.copyFrom(utxoKey0))
        val utxoKey1 =
            (Numeric.hexStringToByteArray("619c335025c7f4012e556c2a58b2506e30b8511b53ade95ea316fd8c3286feb9"))
        signerBuilder.addPrivateKey(ByteString.copyFrom(utxoKey1))


        // Redeem scripts

        val outpoint0 = TrustWalletCore.BitcoinOutPoint.newBuilder()
            .setHash(ByteString.copyFrom(Numeric.hexStringToByteArray("fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f")))
            .setIndex(0)
            .setSequence(Long.MAX_VALUE.toInt())
            .build()

        val utxo0 = TrustWalletCore.BitcoinUnspentTransaction.newBuilder()
            .setAmount(625_000_000)
            .setOutPoint(outpoint0)
            .setScript(ByteString.copyFrom("2103c9f4836b9a4f77fc0d81f7bcb01b7f1b35916864b9476c241ce9fc198bd25432ac".toHexBytes()))
            .build()

        signerBuilder.addUtxo(utxo0)


        val outpoint1 = TrustWalletCore.BitcoinOutPoint.newBuilder()
            .setHash(ByteString.copyFrom("ef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a".toHexBytes()))
            .setIndex(1)
            .setSequence(Long.MAX_VALUE.toInt())
            .build()

        val utxo1 = TrustWalletCore.BitcoinUnspentTransaction.newBuilder()
            .setAmount(600_000_000)
            .setOutPoint(outpoint1)
            .setScript(ByteString.copyFrom(Numeric.hexStringToByteArray("00141d0f172a0ecb48aee1be1f2687d2963ae33f71a1")))
            .build()

        signerBuilder.addUtxo(utxo1)

        val signer = BitcoinTransactionSigner(signerBuilder.build())
        val signedTransaction = signer.sign()

        val signatureHex = signedTransaction.encode(true).toHex()

        assertEquals(signatureHex, "0x01000000000101fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000049483045022100b6006eb0fe2da8cbbd204f702b1ffdb1e29c49f3de51c4983d420bf9f9125635022032a195b153ccb2c4978333b4aad72aaa7e6a0b334a14621d5d817a42489cb0d301ffffffff02b0bf0314000000001976a914769bdff96a02f9135a1d19b749db6a78fe07dc9088acaefd3c11000000001976a9149e089b6889e032d46e3b915a3392edfd616fb1c488ac0000000000")
        assertEquals(signedTransaction.identifier(), "03b30d55430f08365d19a62d3bd32e459ab50984fbcf22921ecc85f1e09dc6ed")
        assertEquals(signedTransaction.witnessIdentifier(), "20bc58d07d91a3bae9e6f4d617d8f6271723d1a7673e486cc0ecaf9e758e2c22")
    }


    @Test
    fun testSignP2PKH() {
        val signerBuilder = TrustWalletCore.BitcoinSigningInput.newBuilder()
            .setAmount(55_000)
            .setHashType(0x01)
            .setToAddress("1GDCMHsTLBkawQXP8dqcZtr8zGgb4XpCug")
            .setChangeAddress("1CSR6tXqngr1CfwVF23V4bQotttJmzXqpf")
            .setByteFee(10)

        // Setting Private Keys

        val utxoKey0 =
            (Numeric.hexStringToByteArray("bbc27228ddcb9209d7fd6f36b02f7dfa6252af40bb2f1cbc7a557da8027ff866"))
        signerBuilder.addPrivateKey(ByteString.copyFrom(utxoKey0))
        val utxoKey1 =
            (Numeric.hexStringToByteArray("619c335025c7f4012e556c2a58b2506e30b8511b53ade95ea316fd8c3286feb9"))
        signerBuilder.addPrivateKey(ByteString.copyFrom(utxoKey1))


        // Redeem scripts

        val outpoint0 = TrustWalletCore.BitcoinOutPoint.newBuilder()
            .setHash(ByteString.copyFrom(Numeric.hexStringToByteArray("fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f")))
            .setIndex(0)
            .setSequence(Long.MAX_VALUE.toInt())
            .build()

        val utxo0 = TrustWalletCore.BitcoinUnspentTransaction.newBuilder()
            .setAmount(30_000)
            .setOutPoint(outpoint0)
            .setScript(ByteString.copyFrom("2103c9f4836b9a4f77fc0d81f7bcb01b7f1b35916864b9476c241ce9fc198bd25432ac".toHexBytes()))
            .build()

        signerBuilder.addUtxo(utxo0)

        val outpoint1 = TrustWalletCore.BitcoinOutPoint.newBuilder()
            .setHash(ByteString.copyFrom("ef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a".toHexBytes()))
            .setIndex(1)
            .setSequence(Long.MAX_VALUE.toInt())
            .build()

        val utxo1 = TrustWalletCore.BitcoinUnspentTransaction.newBuilder()
            .setAmount(45_000)
            .setOutPoint(outpoint1)
            .setScript(ByteString.copyFrom(Numeric.hexStringToByteArray("00141d0f172a0ecb48aee1be1f2687d2963ae33f71a1")))
            .build()

        signerBuilder.addUtxo(utxo1)

        val signer = BitcoinTransactionSigner(signerBuilder.build())
        val signedTransaction = signer.sign()

        val signatureHex = signedTransaction.encode(false).toHex()

        assertEquals(signatureHex, "0x0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000049483045022100991ea84c8f22cbcbdee114a687b31bc80fca181161adc354e37b16b0f4664a6f022016e34b232524a1296a636026f8bb1f5f3635d88bf936532aae70a499c52f77d201ffffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02d8d60000000000001976a914a6d85a488bb777a540f24bf777d30d1486036f6188ac843f0000000000001976a9147d77e6cfb05a9cfc123824279f6caf8b66ac267688ac00000000")
        assertEquals(signedTransaction.identifier(), "51fcc1ac8de03b26c23e8a5e41402e15b8cb2cb9323a78bb05695cbdfa9ff8f5")
        assertEquals(signedTransaction.witnessIdentifier(), "a2a9c44aebe199b4313b2361666ba75737b0e80c04eaca1c9aaa270425554a2d")
    }
}