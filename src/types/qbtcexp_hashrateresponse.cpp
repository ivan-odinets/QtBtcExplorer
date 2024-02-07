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

#include "qbtcexp_hashrateresponse.h"

namespace QtBtcExplorer {

Hashrate::Hashrate() :
    m_value             {-1.0},
    m_unitExponent      {-1},
    m_unitMultiplier    {-1},
    m_raw               {-1.0}
{}

Hashrate::Hashrate(const QJsonObject& jsonObject) :
    m_value                  {       jsonObject.value("val").toDouble()                       },
    m_unitString             {       jsonObject.value("unit").toString()                      },
    m_unitAbbreviationString {       jsonObject.value("unitAbbreviation").toString()          },
    m_unitExponent           {qint16(jsonObject.value("unitExponent").toString("-1").toInt()) },
    m_unitMultiplier         {qint64(jsonObject.value("unitMultiplier").toDouble(-1.0))       },
    m_raw                    {       jsonObject.value("raw").toDouble(-1.0)                   },
    m_stringOne              {       jsonObject.value("string1").toString()                   },
    m_stringTwo              {       jsonObject.value("string2").toString()                   },
    m_stringThree            {       jsonObject.value("string3").toString()                   }
{}

HashrateResponse::HashrateResponse()
{}

HashrateResponse::HashrateResponse(const QJsonObject& jsonObject) :
    m_day          {jsonObject.value("1Day").toObject()    },
    m_week         {jsonObject.value("7Day").toObject()    },
    m_mounth       {jsonObject.value("30Day").toObject()   },
    m_threeMounth  {jsonObject.value("90day").toObject()   },
    m_year         {jsonObject.value("365Day").toObject()  }
{}

} // namespace QtBtcExplorer
