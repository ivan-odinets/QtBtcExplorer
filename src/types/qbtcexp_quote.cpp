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

#include "qbtcexp_quote.h"

namespace QtBtcExplorer {

Quote::Quote() :
    m_quoteIndex(-1)
{}

Quote::Quote(const QJsonObject& jsonObject) :
    m_text(jsonObject.value("text").toString()),
    m_speaker(jsonObject.value("speaker").toString()),
    m_date(QDate::fromString(jsonObject.value("date").toString(),Qt::ISODate)),
    m_context(jsonObject.value("context").toString()),
    m_url(jsonObject.value("url").toString()),
    m_quoteIndex(jsonObject.value("quoteIndex").toInt())
{}

} // namespace QtBtcExplorer
