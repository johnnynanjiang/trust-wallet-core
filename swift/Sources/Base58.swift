// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public struct Base58 {

    public static func encode(data: Data) -> String {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        return String.fromTWString(TWBase58Encode(dataData))
    }

    public static func decode(string: String) -> Data? {
        let stringString = TWStringCreateWithNSString(string);
        defer {
            TWStringDelete(stringString);
        }
        guard let data = TWBase58Decode(stringString) else {
            return nil
        }
        return TWDataNSData(data)
    }

    var rawValue: TWBase58

    init(rawValue: TWBase58) {
        self.rawValue = rawValue
    }


}
