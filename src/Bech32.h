// Copyright © 2017 Pieter Wuille
// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <stdint.h>
#include <vector>
#include <string>

namespace TW {
namespace Bech32 {

/// Encodes a Bech32 string.
///
/// \returns the encoded string, or an empty string in case of failure.
std::string encode(const std::string& hrp, const std::vector<uint8_t>& values);

/// Decodes a Bech32 string.
///
/// \returns a pair with the human-readable part and the data, or a pair or empty collections on failure.
std::pair<std::string, std::vector<uint8_t>> decode(const std::string& str);

}} // namespace
