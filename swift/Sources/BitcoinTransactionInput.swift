// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public final class BitcoinTransactionInput {

    public var previousOutput: BitcoinOutPoint {
        return BitcoinOutPoint(rawValue: TWBitcoinTransactionInputPreviousOutput(rawValue))
    }

    public var script: BitcoinScript {
        return BitcoinScript(rawValue: TWBitcoinTransactionInputScript(rawValue))
    }

    public var sequence: UInt32 {
        return TWBitcoinTransactionInputSequence(rawValue)
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(previousOutput: BitcoinOutPoint, script: BitcoinScript?, sequence: UInt32) {
        rawValue = TWBitcoinTransactionInputCreate(previousOutput.rawValue, script?.rawValue, sequence)
    }

    deinit {
        TWBitcoinTransactionInputDelete(rawValue)
    }

    public func encode() -> Data {
        return TWDataNSData(TWBitcoinTransactionInputEncode(rawValue))
    }

}
