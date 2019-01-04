// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public final class BitcoinTransactionOutput {

    public static func == (lhs: BitcoinTransactionOutput, rhs: BitcoinTransactionOutput) -> Bool {
        return TWBitcoinTransactionOutputEqual(lhs.rawValue, rhs.rawValue)
    }

    public var amount: UInt64 {
        return TWBitcoinTransactionOutputAmount(rawValue)
    }

    public var script: BitcoinScript {
        return BitcoinScript(rawValue: TWBitcoinTransactionOutputScript(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(value: UInt64, script: BitcoinScript?) {
        rawValue = TWBitcoinTransactionOutputCreate(value, script?.rawValue)
    }

    deinit {
        TWBitcoinTransactionOutputDelete(rawValue)
    }

    public func encode() -> Data {
        return TWDataNSData(TWBitcoinTransactionOutputEncode(rawValue))
    }

}
