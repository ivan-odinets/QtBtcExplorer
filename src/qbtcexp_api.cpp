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

#include "qbtcexp_api.h"

#include <QJsonDocument>

namespace QtBtcExplorer {

API::API(QObject* parent) :
    QObject{parent},
    m_errorCode(API::NoError)
{}

Address API::getAddress(const QString& btcAddress)
{
    return makeApiCall<Address>("/address/" + btcAddress);
}

BtcPrice API::price()
{
    return makeApiCall<BtcPrice>("/price");
}

QuoteList API::allQuotes()
{
    return makeApiCall<QuoteList>("/quotes/all");
}

Quote API::randomQuote()
{
    return makeApiCall<Quote>("/quotes/random");
}

Quote API::quote(int index)
{
    return makeApiCall<Quote>("/quotes/" + QString::number(index));
}

QString API::version()
{
    QString result = m_net.get("/version");
    m_errorCode = (result.isEmpty()) ? API::NetworkError : API::NoError;
    return result;
}

template<class C>
C API::makeApiCall(const QString& query)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(m_net.get(query));

    if (jsonDocument.isEmpty() || jsonDocument.isNull()) {
        m_errorCode = NetworkError;
        return C();
    } else if (jsonDocument.isObject()) {
        QJsonObject jsonObject = jsonDocument.object();
        if (jsonObject.contains("error")) {
            m_errorCode = UnknownError;
            return C();
        } else {
            m_errorCode = NoError;
            return C(jsonObject);
        }
    } else if (jsonDocument.isArray()) {
        m_errorCode = NoError;
        return C(jsonDocument.array());
    } else {
        m_errorCode = UnknownError;
        return C();
    }
}

} // namespace QtBtcExplorer
