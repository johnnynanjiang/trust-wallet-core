// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class BitcoinScript {

    public static func encodeNumber(value: Int) -> UInt8 {
        return TWBitcoinScriptEncodeNumber(Int32(value))
    }

    public static func decodeNumber(opcode: UInt8) -> Int {
        return TWBitcoinScriptDecodeNumber(opcode)
    }

    public static func buildPayToPublicKeyHash(hash: Data) -> BitcoinScript {
        return BitcoinScript(rawValue: TWBitcoinScriptBuildPayToPublicKeyHash(hash.twData))
    }

    public static func buildPayToScriptHash(scriptHash: Data) -> BitcoinScript {
        return BitcoinScript(rawValue: TWBitcoinScriptBuildPayToScriptHash(scriptHash.twData))
    }

    public static func buildPayToWitnessPubkeyHash(hash: Data) -> BitcoinScript {
        return BitcoinScript(rawValue: TWBitcoinScriptBuildPayToWitnessPubkeyHash(hash.twData))
    }

    public static func buildPayToWitnessScriptHash(scriptHash: Data) -> BitcoinScript {
        return BitcoinScript(rawValue: TWBitcoinScriptBuildPayToWitnessScriptHash(scriptHash.twData))
    }

    public var size: Int {
        return TWBitcoinScriptSize(rawValue)
    }

    public var data: Data {
        var result = Data(repeating: 0, count: TWBitcoinScriptData(rawValue, nil))
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptData(rawValue, ptr)
        }
        return result
    }

    public var scriptHash: Data {
        var result = Data(repeating: 0, count: 20)
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptScriptHash(rawValue, ptr)
        }
        return result
    }

    public var isPayToScriptHash: Bool {
        return TWBitcoinScriptIsPayToScriptHash(rawValue)
    }

    public var isPayToWitnessScriptHash: Bool {
        return TWBitcoinScriptIsPayToWitnessScriptHash(rawValue)
    }

    public var isWitnessProgram: Bool {
        return TWBitcoinScriptIsWitnessProgram(rawValue)
    }

    private let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(data: Data) {
        rawValue = TWBitcoinScriptCreate(data.twData)
    }

    deinit {
        TWBitcoinScriptDelete(rawValue)
    }

    public func matchPayToPubkey() -> Data {
        var result = Data(repeating: 0, count: TWPublicKeyUncompressedSize)
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptMatchPayToPubkey(rawValue, ptr)
        }
        return result
    }

    public func matchPayToPubkeyHash() -> Data {
        var result = Data(repeating: 0, count: TWBitcoinScriptMatchPayToPubkeyHash(rawValue, nil))
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptMatchPayToPubkeyHash(rawValue, ptr)
        }
        return result
    }

    public func matchPayToScriptHash() -> Data {
        var result = Data(repeating: 0, count: TWBitcoinScriptMatchPayToScriptHash(rawValue, nil))
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptMatchPayToScriptHash(rawValue, ptr)
        }
        return result
    }

    public func matchPayToWitnessPublicKeyHash() -> Data {
        var result = Data(repeating: 0, count: TWBitcoinScriptMatchPayToWitnessPublicKeyHash(rawValue, nil))
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptMatchPayToWitnessPublicKeyHash(rawValue, ptr)
        }
        return result
    }

    public func matchPayToWitnessScriptHash() -> Data {
        var result = Data(repeating: 0, count: TWBitcoinScriptMatchPayToWitnessScriptHash(rawValue, nil))
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptMatchPayToWitnessScriptHash(rawValue, ptr)
        }
        return result
    }

    public func encode() -> Data {
        var result = Data(repeating: 0, count: TWBitcoinScriptEncode(rawValue, nil))
        result.count = result.withUnsafeMutableBytes { ptr in
            TWBitcoinScriptEncode(rawValue, ptr)
        }
        return result
    }

}
