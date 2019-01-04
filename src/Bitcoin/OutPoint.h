// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <algorithm>

namespace TW {
namespace Bitcoin {

/// Bitcoin transaction out-point reference.
class OutPoint {
public:
    /// The hash of the referenced transaction.
    uint8_t hash[32];

    /// The index of the specific output in the transaction.
    uint32_t index;

    /// Initializes an out-point reference with a hash and an index.
    template <typename T>
    OutPoint(const T& h, uint32_t index) {
        std::copy(std::begin(h), std::end(h), hash);
        this->index = index;
    }

    /// Encodes the out-point into the provided buffer.
    void encode(std::vector<uint8_t>& data) const;
};

}} // namespace
