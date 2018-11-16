// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class UInt256: Comparable {
    private var rawValue: OpaquePointer

    private init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public static var zero: UInt256 {
        return UInt256(rawValue: TWUInt256Zero())
    }

    public static var one: UInt256 {
        return UInt256(rawValue: TWUInt256One())
    }

    public init?(data: Data) {
        var rawData = data.twData
        guard let rawValue = TWUInt256CreateWithData(&rawData) else {
            return nil
        }
        self.rawValue = rawValue
    }

    public convenience init(_ value: UInt32) {
        self.init(rawValue: TWUInt256CreateWithUInt32(value))
    }

    public convenience init(_ value: UInt64) {
        self.init(rawValue: TWUInt256CreateWithUInt64(value))
    }

    deinit {
        TWUInt256Delete(rawValue)
    }

    public var isZero: Bool {
        return TWUInt256IsZero(rawValue)
    }

    public var uint32Value: UInt32 {
        return TWUInt256UInt32Value(rawValue)
    }

    public var uint64Value: UInt64 {
        return TWUInt256UInt64Value(rawValue)
    }

    public var data: Data {
        var data = Data(repeating: 0, count: 32)
        data.withUnsafeMutableBytes { ptr in
            TWUInt256CopyData(rawValue, ptr)
        }
        guard let start = data.firstIndex(where: { $0 != 0 }) else {
            return Data(repeating: 0, count: 1)
        }
        return data[start...]
    }

    public static func == (lhs: UInt256, rhs: UInt256) -> Bool {
        return TWUInt256Equal(lhs.rawValue, rhs.rawValue)
    }

    public static func < (lhs: UInt256, rhs: UInt256) -> Bool {
        return TWUInt256Less(lhs.rawValue, rhs.rawValue)
    }

    public func format(decimals: Int = 0, exponent: Int = 0) -> String {
        var data = Data(repeating: 0, count: 80)
        data.count = data.withUnsafeMutableBytes { ptr in
            return TWUInt256Format(rawValue, Int32(decimals), Int32(exponent), ptr, 80)
        }
        return String(bytes: data, encoding: .utf8)!
    }
}
