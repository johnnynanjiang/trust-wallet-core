// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class BitcoinScript {

    public var size: Int {
        return TWBitcoinScriptSize(rawValue)
    }

    public var data: Data {
        var result = Data(repeating: 0, count: TWBitcoinScriptData(rawValue, nil))
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptData(rawValue, ptr)
        }
        return result
    }

    private let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(data: Data) {
        rawValue = TWBitcoinScriptCreate(data.twData)
    }

    deinit {
        TWBitcoinScriptDelete(rawValue)
    }

}
