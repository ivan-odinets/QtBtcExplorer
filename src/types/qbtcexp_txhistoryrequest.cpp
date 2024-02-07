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

#include "qbtcexp_txhistoryrequest.h"

namespace QtBtcExplorer {

TxHistoryRequest::TxHistoryRequest() :
    m_limit{-1},
    m_offset{-1},
    m_sort{Unknown}
{}

TxHistoryRequest::TxHistoryRequest(const QJsonObject& jsonObject) :
    m_limit   {             jsonObject.value("limit").toInt(-1)      },
    m_offset  {             jsonObject.value("offset").toInt(-1)     },
    m_sort    {stringToSort(jsonObject.value("sort").toString())     }
{}

} // namespace QtBtcExplorer
