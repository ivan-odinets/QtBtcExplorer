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

#include "qbtcexp_overallminersummary.h"

namespace QtBtcExplorer {

OverallMinerSummary::OverallMinerSummary() :
    m_blockCount{-1},
    m_totalTransactions{-1},
    m_totalWeight{-1},
    m_subsidyCount{-1}
{}

OverallMinerSummary::OverallMinerSummary(const QJsonObject& jsonObject) :
    m_blockCount        {       jsonObject.value("blockCount").toInt(-1)                 },
    m_totalFees         {Btc::fromBtcString(jsonObject.value("totalFees").toString())    },
    m_totalSubsidy      {Btc::fromBtcString(jsonObject.value("totalSubsidy").toString()) },
    m_totalTransactions {qint64(jsonObject.value("totalTransactions").toDouble(-1.0))    },
    m_totalWeight       {qint64(jsonObject.value("totalWeight").toDouble(-1.0))          },
    m_subsidyCount      {       jsonObject.value("subsidyCount").toInt(-1)               }
{}

} // namespace QtBtcExplorer
