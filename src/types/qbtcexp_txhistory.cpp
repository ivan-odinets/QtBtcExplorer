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

#include "qbtcexp_txhistory.h"

#include <QJsonArray>

namespace QtBtcExplorer {

TxHistory::TxHistory()
{}

TxHistory::TxHistory(const QJsonObject& jsonObject) :
    m_txCount{qint64(jsonObject.value("txCount").toDouble(-1.0))},
    m_balance{Btc(jsonObject.value("balanceSat").toDouble(-1))},
    m_request{jsonObject.value("request").toObject()}
{
    for (const QJsonValue& jsonValue : jsonObject.value("txids").toArray())
        m_txIds.append(jsonValue.toString());

    QJsonObject blockHeightsByTxidJsonObject = jsonObject.value("blockHeightsByTxid").toObject();
    for (const QString& txId : m_txIds)
        m_blockHeightsByTxid.insert(txId,blockHeightsByTxidJsonObject.value(txId).toDouble(-1.0));
}

} // namespace QtBtcExplorer
