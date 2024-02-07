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

#include "qbtcexp_nexthalving.h"

namespace QtBtcExplorer {

NextHalving::NextHalving() :
    m_nextHalvingIndex{-1},
    m_nextHalvingBlock{-1},
    m_nextHalvingSubsidy{-1.0},
    m_blocksUntilNextHalving{-1}
{}

NextHalving::NextHalving(const QJsonObject& jsonObject) :
    m_nextHalvingIndex            {jsonObject.value("nextHalvingIndex").toInt(-1)                                 },
    m_nextHalvingBlock            {jsonObject.value("nextHalvingBlock").toInt(-1)                                 },
    m_nextHalvingSubsidy          {jsonObject.value("nextHalvingSubsidy").toString("-1").toDouble()               },
    m_blocksUntilNextHalving      {jsonObject.value("blocksUntilNextHalving").toInt(-1)                           },
    m_timeUntilNextHalving        {jsonObject.value("timeUntilNextHalving").toString()                            },
    m_nextHalvingEstimatedDate    {QDateTime::fromString(jsonObject.value("nextHalvingEstimatedDate").toString(),
                                                         Qt::ISODateWithMs)                                       }
{}

} // namespace QtBtcExplorer
