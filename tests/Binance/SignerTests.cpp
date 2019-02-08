// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../../src/HexCoding.h"
#include "../../src/proto/Binance.pb.h"
#include "../../src/Tendermint/Address.h"
#include "../../src/Binance/Signer.h"

#include "../TWTestUtilities.h"

#include <TrustWalletCore/TWHRP.h>
#include <gtest/gtest.h>

namespace TW {
namespace Binance {

TEST(BinanceSigner, Sign) {
    auto input = Proto::SigningInput();
    input.set_chain_id("chain-bnb");
    input.set_account_number(12);
    input.set_sequence(35);
    input.set_memo("");
    input.set_source(1);

    auto key = parse_hex("90335b9d2153ad1a9799a3ccc070bd64b4164e9642ee1dd48053c33f9a3a05e9");
    input.set_private_key(key.data(), key.size());

    auto& order = *input.mutable_trade_order();
    auto result = Tendermint::Address::decode("bnb1hgm0p7khfk85zpz5v0j8wnej3a90w709vhkdfu");
    ASSERT_TRUE(result.second);
    auto keyhash = result.first.keyHash;
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
    auto input = Proto::SigningInput();
    input.set_chain_id("chain-bnb");
    input.set_account_number(1);
    input.set_sequence(10);

    auto key = parse_hex("90335b9d2153ad1a9799a3ccc070bd64b4164e9642ee1dd48053c33f9a3a05e9");
    input.set_private_key(key.data(), key.size());

    auto& order = *input.mutable_trade_order();
    auto address = Tendermint::Address(HRP_BINANCE, parse_hex("b6561dcc104130059a7c08f48c64610c1f6f9064"));
    auto keyhash = address.keyHash;
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
            "2002"
            "2801"
            "3080c2d72f"
            "3880989abc04"
            "4001"
        "126e"
            "0a26"
            "eb5ae987"
            "21029729a52e4e3c2b4a4e52aa74033eedaf8ba1df5ab6d1f518fd69e67bbd309b0e"
            "1240""470646cc0187e6d87b0a7f354a17a7f098b66885fdf8c640f0fc7bfc629b225d0053bcf2d3cbb09d05172f9c9045fe4b195edf508e1d6752caf8da4d30563e96"
            "1801"
            "200a"
    );
}

TEST(BinanceSigner, BuildSend) {
    auto signingInput = Proto::SigningInput();
    signingInput.set_chain_id("chain-bnb");
    signingInput.set_account_number(19);
    signingInput.set_sequence(23);
    signingInput.set_memo("test");
    signingInput.set_source(1);

    auto key = parse_hex("95949f757db1f57ca94a5dff23314accbe7abee89597bf6a3c7382c84d7eb832");
    signingInput.set_private_key(key.data(), key.size());

    auto& order = *signingInput.mutable_send_order();

    auto fromKeyhash = parse_hex("40c2979694bbc961023d1d27be6fc4d21a9febe6");
    auto fromAddress = Tendermint::Address(HRP_BINANCE, fromKeyhash);

    auto toKeyhash = parse_hex("88b37d5e05f3699e2a1406468e5d87cb9dcceb95");
    auto toAddress = Tendermint::Address(HRP_BINANCE, toKeyhash);

    auto input = order.add_inputs();
    input->set_address(fromKeyhash.data(), fromKeyhash.size());
    auto inputCoin = input->add_coins();
    inputCoin->set_denom("BNB");
    inputCoin->set_amount(1'001'000'000);

    auto output = order.add_outputs();
    output->set_address(toKeyhash.data(), toKeyhash.size());
    auto outputCoin = output->add_coins();
    outputCoin->set_denom("BNB");
    outputCoin->set_amount(1'001'000'000);

    auto signer = Binance::Signer(std::move(signingInput));
    auto result = signer.build();

    ASSERT_EQ(hex(result.begin(), result.end()), "cc01"
        "f0625dee"
        "0a4e"
            "2a2c87fa"
            "0a23""0a1440c2979694bbc961023d1d27be6fc4d21a9febe6120b0a03424e4210c098a8dd03"
            "1223""0a1488b37d5e05f3699e2a1406468e5d87cb9dcceb95120b0a03424e4210c098a8dd03"
        "126e"
            "0a26"
            "eb5ae987"
            "21026a35920088d98c3888ca68c53dfc93f4564602606cbb87f0fe5ee533db38e502"
            "1240""4f61545232dfac88f5c1cf38a605c3a00b194ed41d13b6f0a81c1002c3d31b0a384289aaa2a0a35cb8c716d08e319a78bb96ac130b23afb0eece43dce6e3215e"
            "1813"
            "2017"
        "1a04""74657374"
        "2001"
    );
}

}} // namespace
