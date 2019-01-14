// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public struct AES {

    public static func cbcencrypt(key: Data, data: Data, iv: Data) -> Data? {
        let keyData = TWDataCreateWithNSData(key);
        defer {
            TWDataDelete(keyData);
        }
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        let ivData = TWDataCreateWithNSData(iv);
        defer {
            TWDataDelete(ivData);
        }
        guard let data = TWAESCBCEncrypt(keyData, dataData, ivData) else {
            return nil
        }
        return TWDataNSData(data)
    }

    public static func cbcdecrypt(key: Data, data: Data, iv: Data) -> Data? {
        let keyData = TWDataCreateWithNSData(key);
        defer {
            TWDataDelete(keyData);
        }
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        let ivData = TWDataCreateWithNSData(iv);
        defer {
            TWDataDelete(ivData);
        }
        guard let data = TWAESCBCDecrypt(keyData, dataData, ivData) else {
            return nil
        }
        return TWDataNSData(data)
    }

    public static func ctrencrypt(key: Data, data: Data, iv: Data) -> Data? {
        let keyData = TWDataCreateWithNSData(key);
        defer {
            TWDataDelete(keyData);
        }
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        let ivData = TWDataCreateWithNSData(iv);
        defer {
            TWDataDelete(ivData);
        }
        guard let data = TWAESCTREncrypt(keyData, dataData, ivData) else {
            return nil
        }
        return TWDataNSData(data)
    }

    public static func ctrdecrypt(key: Data, data: Data, iv: Data) -> Data? {
        let keyData = TWDataCreateWithNSData(key);
        defer {
            TWDataDelete(keyData);
        }
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        let ivData = TWDataCreateWithNSData(iv);
        defer {
            TWDataDelete(ivData);
        }
        guard let data = TWAESCTRDecrypt(keyData, dataData, ivData) else {
            return nil
        }
        return TWDataNSData(data)
    }

    var rawValue: TWAES

    init(rawValue: TWAES) {
        self.rawValue = rawValue
    }


}
