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

#include "qbtcexp_utxoset.h"

namespace QtBtcExplorer {

UtxoSet::UtxoSet() :
    m_height{-1},
    m_txouts{-1},
    m_bogoSize{-1},
    m_totalAmount{-1.0},
    m_totalUnspendableAmount{-1.0},
    m_usingCoinStatsIndex{false},
    m_lastUpdated{-1}
{}

UtxoSet::UtxoSet(const QJsonObject& jsonObject) :
    m_height                 {       jsonObject.value("height").toInt(-1)                          },
    m_bestBlock              {       jsonObject.value("bestblock").toString()                      },
    m_txouts                 {qint64(jsonObject.value("txouts").toDouble(-1.0))                    },
    m_bogoSize               {qint64(jsonObject.value("bogosize").toDouble(-1.0))                  },
    m_muhash                 {       jsonObject.value("muhash").toString()                         },
    m_totalAmount            {       jsonObject.value("total_amount").toDouble(-1.0)               },
    m_totalUnspendableAmount {       jsonObject.value("total_unspendable_amount").toDouble(-1.0)   },
    m_blockInfo              {       jsonObject.value("block_info").toObject()                     },
    m_usingCoinStatsIndex    {       jsonObject.value("usingCoinStatsIndex").toBool(false)         },
    m_lastUpdated            {qint64(jsonObject.value("lastUpdated").toDouble(-1.0))               }
{}

} // namespace QtBtcExplorer
