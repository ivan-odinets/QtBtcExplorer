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

#ifndef QT_BTCEXPLORER_TXHISTORY_H
#define QT_BTCEXPLORER_TXHISTORY_H

#include <QJsonObject>
#include <QJsonValue>
#include <QMap>

#include "qbtcexp_btc.h"
#include "qbtcexp_txhistoryrequest.h"

namespace QtBtcExplorer {

/*! @class TxHistory src/types/qbtcexp_txhistory.h
 *  @brief Object of this type is contained as one of the fields of reply of API::getAddress method (see Address).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class TxHistory
{
public:
    /*! @brief Default constructor. Constructs invalid TxHistory object. */
    TxHistory();
    TxHistory(const QJsonObject& jsonValue);
    TxHistory(const QJsonValue& jsonValue) :
        TxHistory(jsonValue.toObject()) {}

    /*! @brief Returns true if this TxHistory object contains valid information. TxHistory object is considered
     *         valid if txCOunt() returns anything but not -1 and if balance() is valid (see Btc::isValid). */
    bool           isValid() const     { return (m_txCount != -1) && (m_balance.isValid()); }

    qint64         txCount() const     { return m_txCount; }
    QStringList    txIds() const       { return m_txIds; }
    Btc            balance() const     { return m_balance; }
    qint64         balanceSat() const  { return m_balance.satoshi(); }

    QMap<QString,qint64>     blockHeightsByTxId() const    { return m_blockHeightsByTxid; }
    bool           containsTxId(const QString& txId) const { return m_blockHeightsByTxid.contains(txId); }
    qint64         blockHeightByTxId(const QString& txId)  { return m_blockHeightsByTxid.value(txId); }

    TxHistoryRequest request() const { return m_request; }

private:
    qint64         m_txCount;
    QStringList    m_txIds;
    Btc            m_balance;
    QMap<QString,qint64>     m_blockHeightsByTxid;
    TxHistoryRequest    m_request;
};

inline QDebug operator<< (QDebug dbg, const TxHistory& txHistory)
{
    dbg.nospace() << qUtf8Printable(QString("TxHistory(txCount=%1; balance=%2 BTC)")
                                    .arg(txHistory.txCount())
                                    .arg(txHistory.balance().btc()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // TXHISTORY_H
