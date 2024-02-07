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

#include "qbtcexp_utxounspendables.h"

namespace QtBtcExplorer {

UtxoUnspendables::UtxoUnspendables() :
    m_genesisBlock{-1},
    m_bip30{-1},
    m_scripts{-1},
    m_unclaimedRewards{-1}
{}

UtxoUnspendables::UtxoUnspendables(const QJsonObject& jsonObject) :
    m_genesisBlock{jsonObject.value("genesis_block").toInt(-1)},
    m_bip30{jsonObject.value("bip30").toInt(-1)},
    m_scripts{jsonObject.value("scripts").toInt(-1)},
    m_unclaimedRewards{jsonObject.value("unclaimed_rewards").toInt(-1)}
{}

} // namespace QtBtcExplorer
