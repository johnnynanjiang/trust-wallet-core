// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;


public enum P2SHPrefix {
    BITCOIN (0x05),
    LITECOIN (0x32),
    DASH (0x10);

    private final int value;
    P2SHPrefix(int value) {
        this.value = value;
    }
    public int value() { return value; }
}
