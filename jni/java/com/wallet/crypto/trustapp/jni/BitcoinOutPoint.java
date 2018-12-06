// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;

import java.security.InvalidParameterException;

public class BitcoinOutPoint {
    private byte[] bytes;

    private BitcoinOutPoint() {
    }

    static BitcoinOutPoint createFromNative(byte[] bytes) {
        BitcoinOutPoint instance = new BitcoinOutPoint();
        instance.bytes = bytes;
        return instance;
    }

    static native boolean initWithHash(byte[] hash, int index);

    public static native boolean equals(BitcoinOutPoint lhs, BitcoinOutPoint rhs);
    public native byte[] hash();
    public native int index();
    public native byte[] encode();

    public BitcoinOutPoint(byte[] hash, int index) {
        initWithHash(hash, index);
        if (bytes == null) {
            throw new InvalidParameterException();
        }
    }

}
