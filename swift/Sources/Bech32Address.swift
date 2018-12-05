// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class Bech32Address {

    public static func == (lhs: Bech32Address, rhs: Bech32Address) -> Bool {
        return TWBech32AddressEqual(lhs.rawValue, rhs.rawValue)
    }

    public static func isValid(data: Data) -> Bool {
        return TWBech32AddressIsValid(data.twData)
    }

    var rawValue: TWBech32Address

    public var description: String {
        return TWStringNSString(TWBech32AddressDescription(rawValue))
    }

    init(rawValue: TWBech32Address) {
        self.rawValue = rawValue
    }

    public init(string: String) {
        rawValue = TWBech32Address()
        TWBech32AddressInitWithString(&rawValue, string)
    }

    public init(data: Data, hrp: String) {
        rawValue = TWBech32Address()
        TWBech32AddressInitWithData(&rawValue, data.twData, hrp)
    }

    public init(publicKey: PublicKey, hrp: String) {
        rawValue = TWBech32Address()
        TWBech32AddressInitWithPublicKey(&rawValue, publicKey.rawValue, hrp)
    }


}
