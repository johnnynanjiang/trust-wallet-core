// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public struct BitcoinAddress {

    public static func == (lhs: BitcoinAddress, rhs: BitcoinAddress) -> Bool {
        return TWBitcoinAddressEqual(lhs.rawValue, rhs.rawValue)
    }

    public static func isValid(data: Data) -> Bool {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        return TWBitcoinAddressIsValid(dataData)
    }

    var rawValue: TWBitcoinAddress

    public var description: String {
        return TWStringNSString(TWBitcoinAddressDescription(rawValue))
    }

    public var data: Data {
        return TWDataNSData(TWBitcoinAddressData(rawValue))
    }

    init(rawValue: TWBitcoinAddress) {
        self.rawValue = rawValue
    }

    public init(string: String) {
        let stringString = TWStringCreateWithNSString(string);
        defer {
            TWStringDelete(stringString);
        }
        rawValue = TWBitcoinAddress()
        TWBitcoinAddressInitWithString(&rawValue, stringString)
    }

    public init(data: Data) {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        rawValue = TWBitcoinAddress()
        TWBitcoinAddressInitWithData(&rawValue, dataData)
    }

    public init(publicKey: PublicKey, prefix: UInt8) {
        rawValue = TWBitcoinAddress()
        TWBitcoinAddressInitWithPublicKey(&rawValue, publicKey.rawValue, prefix)
    }


}
