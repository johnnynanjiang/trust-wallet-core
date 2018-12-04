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
        return Data.fromTWData(TWPrivateKeyData(rawValue))
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

    public func sign(digest: Data) -> Data? {
        return Data.fromTWData(TWPrivateKeySign(rawValue, digest.twData))
    }

    public func signAsDER(digest: Data) -> Data? {
        return Data.fromTWData(TWPrivateKeySignAsDER(rawValue, digest.twData))
    }

}
