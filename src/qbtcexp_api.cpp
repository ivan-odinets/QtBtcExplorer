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

#include "qbtcexp_api.h"

#include <QJsonDocument>

namespace QtBtcExplorer {

API::API(QObject* parent) :
    QObject{parent},
    m_errorCode(API::NoError)
{}

/*
 **********************************************************************************************************************
 *
 *                                         Implementation of API methods
 *
 */

Block API::getBlockByHash(const QString& hash)
{
    return _makeApiCall<Block>("/block/" + hash);
}

Block API::getBlockByHeight(qint32 height)
{
    return _makeApiCall<Block>("/block/" + QString::number(height));
}

BlockHeader API::getBlockHeaderByHash(const QString& hash)
{
    return _makeApiCall<BlockHeader>("/block/header/" + hash);
}

BlockHeader API::getBlockHeaderByHeight(qint32 height)
{
    return _makeApiCall<BlockHeader>("/block/header/"+QString::number(height));
}

ChainTip API::getChainTip()
{
    return _makeApiCall<ChainTip>("/blocks/tip");
}

Transaction API::getTransactionById(const QString& txID)
{
    return _makeApiCall<Transaction>("/tx/" + txID);
}

qint64 API::getTransactionVolume24h()
{
    QJsonDocument jsonDocument(QJsonDocument::fromJson(m_net.get("/tx/volume/24h")));
    if (jsonDocument.isNull() || jsonDocument.isEmpty()) {
        m_errorCode = NetworkError;
        return -1;
    }

    if (jsonDocument.isArray()) {
        m_errorCode = UnknownError;
        return -1;
    }

    QJsonObject replyObject = jsonDocument.object();
    m_errorCode = _getErrorCode(replyObject);
    return (m_errorCode == NoError) ? replyObject.value("24h").toInt(-1) : -1;
}

BtcSupply API::getCoins()
{
    return _makeApiCall<BtcSupply>("/blockchain/coins");
}

UtxoSet API::getUtxoSet()
{
    return _makeApiCall<UtxoSet>("/blockchain/utxo-set");
}

NextHalving API::nextHalving()
{
    return _makeApiCall<NextHalving>("/blockchain/next-halving");
}

Address API::getAddress(const QString& btcAddress)
{
    return _makeApiCall<Address>("/address/" + btcAddress);
}

PublicKeyDetails API::getPublicKeyDetails(const QString& xpub)
{
    return _makeApiCall<PublicKeyDetails>("/xyzpub/" + xpub);
}

QStringList API::getAddressesByPublicKey(const QString& xpub)
{
    return _getStringList("/xyzpub/addresses/" + xpub);
}

TxIdList API::getTransactionsByPublicKey(const QString& xpub)
{
    return _makeApiCall<TxIdList>("/xyzpub/txids/" + xpub);
}

HashrateResponse API::getHashrate()
{
    return _makeApiCall<HashrateResponse>("/mining/hashrate");
}

double API::getDifficultyAdjustmentEstimate()
{
    QString resultString = m_net.get("/mining/diff-adj-estimate");
    m_errorCode = (resultString.isEmpty()) ? API::NetworkError : API::NoError;
    bool ok = false;
    double result = resultString.toDouble(&ok);
    return (ok) ? result : -1.0;
}

NextBlock API::getNextBlock()
{
    return _makeApiCall<NextBlock>("/mining/next-block");
}

QStringList API::getNextBlockTxIds()
{
    return _getStringList("/mining/next-block/txids");
}

TransactionInclusionStatus API::isTxIncluded(const QString& txId)
{
    return _makeApiCall<TransactionInclusionStatus>("/mining/next-block/includes/" + txId);
}

MinerSummaryResponse API::getMinerSummary()
{
    return _makeApiCall<MinerSummaryResponse>("/mining/miner-summary?since=1d");
}

MempoolSummary API::mempoolSummary()
{
    return _makeApiCall<MempoolSummary>("/mempool/summary");
}

MempoolFees API::mempoolFees()
{
    return _makeApiCall<MempoolFees>("/mempool/fees");
}

BtcPrice API::price()
{
    return _makeApiCall<BtcPrice>("/price");
}

Marketcap API::marketcap()
{
    return _makeApiCall<Marketcap>("/price/marketcap");
}

Sats API::sats()
{
    return _makeApiCall<Sats>("/price/sats");
}

QuoteList API::allQuotes()
{
    return _makeApiCall<QuoteList>("/quotes/all");
}

Quote API::randomQuote()
{
    return _makeApiCall<Quote>("/quotes/random");
}

Quote API::quote(int index)
{
    return _makeApiCall<Quote>("/quotes/" + QString::number(index));
}

HolidayList API::allHolidays()
{
    return _makeApiCall<HolidayList>("/holidays/all");
}

HolidayAtDate API::getTodayHoliday()
{
    return _makeApiCall<HolidayAtDate>("/holidays/today");
}

HolidayAtDate API::getHoliday(const QDate& date)
{
    return _makeApiCall<HolidayAtDate>("/holidays/" + date.toString(Qt::ISODate));
}

QString API::version()
{
    QString result = m_net.get("/version");
    m_errorCode = (result.isEmpty()) ? API::NetworkError : API::NoError;
    return result;
}

/*
 **********************************************************************************************************************
 *
 *                                                  Service methods
 *
 */

API::Error API::_getErrorCode(const QJsonObject& jsonObject)
{
    if (jsonObject.isEmpty())
        return API::NetworkError;

    if (jsonObject.contains("error"))
        return API::UnknownError;

    return API::NoError;
}

QStringList API::_getStringList(const QString& request)
{
    QJsonDocument jsonDocument(QJsonDocument::fromJson(m_net.get(request)));
    if (jsonDocument.isNull() || jsonDocument.isEmpty()) {
        m_errorCode = NetworkError;
        return QStringList();
    }

    if (jsonDocument.isObject()) {
        m_errorCode = _getErrorCode(jsonDocument.object());
        return QStringList();
    }

    QStringList result;
    for (const QJsonValue& jsonValue : jsonDocument.array())
        result.append(jsonValue.toString());
    return result;
}

template<class C>
C API::_makeApiCall(const QString& query)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(m_net.get(query));

    if (jsonDocument.isEmpty() || jsonDocument.isNull()) {
        m_errorCode = NetworkError;
        return C();
    }

    if (jsonDocument.isArray()) {
        m_errorCode = NoError;
        return C(jsonDocument.array());
    }

    if (jsonDocument.isObject()) {
        QJsonObject jsonObject = jsonDocument.object();
        m_errorCode = _getErrorCode(jsonObject);
        return (m_errorCode == NoError) ? C(jsonObject) : C();
    }

    m_errorCode = UnknownError;
    return C();
}

} // namespace QtBtcExplorer
