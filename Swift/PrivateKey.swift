// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class PrivateKey {
    private var rawValue: OpaquePointer

    public init() {
        rawValue = TWPrivateKeyCreate()
    }

    public init?(data: Data) {
        var rawData = data.twData
        guard let rawValue = TWPrivateKeyCreateWithData(&rawData) else {
            return nil
        }
        self.rawValue = rawValue
    }

    deinit {
        TWPrivateKeyFree(rawValue)
    }

    public static func isValid(data: Data) -> Bool {
        var twdata = data.twData
        return TWPrivateKeyIsValid(&twdata)
    }
}
