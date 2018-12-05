// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class PublicKey {

    public static func isValid(data: Data) -> Bool {
        return TWPublicKeyIsValid(data.twData)
    }

    var rawValue: TWPublicKey

    public var isCompressed: Bool {
        return TWPublicKeyIsCompressed(rawValue)
    }

    public var compressed: PublicKey {
        return PublicKey(rawValue: TWPublicKeyCompressed(rawValue))
    }

    public var data: Data {
        return Data.fromTWData(TWPublicKeyData(rawValue))
    }

    init(rawValue: TWPublicKey) {
        self.rawValue = rawValue
    }

    public init(data: Data) {
        rawValue = TWPublicKey()
        TWPublicKeyInitWithData(&rawValue, data.twData)
    }


    public func verify(signature: Data, message: Data) -> Bool {
        return TWPublicKeyVerify(rawValue, signature.twData, message.twData)
    }

}
