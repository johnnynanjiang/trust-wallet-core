// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.wallet.crypto.trustapp.jni;


public enum CoinType {
    BITCOIN (0),
    LITECOIN (2),
    BITCOINCASH (145),
    DASH (5),
    ETHEREUM (60),
    ETHEREUMCLASSIC (61),
    THUNDERTOKEN (1001),
    GO (6060),
    POA (178),
    TRON (195),
    VECHAIN (818),
    CALLISTO (820),
    TOMOCHAIN (889),
    WANCHAIN (5718350),
    ICON (74),
    EOS (194);

    private final int value;
    CoinType(int value) {
        this.value = value;
    }
    public int value() { return value; }
}
