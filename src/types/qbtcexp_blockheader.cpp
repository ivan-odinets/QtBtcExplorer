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

#include "qbtcexp_blockheader.h"

namespace QtBtcExplorer {

BlockHeader::BlockHeader() :
    m_confirmations{-1},
    m_height{-1},
    m_version{-1},
    m_time{-1},
    m_medianTime{-1},
    m_nonce{-1},
    m_bits{-1},
    m_difficulty{-1.0},
    m_nTx{-1}
{}

BlockHeader::BlockHeader(const QJsonObject& jsonObject) :
    m_hash              {       jsonObject.value("hash").toString()                   },
    m_confirmations     {       jsonObject.value("confirmations").toInt(-1)           },
    m_height            {       jsonObject.value("height").toInt(-1)                  },
    m_version           {       jsonObject.value("version").toInt(-1)                 },
    m_merkleRoot        {       jsonObject.value("merkleroot").toString()             },
    m_time              {       jsonObject.value("time").toInt(-1)                    },
    m_medianTime        {       jsonObject.value("mediantime").toInt(-1)              },
    m_nonce             {qint64(jsonObject.value("nonce").toDouble(-1.0))             },
    m_bits              {       jsonObject.value("bits").toString().toInt(nullptr,16) },
    m_difficulty        {       jsonObject.value("difficulty").toDouble()             },
    m_chainwork         {       jsonObject.value("chainwork").toString()              },
    m_nTx               {       jsonObject.value("nTx").toInt(-1)                     },
    m_previousBlockHash {       jsonObject.value("previousblockhash").toString()      },
    m_nextBlockHash     {       jsonObject.value("nextblockhash").toString()          }
{}

} // namespace QtBtcExplorer
