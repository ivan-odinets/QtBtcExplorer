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

#include "qbtcexp_btcprice.h"

namespace QtBtcExplorer {

BtcPrice::BtcPrice() :
    m_btcUsd(-1.0),
    m_btcEur(-1.0),
    m_btcGbp(-1.0),
    m_btcXau(-1.0)
{}

BtcPrice::BtcPrice(const QJsonObject& jsonObject) :
    m_btcUsd(jsonObject.value("usd").toString().toDouble()),
    m_btcEur(jsonObject.value("eur").toString().toDouble()),
    m_btcGbp(jsonObject.value("gbp").toString().toDouble()),
    m_btcXau(jsonObject.value("xau").toString().toDouble())
{}

} // namespace QtBtcExplorer
