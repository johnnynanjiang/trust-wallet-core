// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../TrustWalletCore.pb.h"
#include <nlohmann/json.hpp>

namespace TW {
namespace Binance {

nlohmann::json signatureJSON(const proto::BinanceSigningInput& input);
nlohmann::json orderJSON(const proto::BinanceSigningInput& input);
nlohmann::json inputsJSON(const proto::BinanceSendOrder& order);
nlohmann::json outputsJSON(const proto::BinanceSendOrder& order);
nlohmann::json tokensJSON(const ::google::protobuf::RepeatedPtrField<proto::BinanceSendOrder_Token>& tokens);

}} // namespace
