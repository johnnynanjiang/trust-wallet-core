// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class BitcoinScript {

    public static func encodeNumber(value: Int32) -> UInt8 {
        return TWBitcoinScriptEncodeNumber(Int32(value))
    }

    public static func decodeNumber(opcode: UInt8) -> Int32 {
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
        return Data.fromTWData(TWBitcoinScriptData(rawValue))
    }

    public var scriptHash: Data {
        return Data.fromTWData(TWBitcoinScriptScriptHash(rawValue))
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

    public func matchPayToPubkey() -> Data? {
        return Data.fromTWData(TWBitcoinScriptMatchPayToPubkey(rawValue))
    }

    public func matchPayToPubkeyHash() -> Data? {
        return Data.fromTWData(TWBitcoinScriptMatchPayToPubkeyHash(rawValue))
    }

    public func matchPayToScriptHash() -> Data? {
        return Data.fromTWData(TWBitcoinScriptMatchPayToScriptHash(rawValue))
    }

    public func matchPayToWitnessPublicKeyHash() -> Data? {
        return Data.fromTWData(TWBitcoinScriptMatchPayToWitnessPublicKeyHash(rawValue))
    }

    public func matchPayToWitnessScriptHash() -> Data? {
        return Data.fromTWData(TWBitcoinScriptMatchPayToWitnessScriptHash(rawValue))
    }

    public func encode() -> Data {
        return Data.fromTWData(TWBitcoinScriptEncode(rawValue))
    }

}
