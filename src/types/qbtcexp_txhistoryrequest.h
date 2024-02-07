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

#ifndef QT_BTCEXPLORER_TXHISTORYREQUEST_H
#define QT_BTCEXPLORER_TXHISTORYREQUEST_H

#include <QJsonObject>
#include <QJsonValue>

#include "../qbtcexp_global.h"

namespace QtBtcExplorer {

/*! @class TxHistoryRequest src/types/qbtcexp_txhistoryrequest.h
 *  @brief Object of this type is contained as one of the fields of TxHistory object. See Address class, TxHistory class.
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class TxHistoryRequest
{
public:
    /*! @brief Default constructor. Constructs invalid TxHistoryRequest object. */
    TxHistoryRequest();
    TxHistoryRequest(const QJsonObject& jsonObject);
    TxHistoryRequest(const QJsonValue& jsonValue) :
        TxHistoryRequest(jsonValue.toObject()) {}

    /*! @brief Returns true if this TxHistoryRequest object contains valid information. TxHistoryRequest object is
     *         considered to be valid if limit() and offset() fiedls are containing anything but not -1 amd if sort()
     *         field is containing either Asc or Desc value. */
    bool      isValid() const     { return (m_limit != -1) && (m_offset != -1) && (m_sort != QtBtcExplorer::Unknown);  }

    qint32    limit() const       { return m_limit; }
    qint32    offset() const      { return m_offset; }
    Sort      sort() const        { return m_sort; }

private:
    qint32 m_limit;
    qint32 m_offset;
    Sort   m_sort;
};

inline QDebug operator<< (QDebug dbg, const TxHistoryRequest& txHistoryRequest)
{
    dbg.nospace() << qUtf8Printable(QString("TxHistoryRequest(limit=%1; offset=%2; sort=%3)")
                                    .arg(txHistoryRequest.limit())
                                    .arg(txHistoryRequest.offset())
                                    .arg(sortToSrting(txHistoryRequest.sort())));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // TXHISTORYREQUEST_H
