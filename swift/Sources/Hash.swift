// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class Hash {

    public static func sha1(data: Data) -> Data {
        return Data.fromTWData(TWHashSHA1(data.twData))
    }

    public static func sha256(data: Data) -> Data {
        return Data.fromTWData(TWHashSHA256(data.twData))
    }

    public static func sha512(data: Data) -> Data {
        return Data.fromTWData(TWHashSHA512(data.twData))
    }

    public static func keccak256(data: Data) -> Data {
        return Data.fromTWData(TWHashKeccak256(data.twData))
    }

    public static func keccak512(data: Data) -> Data {
        return Data.fromTWData(TWHashKeccak512(data.twData))
    }

    public static func sha3_256(data: Data) -> Data {
        return Data.fromTWData(TWHashSHA3_256(data.twData))
    }

    public static func sha3_512(data: Data) -> Data {
        return Data.fromTWData(TWHashSHA3_512(data.twData))
    }

    public static func ripemd(data: Data) -> Data {
        return Data.fromTWData(TWHashRIPEMD(data.twData))
    }

    public static func blake2b(data: Data, size: Int) -> Data {
        return Data.fromTWData(TWHashBlake2b(data.twData, size))
    }

    private var rawValue: TWHash

    init(rawValue: TWHash) {
        self.rawValue = rawValue
    }


}
