// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class Hash {

    public static func sha1(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashSHA1Length)
        result.withUnsafeMutableBytes { ptr in
            TWHashSHA1(data.twData, ptr)
        }
        return result
    }


    public static func sha256(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashSHA256Length)
        result.withUnsafeMutableBytes { ptr in
            TWHashSHA256(data.twData, ptr)
        }
        return result
    }


    public static func sha512(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashSHA512Length)
        result.withUnsafeMutableBytes { ptr in
            TWHashSHA512(data.twData, ptr)
        }
        return result
    }


    public static func keccak256(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashSHA256Length)
        result.withUnsafeMutableBytes { ptr in
            TWHashKeccak256(data.twData, ptr)
        }
        return result
    }


    public static func keccak512(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashSHA512Length)
        result.withUnsafeMutableBytes { ptr in
            TWHashKeccak512(data.twData, ptr)
        }
        return result
    }


    public static func sha3_256(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashSHA256Length)
        result.withUnsafeMutableBytes { ptr in
            TWHashSHA3_256(data.twData, ptr)
        }
        return result
    }


    public static func sha3_512(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashSHA512Length)
        result.withUnsafeMutableBytes { ptr in
            TWHashSHA3_512(data.twData, ptr)
        }
        return result
    }


    public static func ripemd(data: Data) -> Data {
        var result = Data(repeating: 0, count: TWHashRipemdLength)
        result.withUnsafeMutableBytes { ptr in
            TWHashRIPEMD(data.twData, ptr)
        }
        return result
    }


    public static func blake2b(data: Data, result: inout Data, size: Int) -> Void {
        result.withUnsafeMutableBytes { ptr in
            return TWHashBlake2b(data.twData, ptr, size)
        }
    }

    private var rawValue: TWHash

    init(rawValue: TWHash) {
        self.rawValue = rawValue
    }

}
