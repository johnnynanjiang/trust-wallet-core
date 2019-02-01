// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWCoinTypeConfiguration.h>

#include "gtest/gtest.h"
#include "TWTestUtilities.h"

TEST(TWCoinTypeConfiguration, TWCoinTypeConfigurationGetSymbol) {
    auto value1 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeEthereum));
    assertStringsEqual(value1, "ETH");

    auto value2 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeBitcoin));
    assertStringsEqual(value2, "BTC");

    auto value3 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeBitcoinCash));
    assertStringsEqual(value3, "BCH");

    auto value4 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeCallisto));
    assertStringsEqual(value4, "CLO");

    auto value5 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeDash));
    assertStringsEqual(value5, "DASH");

    auto value6 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeEthereumClassic));
    assertStringsEqual(value6, "ETC");

    auto value7 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeGo));
    assertStringsEqual(value7, "GO");

    auto value8 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeICON));
    assertStringsEqual(value8, "ICX");

    auto value9 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeLitecoin));
    assertStringsEqual(value9, "LTC");

    auto value10 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypePoa));
    assertStringsEqual(value10, "POA");

    auto value12 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeThunderToken));
    assertStringsEqual(value12, "TT");

    auto value13 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeTomoChain));
    assertStringsEqual(value13, "TOMO");

    auto value14 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeTron));
    assertStringsEqual(value14, "TRX");

    auto value15 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeVeChain));
    assertStringsEqual(value15, "VET");

    auto value16 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeZCoin));
    assertStringsEqual(value16, "XZC");

    auto value17 = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeBinance));
    assertStringsEqual(value17, "BNB");
}

TEST(TWCoinTypeConfiguration, TWCoinTypeConfigurationGetDecimals) {
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeEthereum), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeBitcoin), 8);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeBitcoinCash), 8);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeCallisto), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeDash), 8);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeEthereumClassic), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeGo), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeICON), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeLitecoin), 8);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypePoa), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeTest), 0);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeThunderToken), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeTomoChain), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeTron), 6);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeVeChain), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeWanChain), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeVeChain), 18);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeZCoin), 8);
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeBinance), 8);
}

TEST(TWCoinTypeConfiguration, TWCoinTypeConfigurationGetTransactionURL) {
    auto txId = TWStringCreateWithUTF8Bytes("123");
    auto value1 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeEthereum, txId));
    assertStringsEqual(value1, "https://etherscan.io/tx/123");

    auto value2 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeBitcoin, txId));
    assertStringsEqual(value2, "https://blockchair.com/bitcoin/transaction/123");

    auto value3 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeBitcoinCash, txId));
    assertStringsEqual(value3, "https://blockchair.com/bitcoin-cash/transaction/123");

    auto value4 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeCallisto, txId));
    assertStringsEqual(value4, "https://explorer2.callisto.network/tx/123");

    auto value5 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeDash, txId));
    assertStringsEqual(value5, "https://live.blockcypher.com/dash/tx/123");

    auto value6 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeEthereumClassic, txId));
    assertStringsEqual(value6, "https://gastracker.io/tx/123");

    auto value7 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeGo, txId));
    assertStringsEqual(value7, "https://explorer.gochain.io/tx/123");

    auto value8 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeICON, txId));
    assertStringsEqual(value8, "https://tracker.icon.foundation/transaction/123");

    auto value9 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeLitecoin, txId));
    assertStringsEqual(value9, "https://blockchair.com/litecoin/transaction/123");

    auto value10 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypePoa, txId));
    assertStringsEqual(value10, "https://poaexplorer.com/txid/search/123");

    auto value11 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeThunderToken, txId));
    assertStringsEqual(value11, "https://scan.thundercore.com/tx/123");

    auto value12 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeTomoChain, txId));
    assertStringsEqual(value12, "https://scan.tomochain.com/txs/123");

    auto value13 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeTron, txId));
    assertStringsEqual(value13, "https://tronscan.org/#/transaction/123");

    auto value14 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeTron, txId));
    assertStringsEqual(value14, "https://tronscan.org/#/transaction/123");

    auto value15 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeVeChain, txId));
    assertStringsEqual(value15, "https://explore.veforge.com/transactions/123");

    auto value16 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeWanChain, txId));
    assertStringsEqual(value16, "https://explorer.wanchain.org/tx/123");

    auto value17 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeZCoin, txId));
    assertStringsEqual(value17, "https://explorer.zcoin.io/tx/123");

    auto value18 = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeBinance, txId));
    assertStringsEqual(value18, "https://binance.com");
}
