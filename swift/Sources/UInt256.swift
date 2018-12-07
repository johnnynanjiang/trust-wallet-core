// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class UInt256 {
    public static var zero: UInt256 {
        return UInt256(rawValue: TWUInt256Zero())
    }

    public static var one: UInt256 {
        return UInt256(rawValue: TWUInt256One())
    }


    public static func == (lhs: UInt256, rhs: UInt256) -> Bool {
        return TWUInt256Equal(lhs.rawValue, rhs.rawValue)
    }

    public static func < (lhs: UInt256, rhs: UInt256) -> Bool {
        return TWUInt256Less(lhs.rawValue, rhs.rawValue)
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
        return TWDataNSData(TWUInt256Data(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init?(data: Data) {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        guard let rawValue = TWUInt256CreateWithData(dataData) else {
            return nil
        }
        self.rawValue = rawValue
    }

    public init(_ value: UInt32) {
        rawValue = TWUInt256CreateWithUInt32(value)
    }

    public init(_ value: UInt64) {
        rawValue = TWUInt256CreateWithUInt64(value)
    }

    deinit {
        TWUInt256Delete(rawValue)
    }

    public func format(decimals: Int32, exponent: Int32) -> String {
        return String.fromTWString(TWUInt256Format(rawValue, Int32(decimals), Int32(exponent)))
    }

}
