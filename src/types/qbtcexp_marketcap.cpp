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

#include "qbtcexp_marketcap.h"

namespace QtBtcExplorer {

Marketcap::Marketcap() :
    m_usd{-1.0},
    m_eur{-1.0},
    m_gbp{-1.0},
    m_xau{-1.0}
{}

Marketcap::Marketcap(const QJsonObject& jsonObject) :
    m_usd{    jsonObject.value("usd").toDouble(-1.0)  },
    m_eur{    jsonObject.value("eur").toDouble(-1.0)  },
    m_gbp{    jsonObject.value("gbp").toDouble(-1.0)  },
    m_xau{    jsonObject.value("xau").toDouble(-1.0)  }
{}

} // namespace QtBtcExplorer
