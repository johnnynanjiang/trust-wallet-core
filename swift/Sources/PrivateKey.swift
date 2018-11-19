// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation
import Security

public class PrivateKey {
    private let rawValue: OpaquePointer

    public init() {
        let bytes = UnsafeMutableRawPointer.allocate(byteCount: TWPrivateKeySize, alignment: 8)
        guard SecRandomCopyBytes(kSecRandomDefault, TWPrivateKeySize, bytes) == 0 else {
            fatalError("Failed to generate a random private key.")
        }

        let twData = TWData(bytes: bytes.bindMemory(to: UInt8.self, capacity: TWPrivateKeySize), len: TWPrivateKeySize)
        guard let rawValue = TWPrivateKeyCreateWithData(twData) else {
            fatalError("Failed to generate a random private key.")
        }

        self.rawValue = rawValue
    }

    public init?(data: Data) {
        guard let rawValue = TWPrivateKeyCreateWithData(data.twData) else {
            return nil
        }
        self.rawValue = rawValue
    }

    deinit {
        TWPrivateKeyDelete(rawValue)
    }

    public static func isValid(data: Data) -> Bool {
        return TWPrivateKeyIsValid(data.twData)
    }

    public var data: Data {
        var data = Data()
        data.withUnsafeMutableBytes { ptr in
            TWPrivateKeyCopyBytes(rawValue, ptr)
        }
        return data
    }
}
