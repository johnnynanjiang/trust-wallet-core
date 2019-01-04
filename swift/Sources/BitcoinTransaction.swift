// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public final class BitcoinTransaction {

    public var lockTime: UInt32 {
        return TWBitcoinTransactionLockTime(rawValue)
    }

    public var inputCount: Int {
        return TWBitcoinTransactionInputCount(rawValue)
    }

    public var outputCount: Int {
        return TWBitcoinTransactionOutputCount(rawValue)
    }

    public var hash: Data {
        return TWDataNSData(TWBitcoinTransactionHash(rawValue))
    }

    public var witnessHash: Data {
        return TWDataNSData(TWBitcoinTransactionWitnessHash(rawValue))
    }

    public var identifier: String {
        return TWStringNSString(TWBitcoinTransactionIdentifier(rawValue))
    }

    public var witnessIdentifier: String {
        return TWStringNSString(TWBitcoinTransactionWitnessIdentifier(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(version: Int32, lockTime: UInt32) {
        rawValue = TWBitcoinTransactionCreate(Int32(version), lockTime)
    }

    deinit {
        TWBitcoinTransactionDelete(rawValue)
    }

    public func getInput(index: Int) -> BitcoinTransactionInput {
        return BitcoinTransactionInput(rawValue: TWBitcoinTransactionGetInput(rawValue, index))
    }

    public func addInput(previousOutput: BitcoinOutPoint, script: BitcoinScript?, sequence: UInt32) -> Void {
        return TWBitcoinTransactionAddInput(rawValue, previousOutput.rawValue, script?.rawValue, sequence)
    }

    public func getOutput(index: Int) -> BitcoinTransactionOutput {
        return BitcoinTransactionOutput(rawValue: TWBitcoinTransactionGetOutput(rawValue, index))
    }

    public func addOutput(value: UInt64, script: BitcoinScript) -> Void {
        return TWBitcoinTransactionAddOutput(rawValue, value, script.rawValue)
    }

    public func encode(witness: Bool) -> Data {
        return TWDataNSData(TWBitcoinTransactionEncode(rawValue, witness))
    }

}
