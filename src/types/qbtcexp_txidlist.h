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

#ifndef QT_BTCEXPLORER_TXIDLIST_H
#define QT_BTCEXPLORER_TXIDLIST_H

#include <QJsonObject>
#include <QJsonValue>
#include <QStringList>

namespace QtBtcExplorer {

/*! @class TxIdList src/types/qbtcexp_txidlist.h
 *  @brief Object of this class represents reply of API::getTransactionsByPublicKey method ( /api/xyzpub/txids/ ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class TxIdList
{
public:
    /*! @brief Default constructor. Constructs invalid UtxoSet object. */
    TxIdList();
    TxIdList(const QJsonObject& jsonObject);
    TxIdList(const QJsonValue& jsonValue) :
        TxIdList(jsonValue.toObject()) {}

    /*! @brief Returns true if this TxIdList object is containing valid information. TxIdList object is considered to be
     *         valid if txCount() field contains anything but not -1. */
    bool isValid() const { return m_txCount != -1; }

    qint32         txCount() const     { return m_txCount; }
    QStringList    txIds() const       { return m_txIds; }

private:
    qint32         m_txCount;
    QStringList    m_txIds;
};

inline QDebug operator<< (QDebug dbg, const TxIdList& txHistory)
{
    dbg.nospace() << qUtf8Printable(QString("TxIdList(txCount=%1)")
                                    .arg(txHistory.txCount()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_TXIDLIST_H
