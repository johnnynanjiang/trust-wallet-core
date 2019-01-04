// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public struct Bech32Address {

    public static func == (lhs: Bech32Address, rhs: Bech32Address) -> Bool {
        return TWBech32AddressEqual(lhs.rawValue, rhs.rawValue)
    }

    public static func isValid(data: Data) -> Bool {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        return TWBech32AddressIsValid(dataData)
    }

    public static func isValidString(string: String) -> Bool {
        let stringString = TWStringCreateWithNSString(string);
        defer {
            TWStringDelete(stringString);
        }
        return TWBech32AddressIsValidString(stringString)
    }

    var rawValue: TWBech32Address

    public var description: String {
        return TWStringNSString(TWBech32AddressDescription(rawValue))
    }

    public var data: Data {
        return TWDataNSData(TWBech32AddressData(rawValue))
    }

    init(rawValue: TWBech32Address) {
        self.rawValue = rawValue
    }

    public init(string: String) {
        let stringString = TWStringCreateWithNSString(string);
        defer {
            TWStringDelete(stringString);
        }
        rawValue = TWBech32Address()
        TWBech32AddressInitWithString(&rawValue, stringString)
    }

    public init(data: Data, hrp: String) {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        let hrpString = TWStringCreateWithNSString(hrp);
        defer {
            TWStringDelete(hrpString);
        }
        rawValue = TWBech32Address()
        TWBech32AddressInitWithData(&rawValue, dataData, hrpString)
    }

    public init(publicKey: PublicKey, hrp: String) {
        let hrpString = TWStringCreateWithNSString(hrp);
        defer {
            TWStringDelete(hrpString);
        }
        rawValue = TWBech32Address()
        TWBech32AddressInitWithPublicKey(&rawValue, publicKey.rawValue, hrpString)
    }


}
