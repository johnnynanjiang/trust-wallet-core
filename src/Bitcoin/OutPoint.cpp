// Copyright © 2017-2018 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "OutPoint.h"

#include "TWBinaryCoding.h"

using namespace TW::Bitcoin;

void OutPoint::encode(std::vector<uint8_t>& data) const {
    std::copy(std::begin(hash), std::end(hash), std::back_inserter(data));
    encode32(index, data);
}
