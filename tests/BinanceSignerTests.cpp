// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

#include "../src/HexCoding.h"
#include "../src/TrustWalletCore.pb.h"
#include "../src/Binance/Signer.h"

using namespace TW;

TEST(BinanceSigner, Sign) {
    auto input = proto::BinanceSigningInput();
    input.set_chain_id("chain-bnb");
    input.set_account_number(12);
    input.set_sequence(35);
    input.set_memo("");
    input.set_source(1);

    auto key = parse_hex("90335b9d2153ad1a9799a3ccc070bd64b4164e9642ee1dd48053c33f9a3a05e9");
    input.set_private_key(key.data(), key.size());

    auto& order = *input.mutable_trade_order();
    order.set_sender("bnc1hgm0p7khfk85zpz5v0j8wnej3a90w7098fpxyh");
    order.set_id("BA36F0FAD74D8F41045463E4774F328F4AF779E5-36");
    order.set_symbol("NNB-338_BNB");
    order.set_ordertype(2);
    order.set_side(1);
    order.set_price(136350000);
    order.set_quantity(100000000);
    order.set_timeinforce(1);
    
    auto signer = Binance::Signer(std::move(input));
    auto signature = signer.sign();

    ASSERT_EQ(hex(signature.begin(), signature.end()), "08bf9c556c1f632e42c4eca3efd72971517a07b07853af3d8f8581ee58209a9771763286cf2859b62c6e3f139ac15c3d46eafd7b1d71763ac45a4b053b23a347");
}

TEST(BinanceSigner, Build) {
    auto input = proto::BinanceSigningInput();
    input.set_chain_id("chain-bnb");
    input.set_account_number(1);
    input.set_sequence(10);

    auto key = parse_hex("90335b9d2153ad1a9799a3ccc070bd64b4164e9642ee1dd48053c33f9a3a05e9");
    input.set_private_key(key.data(), key.size());

    auto& order = *input.mutable_trade_order();
    auto sender = parse_hex("b6561dcc104130059a7c08f48c64610c1f6f9064");
    order.set_sender(sender.data(), sender.size());
    order.set_id("B6561DCC104130059A7C08F48C64610C1F6F9064-11");
    order.set_symbol("BTC-5C4_BNB");
    order.set_ordertype(2);
    order.set_side(1);
    order.set_price(100000000);
    order.set_quantity(1200000000);
    order.set_timeinforce(1);
    
    auto signer = Binance::Signer(std::move(input));
    auto result = signer.build();

    ASSERT_EQ(hex(result.begin(), result.end()), "db01f0625dee0a65ce6dc0430a14b6561dcc104130059a7c08f48c64610c1f6f9064122b423635363144434331303431333030353941374330384634384336343631304331463646393036342d31311a0b4254432d3543345f424e4220042802308084af5f3880b0b4f8084002126e0a26eb5ae98721029729a52e4e3c2b4a4e52aa74033eedaf8ba1df5ab6d1f518fd69e67bbd309b0e1240fd9048590c14524cb79dc02dde290beb044556f3b00c758e582f45035cb1c8e15569da6b5ca3734e11d2fcd490d53f16569a36b190a34e2233a6c16b1830dff518022014");
}
