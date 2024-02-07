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

#ifndef QT_BTCEXPLORER_TRANSACTION_H
#define QT_BTCEXPLORER_TRANSACTION_H

#include <QJsonObject>
#include <QJsonValue>

#include "qbtcexp_btc.h"

namespace QtBtcExplorer {

/*! @class Transaction src/types/qtbtcexp_transaction.h
 *  @brief Object of this class represents reply of API::getTransactionById method ( /api/tx/$TXID ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Transaction
{
public:
    /*! @brief Default constructor. Constructs invalid Transaction object. */
    Transaction();
    Transaction(const QJsonObject& jsonObject);
    Transaction(const QJsonValue& jsonValue) :
        Transaction(jsonValue.toObject()) {}

    /*! @brief Returns true if this Transaction object is containing valid information. Transaction object is considered
     *         to be valid if hash() field contains non-empty string. */
    bool      isValid() const          { return !m_hash.isEmpty(); }

    QString   txId() const             { return m_txId; }
    QString   hash() const             { return m_hash; }
    qint32    version() const          { return m_version; }
    qint32    size() const             { return m_size; }
    qint32    vsize() const            { return m_vsize; }
    qint32    weight() const           { return m_weight; }
    qint32    locktime() const         { return m_locktime; }
    QString   hex() const              { return m_hex; }
    QString   blockHash() const        { return m_blockHash; }
    qint32    confirmations() const    { return m_confirmations; }
    qint64    time() const             { return m_time; }
    qint64    blockTime() const        { return m_blockTime; }
    double    fee() const              { return m_fee; }
    Btc       feeBtc() const           { return Btc::fromBtcDouble(m_fee); }
    QString   feeUnitString() const    { return m_feeUnitString; }

private:
    QString   m_txId;
    QString   m_hash;
    qint32    m_version;
    qint32    m_size;
    qint32    m_vsize;
    qint32    m_weight;
    qint32    m_locktime;
    QString   m_hex;
    QString   m_blockHash;
    qint32    m_confirmations;
    qint64    m_time;
    qint64    m_blockTime;
    double    m_fee;
    QString   m_feeUnitString;
};

inline QDebug operator<< (QDebug dbg, const Transaction& transaction)
{
    dbg.nospace() << qUtf8Printable(QString("Transaction(txId=%1; hash=%2)")
                                    .arg(transaction.txId())
                                    .arg(transaction.hash()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_TRANSACTION_H
