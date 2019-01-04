// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import TrustWalletCore
import XCTest

class UInt256Tests: XCTestCase {
    func testCreateWithData() {
        let data = Data(bytes: Array(repeating: 0, count: 24) + [0x1b, 0xc1, 0x6d, 0x67, 0x4e, 0xc8, 0x00, 0x00])
        let number = UInt256(data: data)!

        XCTAssertEqual(number.format(decimals: 18, exponent: 0), "2.0")
        XCTAssertEqual(Array(number.data), Array(data))
    }

    func testZeroData() {
        XCTAssertEqual(Array(UInt256.zero.data), Array(repeating: 0, count: 32))
    }

    func testIsZero() {
        XCTAssertTrue(UInt256.zero.isZero)
        XCTAssertFalse(UInt256.one.isZero)
    }

    func testFormat() {
        XCTAssertEqual(UInt256.zero.format(decimals: 0, exponent: 0), "0")
        XCTAssertEqual(UInt256.one.format(decimals: 0, exponent: 0), "1")
        XCTAssertEqual(UInt256.zero.format(decimals: 1, exponent: 1), "0.0")

        let x = UInt256(1234567890 as UInt64)
        XCTAssertEqual(x.format(decimals: 0, exponent: 0), "1234567890")
        XCTAssertEqual(x.format(decimals: 1, exponent: 1), "1234567890.0")
        XCTAssertEqual(x.format(decimals: 5, exponent: 0), "12345.6789")
        XCTAssertEqual(x.format(decimals: 5, exponent: 1), "123456.789")
    }
}
