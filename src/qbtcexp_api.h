/*
 **********************************************************************************************************************
 *
 * QtBtcExplorer
 * Copyright (C) 2024 Ivan Odinets <i_odinets@protonmail.com>
 *
 * This file is part of QtBtcExplorer
 *
 * QtBtcExplorer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * QtBtcExplorer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with QtBtcExplorer; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef QT_BTCEXPLORER_API_H
#define QT_BTCEXPLORER_API_H

#include <QObject>

#include "qbtcexp_networking.h"

#include "./src/types/qbtcexp_address.h"
#include "./src/types/qbtcexp_block.h"
#include "./src/types/qbtcexp_blockheader.h"
#include "./src/types/qbtcexp_btcprice.h"
#include "./src/types/qbtcexp_btcsupply.h"
#include "./src/types/qbtcexp_chaintip.h"
#include "./src/types/qbtcexp_hashrateresponse.h"
#include "./src/types/qbtcexp_holiday.h"
#include "./src/types/qbtcexp_holidayatdate.h"
#include "./src/types/qbtcexp_marketcap.h"
#include "./src/types/qbtcexp_mempoolfees.h"
#include "./src/types/qbtcexp_mempoolsummary.h"
#include "./src/types/qbtcexp_minersummaryresponse.h"
#include "./src/types/qbtcexp_nextblock.h"
#include "./src/types/qbtcexp_nexthalving.h"
#include "./src/types/qbtcexp_publickeydetails.h"
#include "./src/types/qbtcexp_sats.h"
#include "./src/types/qbtcexp_transaction.h"
#include "./src/types/qbtcexp_transactioninclusionstatus.h"
#include "./src/types/qbtcexp_txidlist.h"
#include "./src/types/qbtcexp_quote.h"
#include "./src/types/qbtcexp_utxoset.h"

namespace QtBtcExplorer {

/*! @class API "QtBtcExplorer.h"
 *  @brief API class provides interface to communicate with btc-rpc-explorer server
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class API : public QObject
{
public:
    /*! @brief This enum holds information about what exactly error happened */
    enum Error {
        NoError,                       /*!< @brief If the request was successfull */
        NetworkError,                  /*!< @brief If during request some networking error happened */
        UnknownError                   /*!< @brief Corresponds to any other error which have happened */
    };

    explicit API(QObject* parent = nullptr);
    ~API() {}

    /*! @brief This method can be used to setup btc-rpc-explorer server address. If nothing was setup manualy by user -
     *         default server will be used (https://bitcoinexplorer.org/) */
    void      setApiHost(const QString& newHost)      { m_net.setApiHost(newHost); }

    /*! @brief This method returns btc-rpc-explorer server address with which this API object is communicating. */
    QString   apiHost() const                         { return m_net.apiHost(); }

    /*! @brief This method can be used to configure proxy, through which communication with btc-rpc-explorer server will
     *         be done
     *  @param QNetworkProxy newProxy - new proxy configuration */
    void           setProxy(const QNetworkProxy& newProxy) { m_net.setProxy(newProxy); }

    /*! @brief This method can be used to get information about currently configured proxy.
     *  @return QNetworkProxy object, representing current proxy configuration */
    QNetworkProxy  proxy() const                           { return m_net.proxy(); }

    /*! @brief This method allows to setup a timeout for requests to btc-rpc-explorer server.
     *  @param quint32 timeout (in mseconds) after which request will be aborted. Pass 0 to disable timeout */
    void           setRequestTimeout(quint32 msec)         { m_net.setRequestTimeout(msec); }

    /*! @brief This method returns information about timeout */
    quint32        requestTimeout() const                  { return m_net.requestTimeout(); }

    /*! @brief This method can be used to get information about errors.
     *  @details If the last request to btc-rpc-explorer server failed due to whatever reason - this method should return
     *           value from enum QtBtcEcplorer::API::Error which is representing occured error. If the last request was
     *           successfull - this method should return QtBtcExplorer::API::NoError value. */
    Error          errorCode() const                       { return m_errorCode; }

    /// @name Implemented API methods
    /// @{

    /*! @brief Returns the details of the block with the given hash.
     * @see https://bitcoinexplorer.org/api/docs */
    Block getBlockByHash(const QString& hash);

    /*! @brief Returns the details of the block at the given height.
     * @see https://bitcoinexplorer.org/api/docs */
    Block getBlockByHeight(qint32 height);

    /*! @brief Returns the details of the block header with the given hash.
     * @see https://bitcoinexplorer.org/api/docs */
    BlockHeader getBlockHeaderByHash(const QString& hash);

    /*! @brief Returns the details of the block header at the given height.
     * @see https://bitcoinexplorer.org/api/docs */
    BlockHeader getBlockHeaderByHeight(qint32 height);

    /*! @brief Returns basic details about the chain tip.
     * @see https://bitcoinexplorer.org/api/docs */
    ChainTip getChainTip();

    /*! @brief Returns the details of the transaction with the given txid.
     * @see https://bitcoinexplorer.org/api/docs */
    Transaction getTransactionById(const QString& txID);

    /*! @brief Returns total output of all transactions over the last 24hrs.
     * @see https://bitcoinexplorer.org/api/docs */
    qint64 getTransactionVolume24h();

    /*! @brief Returns the current supply of Bitcoin. An estimate using a checkpoint can be returned in 2 cases: on 'slow'
     *         devices, and before the UTXO Set snapshot is loaded.
     * @see https://bitcoinexplorer.org/api/docs */
    BtcSupply getCoins();

    /*! @brief Returns the latest UTXO Set snapshot.
     *  @details Warning: This call can be very s-low, depending on node hardware and index configurations.
     * @see https://bitcoinexplorer.org/api/docs */
    UtxoSet getUtxoSet();

    /*! @brief Returns details about the next, upcoming halving.
     * @see https://bitcoinexplorer.org/api/docs */
    NextHalving nextHalving();

    /*! @brief Returns a summary of data pertaining to the given address.
     *  @details The output of this call will depend heavily on the configured '%Address %API' (see .env-sample file).
     *           If an %Address %API is configured, transactions related to the given address will be returned (the below
     *           optional parameters apply to those transactions).
     * @see https://bitcoinexplorer.org/api/docs */
    Address getAddress(const QString& btcAddress);

    /*! @brief Returns details for the specified extended public key, including related keys and addresses.
     * @see https://bitcoinexplorer.org/api/docs */
    PublicKeyDetails getPublicKeyDetails(const QString& xpub);

    /*! @brief Returns a list of addresses derived from the given [xyz]pub.
     * @see https://bitcoinexplorer.org/api/docs */
    QStringList getAddressesByPublicKey(const QString& xpub);

    /*! @brief Returns a list of transaction IDs associated with the given [xyz]pub.
     * @see https://bitcoinexplorer.org/api/docs */
    TxIdList getTransactionsByPublicKey(const QString& xpub);

    /*! @brief Returns the network hash rate, estimated over the last 1, 7, 30, 90, and 365 days.
     * @see https://bitcoinexplorer.org/api/docs */
    HashrateResponse getHashrate();

    /*! @brief Returns the current estimate for the next difficulty adjustment as a percentage.
     * @see https://bitcoinexplorer.org/api/docs */
    double getDifficultyAdjustmentEstimate();

    /*! @brief Returns a summary for the estimated next block to be mined (produced via getblocktemplate).
     * @see https://bitcoinexplorer.org/api/docs */
    NextBlock getNextBlock();

    /*! @brief Returns a list of the transaction IDs included in the estimated next block to be mined (produced via
     *         getblocktemplate).
     * @see https://bitcoinexplorer.org/api/docs */
    QStringList getNextBlockTxIds();

    /*! @brief Returns whether the specified transaction ID is included in the estimated next block to be mined (produced
     *         via getblocktemplate).
     * @see https://bitcoinexplorer.org/api/docs */
    TransactionInclusionStatus isTxIncluded(const QString& txId);

    /*! @see https://bitcoinexplorer.org/api/docs */
    MinerSummaryResponse getMinerSummary();

    /*! @brief Returns a summary of Bitcoin Core's mempool (full output from 'getmempoolinfo')
     *  @see https://bitcoinexplorer.org/api/docs */
    MempoolSummary mempoolSummary();

    /*! @brief Returns recommended fee rates in sats/vB for next block, ~30 min, 1 hr, and 1 day.
     *  @see https://bitcoinexplorer.org/api/docs */
    MempoolFees mempoolFees();

    /*! @brief Returns the price of 1 BTC, in USD, EUR, GBP, and XAU
     * @see https://bitcoinexplorer.org/api/docs */
    BtcPrice price();

    /*! @brief Returns the market cap of Bitcoin, in USD, EUR, GBP, XAU
     *
     * @see https://bitcoinexplorer.org/api/docs */
    Marketcap marketcap();

    /*! @brief Returns the price of 1 unit of [USD, EUR, GBP, XAU] (e.g. 1 "usd") in satoshis
     * @see https://bitcoinexplorer.org/api/docs */
    Sats sats();

    /*! @brief Returns the full curated list of Bitcoin quotes.
     * @see https://bitcoinexplorer.org/api/docs */
    QuoteList allQuotes();

    /*! @brief Returns the Bitcoin quote with the given index from the curated list.
     * @see https://bitcoinexplorer.org/api/docs */
    Quote quote(int index);

    /*! @brief Returns a random Bitcoin quote from the curated list.
     * @see https://bitcoinexplorer.org/api/docs */
    Quote randomQuote();

    /*! @brief Returns the full curated list of Bitcoin Holidays.
     * @see https://bitcoinexplorer.org/api/docs */
    HolidayList allHolidays();

    /*! @brief Returns the Bitcoin Holidays celebrated 'today' (i.e. at the time the API call is made).
     * @see https://bitcoinexplorer.org/api/docs */
    HolidayAtDate getTodayHoliday();

    /*! @brief Returns the Bitcoin Holidays celebrated on the specified day, using one of the following formats:
     *         yyyy-MM-DD, MM-DD.
     * @see https://bitcoinexplorer.org/api/docs */
    HolidayAtDate getHoliday(const QDate& date);

    /*! @brief Returns the semantic version of the public API, which is maintained separate from the app version.
     * @see https://bitcoinexplorer.org/api/docs */
    QString version();

    /// @}

private:
    Networking m_net;
    Error      m_errorCode;
    Error      _getErrorCode(const QJsonObject& jsonObject);


    QStringList _getStringList(const QString& request);
    template<class C>
    C _makeApiCall(const QString& query);
};

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_API_H
