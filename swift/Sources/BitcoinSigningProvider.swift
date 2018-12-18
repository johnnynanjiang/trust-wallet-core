// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class BitcoinSigningProvider {

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init() {
        rawValue = TWBitcoinSigningProviderCreate()
    }

    deinit {
        TWBitcoinSigningProviderDelete(rawValue)
    }

    public func addKey(key: PrivateKey) -> Void {
        return TWBitcoinSigningProviderAddKey(rawValue, key.rawValue)
    }

    public func addRedeemScript(hash: Data, script: BitcoinScript) -> Void {
        let hashData = TWDataCreateWithNSData(hash);
        defer {
            TWDataDelete(hashData);
        }
        return TWBitcoinSigningProviderAddRedeemScript(rawValue, hashData, script.rawValue)
    }

}
