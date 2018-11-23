// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class PrivateKey {

    public static func isValid(data: Data) -> Bool {
        return TWPrivateKeyIsValid(data.twData)
    }

    public var data: Data {
        var result = Data(repeating: 0, count: TWPrivateKeySize)
        result.withUnsafeMutableBytes { ptr in
            TWPrivateKeyData(rawValue, ptr)
        }
        return result
    }

    private let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init() {
        rawValue = TWPrivateKeyCreate()
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


    public func sign(digest: Data, result: inout Data) -> Bool {
        return result.withUnsafeMutableBytes { ptr in
            TWPrivateKeySign(rawValue, digest.twData, ptr)
        }
    }

    public func signAsDER(digest: Data) -> Data {
        var result = Data(repeating: 0, count: 72)
        result.count = result.withUnsafeMutableBytes { ptr in
            TWPrivateKeySignAsDER(rawValue, digest.twData, ptr)
        }
        return result
    }

}
