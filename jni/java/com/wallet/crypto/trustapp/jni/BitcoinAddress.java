// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;

public class BitcoinAddress {
    private byte[] bytes;

    private BitcoinAddress() {
    }

    static BitcoinAddress createFromNative(byte[] bytes) {
        BitcoinAddress instance = new BitcoinAddress();
        instance.bytes = bytes;
        return instance;
    }

    static native byte[] initWithString(String string);
    static native byte[] initWithData(byte[] data);
    static native byte[] initWithPublicKey(PublicKey publicKey, char prefix);

    public static native boolean equals(BitcoinAddress lhs, BitcoinAddress rhs);
    public static native boolean isValid(byte[] data);
    public native String description();
    public native byte[] data();

    public BitcoinAddress(String string) {
        bytes = initWithString(string);
        if (bytes == null) {
            throw new InvalidParameterException();
        }
    }

    public BitcoinAddress(byte[] data) {
        bytes = initWithData(data);
        if (bytes == null) {
            throw new InvalidParameterException();
        }
    }

    public BitcoinAddress(PublicKey publicKey, char prefix) {
        bytes = initWithPublicKey(publicKey, prefix);
        if (bytes == null) {
            throw new InvalidParameterException();
        }
    }

}
