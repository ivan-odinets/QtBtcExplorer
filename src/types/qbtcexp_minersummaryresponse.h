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

#ifndef QT_BTCEXPLORER_MINERSUMMARYRESPONSE_H
#define QT_BTCEXPLORER_MINERSUMMARYRESPONSE_H

#include <QStringList>
#include <QMap>

#include "qbtcexp_minersummary.h"
#include "qbtcexp_overallminersummary.h"

namespace QtBtcExplorer {

/*! @class MinerSummaryResponse src/types/qbtcexp_minersummaryresponse.h
 *  @brief Object of this type is returned as reply of API::getMinerSummary method ( /api/mining/miner-summary ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class MinerSummaryResponse
{
public:
    /*! @brief Default constructor. Constructs invalid MinerSummaryResponse object. */
    MinerSummaryResponse();
    MinerSummaryResponse(const QJsonObject& jsonObject);
    MinerSummaryResponse(const QJsonValue& jsonValue) :
        MinerSummaryResponse(jsonValue.toObject()) {}

    /*! @brief Returns true if this MinerSummaryResponse object is containing valid information. MinerSummaryResponse
     *         object is considered to be valid if miners() field is not empty. */
    bool isValid() const                                                  { return !m_miners.isEmpty(); }

    QStringList                   minerNamesSortedByBlockCount() const    { return m_minerNamesSortedByBlockCount; }
    QMap<QString,MinerSummary>    miners() const                          { return m_miners; };
    OverallMinerSummary           overall() const                         { return m_overall; };

private:
    QStringList                   m_minerNamesSortedByBlockCount;
    QMap<QString,MinerSummary>    m_miners;
    OverallMinerSummary           m_overall;
};

inline QDebug operator<< (QDebug dbg, const MinerSummaryResponse& minerSummaryResponse)
{
    dbg.nospace() << qUtf8Printable(QString("MinerSummaryResponse(miners.count()=%1; overall.blockCount()=%2)")
                                    .arg(minerSummaryResponse.miners().count())
                                    .arg(minerSummaryResponse.overall().blockCount()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // MINERSUMMARYRESPONSE_H
