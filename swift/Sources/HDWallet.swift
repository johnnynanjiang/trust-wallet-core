// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

public class HDWallet {

    public static func getPublicKeyFromExtended(extended: String, versionPublic: UInt32, versionPrivate: UInt32, change: UInt32, address: UInt32) -> PublicKey {
        let extendedString = TWStringCreateWithNSString(extended);
        defer {
            TWStringDelete(extendedString);
        }
        return PublicKey(rawValue: TWHDWalletGetPublicKeyFromExtended(extendedString, versionPublic, versionPrivate, change, address))
    }

    public var seed: Data {
        return TWDataNSData(TWHDWalletSeed(rawValue))
    }

    public var mnemonic: String {
        return TWStringNSString(TWHDWalletMnemonic(rawValue))
    }

    let rawValue: OpaquePointer

    init(rawValue: OpaquePointer) {
        self.rawValue = rawValue
    }

    public init(strength: Int32, passphrase: String) {
        let passphraseString = TWStringCreateWithNSString(passphrase);
        defer {
            TWStringDelete(passphraseString);
        }
        rawValue = TWHDWalletCreate(Int32(strength), passphraseString)
    }

    public init(mnemonic: String, passphrase: String) {
        let mnemonicString = TWStringCreateWithNSString(mnemonic);
        defer {
            TWStringDelete(mnemonicString);
        }
        let passphraseString = TWStringCreateWithNSString(passphrase);
        defer {
            TWStringDelete(passphraseString);
        }
        rawValue = TWHDWalletCreateWithMnemonic(mnemonicString, passphraseString)
    }

    public init(data: Data, passphrase: String) {
        let dataData = TWDataCreateWithNSData(data);
        defer {
            TWDataDelete(dataData);
        }
        let passphraseString = TWStringCreateWithNSString(passphrase);
        defer {
            TWStringDelete(passphraseString);
        }
        rawValue = TWHDWalletCreateWithData(dataData, passphraseString)
    }

    deinit {
        TWHDWalletDelete(rawValue)
    }

    public func getKey(purpose: UInt32, coin: UInt32, account: UInt32, change: UInt32, address: UInt32) -> PrivateKey {
        return PrivateKey(rawValue: TWHDWalletGetKey(rawValue, purpose, coin, account, change, address))
    }

    public func getExtendedPrivateKey(purpose: UInt32, coin: UInt32, version: UInt32) -> String {
        return String.fromTWString(TWHDWalletGetExtendedPrivateKey(rawValue, purpose, coin, version))
    }

    public func getExtendedPublicKey(purpose: UInt32, coin: UInt32, version: UInt32) -> String {
        return String.fromTWString(TWHDWalletGetExtendedPublicKey(rawValue, purpose, coin, version))
    }

}
