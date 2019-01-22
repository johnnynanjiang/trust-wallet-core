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
#include "../src/Bitcoin/Bech32Address.h"

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
    auto address = Bitcoin::Bech32Address("bnb1qhgm0p7khfk85zpz5v0j8wnej3a90w709jcx440");
    auto keyhash = address.keyHash();
    order.set_sender(keyhash.data(), keyhash.size());
    order.set_id("BA36F0FAD74D8F41045463E4774F328F4AF779E5-36");
    order.set_symbol("NNB-338_BNB");
    order.set_ordertype(2);
    order.set_side(1);
    order.set_price(136350000);
    order.set_quantity(100000000);
    order.set_timeinforce(1);
    
    auto signer = Binance::Signer(std::move(input));
    auto signature = signer.sign();

    ASSERT_EQ(hex(signature.begin(), signature.end()), "cf7895f68fc8d17ae5f4930193133108a5bca4e8ef3353d6a5378e4c30563aba2ebdc4265dc282df12625cc68ad94230eaa1137838383e0de49cc400dd9288eb");
}

TEST(BinanceSigner, Build) {
    auto input = proto::BinanceSigningInput();
    input.set_chain_id("chain-bnb");
    input.set_account_number(1);
    input.set_sequence(10);

    auto key = parse_hex("90335b9d2153ad1a9799a3ccc070bd64b4164e9642ee1dd48053c33f9a3a05e9");
    input.set_private_key(key.data(), key.size());

    auto& order = *input.mutable_trade_order();
    auto address = Bitcoin::Bech32Address::fromKeyhash(parse_hex("b6561dcc104130059a7c08f48c64610c1f6f9064"), "bnb");
    auto keyhash = address.keyHash();
    order.set_sender(keyhash.data(), keyhash.size());
    order.set_id("B6561DCC104130059A7C08F48C64610C1F6F9064-11");
    order.set_symbol("BTC-5C4_BNB");
    order.set_ordertype(2);
    order.set_side(1);
    order.set_price(100000000);
    order.set_quantity(1200000000);
    order.set_timeinforce(1);
    
    auto signer = Binance::Signer(std::move(input));
    auto result = signer.build();

    ASSERT_EQ(hex(result.begin(), result.end()), "db01"
        "f0625dee"
        "0a65"
            "ce6dc043"
            "0a14""b6561dcc104130059a7c08f48c64610c1f6f9064"
            "122b""423635363144434331303431333030353941374330384634384336343631304331463646393036342d3131"
            "1a0b""4254432d3543345f424e42"
            "2004"
            "2802"
            "308084af5f"
            "3880b0b4f808"
            "4002"
        "126e"
            "0a26"
            "eb5ae987"
            "21029729a52e4e3c2b4a4e52aa74033eedaf8ba1df5ab6d1f518fd69e67bbd309b0e"
            "1240""470646cc0187e6d87b0a7f354a17a7f098b66885fdf8c640f0fc7bfc629b225d0053bcf2d3cbb09d05172f9c9045fe4b195edf508e1d6752caf8da4d30563e96"
            "1802"
            "2014"
    );
}
