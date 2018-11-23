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

    private var rawValue: TWPublicKey

    public var isCompressed: Bool {
        return TWPublicKeyIsCompressed(rawValue)
    }

    public var compressed: PublicKey {
        return PublicKey(rawValue: TWPublicKeyCompressed(rawValue))
    }

    public var data: Data {
        var result = Data(repeating: 0, count: TWPublicKeyUncompressedSize)
        result.count = result.withUnsafeMutableBytes { ptr in
            TWPublicKeyData(rawValue, ptr)
        }
        return result
    }

    init(rawValue: TWPublicKey) {
        self.rawValue = rawValue
    }

    public init(data: Data) {
        rawValue = TWPublicKey()
        TWPublicKeyInitWithData(&rawValue, data.twData)
    }

}
