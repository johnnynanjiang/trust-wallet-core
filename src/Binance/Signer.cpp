// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"

#include "../Hash.h"
#include "../HexCoding.h"
#include "../PrivateKey.h"

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <string>

using namespace TW;
using namespace TW::Binance;

// Message prefixes
static const auto sendPrefix = std::vector<uint8_t>{ 0x2A, 0x2C, 0x87, 0xFA };
static const auto tradeOrderPrefix = std::vector<uint8_t>{ 0xCE, 0x6D, 0xC0, 0x43 };
static const auto cancelTradeOrderPrefix = std::vector<uint8_t>{ 0x16, 0x6E, 0x68, 0x1B };
static const auto tokenFreezePrefix = std::vector<uint8_t>{ 0xE7, 0x74, 0xB3, 0x2D };
static const auto tokenUnfreezePrefix = std::vector<uint8_t>{ 0x65, 0x15, 0xFF, 0x0D };
static const auto pubKeyPrefix = std::vector<uint8_t>{ 0xEB, 0x5A, 0xE9, 0x87 };
static const auto transactionPrefix = std::vector<uint8_t>{ 0xF0, 0x62, 0x5D, 0xEE };

static inline std::string to_json(const std::string& key, const std::string& value) {
    static const char dqoute = '"';
    return dqoute + key + dqoute + ":" + dqoute + value + dqoute;
}

static inline std::string to_json(const std::string& key, int value) {
    static const char dqoute = '"';
    return dqoute + key + dqoute + ":" + std::to_string(value);
}

std::vector<uint8_t> Signer::build() const {
    auto signature = encodeSignature(sign());
   return encodeTransaction(signature);
}

std::vector<uint8_t> Signer::sign() const {
    auto key = PrivateKey(input.private_key());
    auto hash = Hash::sha256(signaturePreimage());
    auto signature = key.sign(hash);
    return std::vector<uint8_t>(signature.begin(), signature.end() - 1);
}

std::string Signer::signaturePreimage() const {
    std::string json;
    json += "{";
    json += to_json("account_number", std::to_string(input.account_number()));
    json += ",";
    json += to_json("chain_id", input.chain_id());
    json += ",";
    json += "\"data\":null,";
    json += to_json("memo", input.memo());
    json += ",";
    json += "\"msgs\":[" + orderJSON() + "],";
    json += to_json("sequence", std::to_string(input.sequence()));
    json += ",";
    json += to_json("source", std::to_string(input.source()));
    json += "}";
    return json;
}

std::string Signer::orderJSON() const {
    std::string json;
    json += "{";
    if (input.has_trade_order()) {
        json += to_json("id", input.trade_order().id());
        json += ",";
        json += to_json("ordertype", 2);
        json += ",";
        json += to_json("price", input.trade_order().price());
        json += ",";
        json += to_json("quantity", input.trade_order().quantity());
        json += ",";
        json += to_json("sender", input.trade_order().sender());
        json += ",";
        json += to_json("side", input.trade_order().side());
        json += ",";
        json += to_json("symbol", input.trade_order().symbol());
        json += ",";
        json += to_json("timeinforce", input.trade_order().timeinforce());
    } else {
        json += to_json("id", input.cancel_trade_order().id());
        json += ",";
        json += to_json("refid", input.cancel_trade_order().refid());
        json += ",";
        json += to_json("sender", input.cancel_trade_order().sender());
        json += ",";
        json += to_json("symbol", input.cancel_trade_order().symbol());
    }
    json += "}";
    return json;
}

std::vector<uint8_t> Signer::encodeTransaction(const std::vector<uint8_t>& signature) const {
    auto msg = encodeOrder();
    auto transaction = proto::BinanceTransaction();
    transaction.add_msgs(msg.data(), msg.size());
    transaction.add_signatures(signature.data(), signature.size());
    transaction.set_memo(input.memo());
    transaction.set_source(input.source());
    
    auto data = transaction.SerializeAsString();
    return aminoWrap(data, transactionPrefix, true);
}

std::vector<uint8_t> Signer::encodeOrder() const {
    std::string data;
    std::vector<uint8_t> prefix;
    if (input.has_trade_order()) {
        data = input.trade_order().SerializeAsString();
        prefix = tradeOrderPrefix;
    } else {
        data = input.cancel_trade_order().SerializeAsString();
        prefix = cancelTradeOrderPrefix;
    }
    return aminoWrap(data, prefix, false);
}

std::vector<uint8_t> Signer::encodeSignature(const std::vector<uint8_t>& signature) const {
    auto key = PrivateKey(input.private_key());
    auto publicKey = key.getPublicKey(true);

    auto encodedPublicKey = pubKeyPrefix;
    encodedPublicKey.insert(encodedPublicKey.end(), static_cast<uint8_t>(publicKey.size()));
    encodedPublicKey.insert(encodedPublicKey.end(), publicKey.begin(), publicKey.end());

    auto object = proto::BinanceSignature();
    object.set_pub_key(encodedPublicKey.data(), encodedPublicKey.size());
    object.set_signature(signature.data(), signature.size());
    object.set_account_number(input.account_number());
    object.set_sequence(input.sequence());

    return aminoWrap(object.SerializeAsString(), {}, false);
}

std::vector<uint8_t> Signer::aminoWrap(const std::string& raw, const std::vector<uint8_t>& typePrefix, bool prefixWithSize) const {
    const auto contentsSize = raw.size() + typePrefix.size();
    auto size = contentsSize;
    if (prefixWithSize) {
        size += 10;
    }

    std::string msg;
    msg.reserve(size);
    {
        google::protobuf::io::StringOutputStream output(&msg);
        google::protobuf::io::CodedOutputStream cos(&output);
        if (prefixWithSize) {
            cos.WriteVarint64(contentsSize);
        }
        cos.WriteRaw(typePrefix.data(), typePrefix.size());
        cos.WriteRaw(raw.data(), raw.size());
    }

    return std::vector<uint8_t>(msg.begin(), msg.end());
}
