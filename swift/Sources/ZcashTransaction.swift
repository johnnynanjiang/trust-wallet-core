// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

public final class ZcashTransaction {

    public var lockTime: UInt32 {
        return TWZcashTransactionLockTime(rawValue)
    }

    public var inputCount: Int {
        return TWZcashTransactionInputCount(rawValue)
    }

    public var outputCount: Int {
        return TWZcashTransactionOutputCount(rawValue)
    }

    public var hash: Data {
        return TWDataNSData(TWZcashTransactionHash(rawValue))
    }

    public var identifier: String {
        return TWStringNSString(TWZcashTransactionIdentifier(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init() {
        rawValue = TWZcashTransactionCreate()
    }

    deinit {
        TWZcashTransactionDelete(rawValue)
    }

    public func encode() -> Data {
        return TWDataNSData(TWZcashTransactionEncode(rawValue))
    }

}
