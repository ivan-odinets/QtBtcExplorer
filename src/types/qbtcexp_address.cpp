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

#include "qbtcexp_address.h"

#include <QJsonArray>

namespace QtBtcExplorer {

Address::Address()
{}

Address::Address(const QJsonObject& jsonObject) :
    m_encoding(jsonObject.value("encoding").toString())
{
    // validateaddress block
    QJsonObject temp = jsonObject.value("validateaddress").toObject();
    m_address = temp.value("address").toString();
    m_scriptPubKey = temp.value("scriptPubKey").toString();
    m_isScript = temp.value("isscript").toBool();
    m_isWintess = temp.value("iswitness").toBool();
    m_witnessVersion = temp.value("witness_version").toInt();
    m_witnessProgram = temp.value("witness_program").toString();

    // txHistory block
    temp = jsonObject.value("txHistory").toObject();
    m_txCount = temp.value("txCount").toDouble();
    for (const QJsonValue& jsonValue : temp.value("txids").toArray())
        m_txIds.append(jsonValue.toString());
    m_balance = Btc(temp.value("balanceSat").toDouble());
}

} // namespace QtBtcExplorer
