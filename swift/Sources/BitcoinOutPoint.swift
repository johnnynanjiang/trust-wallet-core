// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public struct BitcoinOutPoint {

    public static func == (lhs: BitcoinOutPoint, rhs: BitcoinOutPoint) -> Bool {
        return TWBitcoinOutPointEqual(lhs.rawValue, rhs.rawValue)
    }

    var rawValue: TWBitcoinOutPoint

    public var hash: Data {
        return TWDataNSData(TWBitcoinOutPointHash(rawValue))
    }

    public var index: UInt32 {
        return TWBitcoinOutPointIndex(rawValue)
    }

    init(rawValue: TWBitcoinOutPoint) {
        self.rawValue = rawValue
    }

    public init(hash: Data, index: UInt32) {
        let hashData = TWDataCreateWithNSData(hash);
        defer {
            TWDataDelete(hashData);
        }
        rawValue = TWBitcoinOutPoint()
        TWBitcoinOutPointInitWithHash(&rawValue, hashData, index)
    }


    public func encode() -> Data {
        return TWDataNSData(TWBitcoinOutPointEncode(rawValue))
    }

}
