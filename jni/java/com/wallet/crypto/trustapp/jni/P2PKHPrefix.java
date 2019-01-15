// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;


public enum P2PKHPrefix {
    BITCOIN (0x00),
    LITECOIN (0x30),
    DASH (0x4C);

    private final int value;
    P2PKHPrefix(int value) {
        this.value = value;
    }
    public int value() { return value; }
}
