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

#include "qbtcexp_block.h"

#include <QJsonArray>

namespace QtBtcExplorer {

Block::Block() :
    BlockHeader(),
    m_strippedSize{-1},
    m_size{-1},
    m_weight{-1}
{}

Block::Block(const QJsonObject& jsonObject) :
    BlockHeader{jsonObject},
    m_strippedSize {jsonObject.value("strippedsize").toInt(-1)       },
    m_size         {jsonObject.value("size").toInt(-1)               },
    m_weight       {jsonObject.value("weight").toInt(-1)             },
    m_totalFees    {Btc::fromBtcString(jsonObject.value("totalFees").toString("-1")) },
    m_miner        {jsonObject.value("miner").toObject()             },
    m_subsidy      {Btc::fromBtcString(jsonObject.value("subsidy").toString("-1")) }
{
    QJsonArray txJsonArray = jsonObject.value("tx").toArray();
    for (const QJsonValue& jsonValue : txJsonArray)
        m_tx.append(jsonValue.toString());
}

} // namespace QtBtcExplorer
