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

#ifndef QT_BTCEXPLORER_MINERSUMMARY_H
#define QT_BTCEXPLORER_MINERSUMMARY_H

#include <QJsonObject>
#include <QJsonValue>

#include "qbtcexp_btc.h"

namespace QtBtcExplorer {

/*! @class MinerSummary src/types/qbtcexp_minersummary.h
 *  @brief A map of such objects is present as one of the fields of MinerSummaryResponse, which is returned by
 *         API::getMinerSummary method ( /api/mining/miner-summary ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class MinerSummary
{
public:
    /*! @brief Default constructor. Constructs invalid MinerSummary object. */
    MinerSummary();
    MinerSummary(const QJsonObject& jsonObject);
    MinerSummary(const QJsonValue& jsonValue) :
        MinerSummary(jsonValue.toObject()) {}

    /*! @brief Returns true if this MinerSummary object is containing valid information. MinerSummary object is considered
     *         to be valid if name() field contains non-empty string. */
    bool isValid() const                         { return !m_name.isEmpty(); }

    QString        name() const                  { return m_name; }
    QList<qint32>  blocks() const                { return m_blocks; }
    Btc            totalFees() const             { return m_totalFees; }
    Btc            totalSubsidy() const          { return m_totalSubsidy; }
    qint64         totalTransactions() const     { return m_totalTransactions; }
    qint64         totalWeight() const           { return m_totalWeight; }
    qint32         subsidyCount() const          { return m_subsidyCount; }

private:
    QString        m_name;
    QList<qint32>  m_blocks;
    Btc            m_totalFees;
    Btc            m_totalSubsidy;
    qint64         m_totalTransactions;
    qint64         m_totalWeight;
    qint32         m_subsidyCount;
};

inline QDebug operator<< (QDebug dbg, const MinerSummary& minerSummary)
{
    dbg.nospace() << qUtf8Printable(QString("MinerSummary(name=%1; blocks.count()=%2; totalFees.btc()=%3 BTC)")
                                    .arg(minerSummary.name())
                                    .arg(minerSummary.blocks().count())
                                    .arg(minerSummary.totalFees().btc()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_MINERSUMMARY_H
