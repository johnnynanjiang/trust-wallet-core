// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;

public class Bech32Address {
    private byte[] bytes;

    private Bech32Address() {
    }

    static Bech32Address createFromNative(byte[] bytes) {
        Bech32Address instance = new Bech32Address();
        instance.bytes = bytes;
        return instance;
    }

    static native byte[] initWithString(String string);
    static native byte[] initWithData(byte[] data, String hrp);
    static native byte[] initWithPublicKey(PublicKey publicKey, String hrp);

    public static native boolean equals(Bech32Address lhs, Bech32Address rhs);
    public static native boolean isValid(byte[] data);
    public static native boolean isValidString(String string);
    public native String description();
    public native byte[] data();

    public Bech32Address(String string) {
        bytes = initWithString(string);
        if (bytes == null) {
            throw new InvalidParameterException();
        }
    }

    public Bech32Address(byte[] data, String hrp) {
        bytes = initWithData(data, hrp);
        if (bytes == null) {
            throw new InvalidParameterException();
        }
    }

    public Bech32Address(PublicKey publicKey, String hrp) {
        bytes = initWithPublicKey(publicKey, hrp);
        if (bytes == null) {
            throw new InvalidParameterException();
        }
    }

}
