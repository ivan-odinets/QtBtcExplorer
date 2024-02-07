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

#include "qbtcexp_transaction.h"

namespace QtBtcExplorer {

Transaction::Transaction() :
    m_version{-1},
    m_size{-1},
    m_vsize{-1},
    m_weight{-1},
    m_locktime{-1},
    m_confirmations{-1},
    m_time{-1},
    m_blockTime{-1}
{}

Transaction::Transaction(const QJsonObject& jsonObject) :
    m_txId                {       jsonObject.value("txid").toString()               },
    m_hash                {       jsonObject.value("hash").toString()               },
    m_version             {       jsonObject.value("version").toInt(-1)             },
    m_size                {       jsonObject.value("size").toInt(-1)                },
    m_vsize               {       jsonObject.value("vsize").toInt(-1)               },
    m_weight              {       jsonObject.value("weight").toInt(-1)              },
    m_locktime            {       jsonObject.value("locktime").toInt(-1)            },
    m_hex                 {       jsonObject.value("hex").toString()                },
    m_blockHash           {       jsonObject.value("blockhash").toString()          },
    m_confirmations       {       jsonObject.value("confirmations").toInt(-1)       },
    m_time                {qint64(jsonObject.value("time").toDouble(-1.0))          },
    m_blockTime           {qint64(jsonObject.value("blocktime").toDouble(-1.0))     }
{
    QJsonObject feeJsonObject = jsonObject.value("fee").toObject();
    m_feeUnitString = feeJsonObject.value("unit").toString();
    m_fee = feeJsonObject.value("amount").toDouble(-1);
}

} // namespace QtBtcExplorer
