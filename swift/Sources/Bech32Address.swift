// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public final class Bech32Address {

    public static func == (lhs: Bech32Address, rhs: Bech32Address) -> Bool {
        return TWBech32AddressEqual(lhs.rawValue, rhs.rawValue)
    }

    public static func isValidString(string: String) -> Bool {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        return TWBech32AddressIsValidString(stringString)
    }

    public var description: String {
        return TWStringNSString(TWBech32AddressDescription(rawValue))
    }

    public var hrp: HRP {
        return HRP(rawValue: TWBech32AddressHRP(rawValue).rawValue)!
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init?(string: String) {
        let stringString = TWStringCreateWithNSString(string)
        defer {
            TWStringDelete(stringString)
        }
        guard let rawValue = TWBech32AddressCreateWithString(stringString) else {
            return nil
        }
        self.rawValue = rawValue
    }

    public init?(publicKey: PublicKey, hrp: HRP) {
        guard let rawValue = TWBech32AddressCreateWithPublicKey(publicKey.rawValue, TWHRP(rawValue: hrp.rawValue)) else {
            return nil
        }
        self.rawValue = rawValue
    }

    deinit {
        TWBech32AddressDelete(rawValue)
    }

}
