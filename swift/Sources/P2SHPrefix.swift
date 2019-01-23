// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

public enum P2SHPrefix: UInt8 {
    case bitcoin = 0x05
    case litecoin = 0x32
    case dash = 0x10
    case zcoin = 0x07
}
