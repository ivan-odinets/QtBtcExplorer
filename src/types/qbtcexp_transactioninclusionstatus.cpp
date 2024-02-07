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

#include "qbtcexp_transactioninclusionstatus.h"

namespace QtBtcExplorer {

TransactionInclusionStatus::TransactionInclusionStatus() :
    m_included{false},
    m_index{-1},
    m_txCount{-1}
{}

TransactionInclusionStatus::TransactionInclusionStatus(const QJsonObject& jsonObject) :
    m_included{jsonObject.value("included").toBool(false)  },
    m_index   {jsonObject.value("index").toInt(-1)         },
    m_txCount {jsonObject.value("txCount").toInt(-1)       }
{}

} // namespace QtBtcExplorer
