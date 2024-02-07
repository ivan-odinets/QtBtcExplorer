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

#include "qbtcexp_mempoolfees.h"

namespace QtBtcExplorer {

MempoolFees::MempoolFees() :
    m_nextBlockSmart{-1},
    m_nextBlockMin{-1},
    m_nextBlockMax{-1},
    m_nextBlockMedian{-1},
    m_30min{-1},
    m_60min{-1},
    m_1day{-1}
{}

MempoolFees::MempoolFees(const QJsonObject& jsonObject) :
    m_30min{jsonObject.value("30min").toInt(-1)},
    m_60min{jsonObject.value("60min").toInt(-1)},
    m_1day{jsonObject.value("1day").toInt(-1)}
{
    QJsonObject nextBlock =  jsonObject.value("nextBlock").toObject();
    m_nextBlockSmart =       nextBlock.value("smart").toInt(-1);
    m_nextBlockMin =         nextBlock.value("min").toInt(-1);
    m_nextBlockMax =         nextBlock.value("max").toInt(-1);
    m_nextBlockMedian =      nextBlock.value("median").toInt(-1);
}

} // namespace QtBtcExplorer
