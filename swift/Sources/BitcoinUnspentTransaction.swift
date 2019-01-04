// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public final class BitcoinUnspentTransaction {

    public var outPoint: BitcoinOutPoint {
        return BitcoinOutPoint(rawValue: TWBitcoinUnspentTransactionOutPoint(rawValue))
    }

    public var output: BitcoinTransactionOutput {
        return BitcoinTransactionOutput(rawValue: TWBitcoinUnspentTransactionOutput(rawValue))
    }

    public var amount: UInt64 {
        return TWBitcoinUnspentTransactionAmount(rawValue)
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(outpoint: BitcoinOutPoint, output: BitcoinTransactionOutput) {
        rawValue = TWBitcoinUnspentTransactionCreateWithOutput(outpoint.rawValue, output.rawValue)
    }

    public init(hash: Data, index: UInt32, script: BitcoinScript, amount: UInt64) {
        let hashData = TWDataCreateWithNSData(hash);
        defer {
            TWDataDelete(hashData);
        }
        rawValue = TWBitcoinUnspentTransactionCreate(hashData, index, script.rawValue, amount)
    }

    deinit {
        TWBitcoinUnspentTransactionDelete(rawValue)
    }

}
