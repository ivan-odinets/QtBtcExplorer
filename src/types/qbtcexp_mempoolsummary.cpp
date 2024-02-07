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

#include "qbtcexp_mempoolsummary.h"

namespace QtBtcExplorer {

MempoolSummary::MempoolSummary() :
    m_loaded                 {false},
    m_size                   {-1},
    m_bytes                  {-1},
    m_usage                  {-1},
    m_totalFee               {-1.0},
    m_maxMempool             {-1},
    m_mempoolminfee          {-1.0},
    m_minrelaytxfee          {-1.0},
    m_incrementalrelayfee    {-1.0},
    m_unbroadcastcount       {-1},
    m_fullrbf                {false}
{}

MempoolSummary::MempoolSummary(const QJsonObject& jsonObject) :
    m_loaded                 {       jsonObject.value("loaded").toBool()                 },
    m_size                   {       jsonObject.value("size").toInt()                    },
    m_bytes                  {qint64(jsonObject.value("bytes").toDouble())               },
    m_usage                  {qint64(jsonObject.value("usage").toDouble())               },
    m_totalFee               {       jsonObject.value("total_fee").toDouble()            },
    m_maxMempool             {qint64(jsonObject.value("maxmempool").toDouble())          },
    m_mempoolminfee          {       jsonObject.value("mempoolminfee").toDouble()        },
    m_minrelaytxfee          {       jsonObject.value("minrelaytxfee").toDouble()        },
    m_incrementalrelayfee    {       jsonObject.value("incrementalrelayfee").toDouble()  },
    m_unbroadcastcount       {qint32(jsonObject.value("unbroadcastcount").toDouble())    },
    m_fullrbf                {       jsonObject.value("fullrbf").toBool()                }
{}

} // namespace QtBtcExplorer
