// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public struct PublicKey {
    private var rawValue: TWPublicKey

    private init(rawValue: TWPublicKey) {
        self.rawValue = rawValue
    }

    public init?(data: Data) {
        rawValue = TWPublicKey()
        guard TWPublicKeyInitWithData(&rawValue, data.twData) else {
            return nil
        }
    }

    public static func isValid(data: Data) -> Bool {
        return TWPublicKeyIsValid(data.twData)
    }

    public var isCompressed: Bool {
        return TWPublicKeyIsCompressed(rawValue)
    }

    public var compressed: PublicKey {
        var newRawValue = TWPublicKey()
        TWPublicKeyCompressedCopy(rawValue, &newRawValue)
        return PublicKey(rawValue: newRawValue)
    }

    public var data: Data {
        var data = Data(repeating: 0, count: TWPublicKeyUncompressedSize)
        data.withUnsafeMutableBytes { ptr in
            TWPublicKeyCopyBytes(rawValue, ptr)
        }
        return data
    }
}
