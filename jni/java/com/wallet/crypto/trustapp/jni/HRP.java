// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;


public enum HRP {
    UNKNOWN (0),
    BITCOIN (1),
    LITECOIN (2),
    BITCOINCASH (3),
    BINANCE (4);

    private final int value;
    HRP(int value) {
        this.value = value;
    }
    public int value() { return value; }

    public String toString() {
        switch (this) {
        case UNKNOWN: return "";
        case BITCOIN: return "bc";
        case LITECOIN: return "ltc";
        case BITCOINCASH: return "bitcoincash";
        case BINANCE: return "bnb";
        default: return "";
        }
    }
}
