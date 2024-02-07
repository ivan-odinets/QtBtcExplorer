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

#ifndef QT_BTCEXPLORER_UTXOSET_H
#define QT_BTCEXPLORER_UTXOSET_H

#include "qbtcexp_utxosetblockinfo.h"

namespace QtBtcExplorer {

/*! @class UtxoSet src/types/qbtcexp_utxoset.h
 *  @brief Object of this class represents reply of API::getUtxoSet method ( /api/blockchain/utxo-set ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class UtxoSet
{
public:
    /*! @brief Default constructor. Constructs invalid UtxoSet object. */
    UtxoSet();
    UtxoSet(const QJsonObject& jsonObject);
    UtxoSet(const QJsonValue& jsonValue) :
        UtxoSet(jsonValue.toObject()) {}

    /*! @brief Returns true if this UtxoSet object is containing valid information. UtxoSet object is considered to be
     *         valid if height() field contains anything but not -1. */
    bool                isValid() const                    { return m_height != -1; }

    qint32              height() const                     { return m_height; }
    QString             bestBlock() const                  { return m_bestBlock; }
    qint64              txouts() const                     { return m_txouts; }
    qint64              bogoSize() const                   { return m_bogoSize; }
    QString             muhash() const                     { return m_muhash; }
    double              totalAmount() const                { return m_totalAmount; }
    double              totalUnspendableAmount() const     { return m_totalUnspendableAmount; }
    UtxoSetBlockInfo    blockInfo() const                  { return m_blockInfo; }
    bool                usingCoinStatsIndex() const        { return m_usingCoinStatsIndex; }
    qint64              lastUpdated() const                { return m_lastUpdated; }

private:
    qint32              m_height;
    QString             m_bestBlock;
    qint64              m_txouts;
    qint64              m_bogoSize;
    QString             m_muhash;
    double              m_totalAmount;
    double              m_totalUnspendableAmount;
    UtxoSetBlockInfo    m_blockInfo;
    bool                m_usingCoinStatsIndex;
    qint64              m_lastUpdated;
};

inline QDebug operator<< (QDebug dbg, const UtxoSet& utxoSet)
{
    dbg.nospace() << qUtf8Printable(QString("UtxoSet(height=%1; bestBlock=%2)")
                                    .arg(utxoSet.height())
                                    .arg(utxoSet.bestBlock()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_UTXOSET_H
