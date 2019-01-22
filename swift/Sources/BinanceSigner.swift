// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public final class BinanceSigner {

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(input: TW_Proto_BinanceSigningInput) {
        let inputData = TWDataCreateWithNSData(try! input.serializedData())
        defer {
            TWDataDelete(inputData)
        }
        rawValue = TWBinanceSignerCreate(inputData)
    }

    deinit {
        TWBinanceSignerDelete(rawValue)
    }

    public func build() -> Data? {
        guard let result = TWBinanceSignerBuild(rawValue) else {
            return nil
        }
        return TWDataNSData(result)
    }

}
