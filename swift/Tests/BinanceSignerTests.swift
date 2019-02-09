// Copyright © 2017-2019 Binance.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import TrustWalletCore
import XCTest

class BinanceSignerTests: XCTestCase {
    func testExample() {
        let privateKey = PrivateKey(data: Data(hexString: "0f9f4fb7eff191ea6da79c912387f929806922f07be7ec78f94da2002ecd89b3")!)!
        let publicKey = privateKey.getPublicKey(compressed: true)

        var signingInput = TW_Binance_Proto_SigningInput()
        signingInput.chainID = "Binance-Chain-Nile"
        signingInput.accountNumber = 0
        signingInput.sequence = 0
        signingInput.testNet = true

        signingInput.privateKey = privateKey.data

        var token = TW_Binance_Proto_SendOrder.Token()
        token.denom = "BNB"
        token.amount = 1

        var input = TW_Binance_Proto_SendOrder.Input()
        input.address = TendermintAddress(hrp: .binanceTest, publicKey: publicKey)!.keyHash
        input.coins = [token]

        var output = TW_Binance_Proto_SendOrder.Output()
        output.address = TendermintAddress(string: "tbnb1hlly02l6ahjsgxw9wlcswnlwdhg4xhx3f309d9")!.keyHash
        output.coins = [token]

        var sendOrder = TW_Binance_Proto_SendOrder()
        sendOrder.inputs = [input]
        sendOrder.outputs = [output]

        signingInput.sendOrder = sendOrder

        let data = BinanceSigner(input: signingInput).build()
        XCTAssertEqual(data?.hexString, "b801f0625dee0a462a2c87fa0a1f0a14fe1a20e0d58d65f6626178b5331ccd79965b8c5d12070a03424e421001121f0a14bffe47abfaede50419c577f1074fee6dd1535cd112070a03424e421001126a0a26eb5ae98721039f1215ae839d69cea9f160c808b2099b08b241bd6f7504fed1961a778085e12e12401d508c7767722fcda090ffe0b68b61834004681a8ce64aa65be5fedb8fa7f10c24b006b6f4f118f97ab100f00dd015a310fd360e96480dd32f0f8be4565f83d2")
    }
}
