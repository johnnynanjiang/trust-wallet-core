// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

import Foundation

public struct CoinTypeConfiguration {

    public static func getSymbol(type: CoinType) -> String? {
        guard let result = TWCoinTypeConfigurationGetSymbol(TWCoinType(rawValue: type.rawValue)) else {
            return nil
        }
        return TWStringNSString(result)
    }

    public static func getDecimals(type: CoinType) -> Int32 {
        return TWCoinTypeConfigurationGetDecimals(TWCoinType(rawValue: type.rawValue))
    }

    public static func getTransactionURL(type: CoinType, transactionID: String) -> String? {
        let transactionIDString = TWStringCreateWithNSString(transactionID)
        defer {
            TWStringDelete(transactionIDString)
        }
        guard let result = TWCoinTypeConfigurationGetTransactionURL(TWCoinType(rawValue: type.rawValue), transactionIDString) else {
            return nil
        }
        return TWStringNSString(result)
    }

    var rawValue: TWCoinTypeConfiguration

    init(rawValue: TWCoinTypeConfiguration) {
        self.rawValue = rawValue
    }


}
