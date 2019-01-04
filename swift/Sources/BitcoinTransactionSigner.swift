// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public final class BitcoinTransactionSigner {

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(provider: BitcoinSigningProvider, transaction: BitcoinTransaction, hashType: UInt32) {
        rawValue = TWBitcoinTransactionSignerCreate(provider.rawValue, transaction.rawValue, hashType)
    }

    deinit {
        TWBitcoinTransactionSignerDelete(rawValue)
    }

    public func addUnspent(outPoint: BitcoinOutPoint, script: BitcoinScript, amount: UInt64) -> Void {
        return TWBitcoinTransactionSignerAddUnspent(rawValue, outPoint.rawValue, script.rawValue, amount)
    }

    public func sign() -> BitcoinTransaction? {
        guard let value = TWBitcoinTransactionSignerSign(rawValue) else {
            return nil
        }
        return BitcoinTransaction(rawValue: value)
    }

}
