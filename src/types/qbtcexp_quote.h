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

#ifndef QT_BTCEXPLORER_QUOTE_H
#define QT_BTCEXPLORER_QUOTE_H

#include <QDate>
#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>

#include "qbtcexp_json_objectslist.h"

namespace QtBtcExplorer {

/*! @class Quote src/types/qbtcexp_quote.h
 *  @brief Object of this class represents reply of API::quote and API::randomQuote methods ( /api/quotes/$INDEX and
 *         /api/quotes/random ). Moreover a list of such objects (QuoteList) is returned as reply of API::allQuotes
 *         method ( /api/quotes/all )
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Quote
{
public:
    /*! @brief Default constructor. Conastructs invalid Quote object. */
    Quote();
    Quote(const QJsonObject& jsonObject);
    Quote(const QJsonValue& jsonValue) :
        Quote(jsonValue.toObject()) {}

    /*! @brief Returns true if this Quote object contains valid information. Quote object is considered to be valid if
     *         text() is not empty. */
    bool      isValid() const     { return !m_text.isEmpty(); }

    QString   text() const        { return m_text; }
    QString   speaker() const     { return m_speaker; }
    QDate     date() const        { return m_date; }
    QString   context() const     { return m_context; }
    QString   url() const         { return m_url; }
    qint32    quoteIndex() const  { return m_quoteIndex; }

private:
    QString   m_text;
    QString   m_speaker;
    QDate     m_date;
    QString   m_context;
    QString   m_url;
    qint32    m_quoteIndex;
};

inline QDebug operator<< (QDebug dbg, const Quote& quote)
{
    dbg.nospace() << qUtf8Printable(QString("Quote(text=%1; speaker=%2; date=%3)")
                                    .arg(quote.text())
                                    .arg(quote.speaker())
                                    .arg(quote.date().toString(Qt::ISODate)));

    return dbg.maybeSpace();
}

/*! @typedef QuoteList
 *  @brief This is a list of Quote objects. It is returned by method API::allQuotes Nothing more than a QList with some
 *         extra constructors (JsonObjectsList).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

typedef JsonObjectsList<Quote> QuoteList;

inline QDebug operator<< (QDebug dbg, const QuoteList& quoteList)
{
    dbg.nospace() << qUtf8Printable(QString("QuoteList(count=%1)")
                   .arg(quoteList.count()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_QUOTE_H
