// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

const char *explorerURLForCoinType(enum TWCoinType type);

TWString *_Nullable TWCoinTypeConfigurationGetSymbol(enum TWCoinType type) {
    string string;
    switch (type) {
    case TWCoinTypeEthereum: string = "ETH"; break;
    case TWCoinTypeBitcoin: string = "BTC"; break;
    case TWCoinTypeBitcoinCash:  string = "BCH"; break;
    case TWCoinTypeCallisto:  string = "CLO"; break;
    case TWCoinTypeDash:  string = "DASH"; break;
    case TWCoinTypeEthereumClassic:  string = "ETC"; break;
    case TWCoinTypeGo:  string =  "GO"; break;
    case TWCoinTypeICON:  string =  "ICX"; break;
    case TWCoinTypeLitecoin: string = "LTC"; break;
    case TWCoinTypePoa: string = "POA"; break;
    case TWCoinTypeTest: string = "TEST"; break;
    case TWCoinTypeThunderToken: string = "TT"; break;
    case TWCoinTypeTomoChain: string = "TOMO"; break;
    case TWCoinTypeTron: string = "TRX"; break;
    case TWCoinTypeVeChain: string = "VET"; break;
    case TWCoinTypeWanChain: string = "WAN"; break;
    case TWCoinTypeZCoin: string = "XZC"; break;
    case TWCoinTypeBinance: string = "BNB"; break;
    default: string = ""; break;
    }
    return TWStringCreateWithUTF8Bytes(string.c_str());
}

int TWCoinTypeConfigurationGetDecimals(enum TWCoinType type) {
    switch (type) {
    case TWCoinTypeEthereum:
    case TWCoinTypeCallisto:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeICON:
    case TWCoinTypeGo:
    case TWCoinTypePoa:
    case TWCoinTypeThunderToken:
    case TWCoinTypeTomoChain:
    case TWCoinTypeVeChain:
    case TWCoinTypeWanChain:
        return 18;
    case TWCoinTypeBitcoinCash:
    case TWCoinTypeBitcoin:
    case TWCoinTypeDash:
    case TWCoinTypeLitecoin:
    case TWCoinTypeBinance:
    case TWCoinTypeZCoin:
     return 8;
    case TWCoinTypeTron:
        return 6;
    case TWCoinTypeTest:
    default:
        return 0;
    }
}

TWString *_Nullable TWCoinTypeConfigurationGetTransactionURL(enum TWCoinType type, TWString *_Nonnull transactionID) {
    string url = string(explorerURLForCoinType(type));
    string txId = string(TWStringUTF8Bytes(transactionID));
    switch (type) {
    case TWCoinTypeBitcoin:
    case TWCoinTypeBitcoinCash:
    case TWCoinTypeICON:
    case TWCoinTypeLitecoin:
        url += "/transaction/" + txId;
        break;
    case TWCoinTypeEthereum:
    case TWCoinTypeDash:
    case TWCoinTypeCallisto:
    case TWCoinTypeEthereumClassic:
    case TWCoinTypeGo:
    case TWCoinTypeThunderToken:
    case TWCoinTypeWanChain:
    case TWCoinTypeZCoin:
        url += "/tx/" + txId;
        break;
    case TWCoinTypePoa:
        url += "/txid/search/" + txId;
        break;
    case TWCoinTypeTomoChain:
        url += "/txs/" + txId;
        break;
    case TWCoinTypeTron:
        url += "/#/transaction/" + txId;
        break;
    case TWCoinTypeVeChain:
        url += "/transactions/" + txId;
        break;
    case TWCoinTypeBinance: break;
    default: break;
    }
    return TWStringCreateWithUTF8Bytes(url.c_str());
}

const char *explorerURLForCoinType(enum TWCoinType type) {
    switch (type) {
    case TWCoinTypeEthereum: return "https://etherscan.io";
    case TWCoinTypeBitcoin: return "https://blockchair.com/bitcoin";
    case TWCoinTypeBitcoinCash: return "https://blockchair.com/bitcoin-cash";
    case TWCoinTypeCallisto: return "https://explorer2.callisto.network";
    case TWCoinTypeDash: return "https://live.blockcypher.com/dash";
    case TWCoinTypeEthereumClassic: return "https://gastracker.io";
    case TWCoinTypeGo: return "https://explorer.gochain.io";
    case TWCoinTypeICON: return "https://tracker.icon.foundation";
    case TWCoinTypeLitecoin: return "https://blockchair.com/litecoin";
    case TWCoinTypePoa: return "https://poaexplorer.com";
    case TWCoinTypeTest: return "";
    case TWCoinTypeThunderToken: return "https://scan.thundercore.com";
    case TWCoinTypeTomoChain: return "https://scan.tomochain.com";
    case TWCoinTypeTron: return "https://tronscan.org";
    case TWCoinTypeVeChain: return "https://explore.veforge.com";
    case TWCoinTypeWanChain: return "https://explorer.wanchain.org";
    case TWCoinTypeZCoin: return "https://explorer.zcoin.io";
    case TWCoinTypeBinance: return "https://binance.com";
    default: return "";
    }
}