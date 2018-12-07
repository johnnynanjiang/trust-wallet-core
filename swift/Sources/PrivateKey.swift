// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class PrivateKey {

    public static func isValid(data: Data) -> Bool {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        return TWPrivateKeyIsValid(dataData)
    }

    public var data: Data {
        return TWDataNSData(TWPrivateKeyData(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init() {
        rawValue = TWPrivateKeyCreate()
    }

    public init?(data: Data) {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        guard let rawValue = TWPrivateKeyCreateWithData(dataData) else {
            return nil
        }
        self.rawValue = rawValue
    }

    deinit {
        TWPrivateKeyDelete(rawValue)
    }

    public func sign(digest: Data) -> Data? {
        let digestData = TWDataCreateWithNSData(digest);
        defer {
            TWDataDelete(digestData);
        }
        guard let result = TWPrivateKeySign(rawValue, digestData) else {
            return nil
        }
        return TWDataNSData(result)
    }

    public func signAsDER(digest: Data) -> Data? {
        let digestData = TWDataCreateWithNSData(digest);
        defer {
            TWDataDelete(digestData);
        }
        guard let result = TWPrivateKeySignAsDER(rawValue, digestData) else {
            return nil
        }
        return TWDataNSData(result)
    }

}
