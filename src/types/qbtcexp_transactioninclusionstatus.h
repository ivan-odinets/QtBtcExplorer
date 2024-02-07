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

#ifndef QT_BTCEXPLORER_TRANSACTIONINCLUDED_H
#define QT_BTCEXPLORER_TRANSACTIONINCLUDED_H

#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class TransactionInclusionStatus src/types/qbtcexp_transactioninclusionstatus.h
 *  @brief Object of this type represents reply from /api/mining/next-block/includes/$TXID method.
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class TransactionInclusionStatus
{
public:
    /*! @brief Default constructor. Constructs invalid TransactionInclusionStatus object. */
    TransactionInclusionStatus();
    TransactionInclusionStatus(const QJsonObject& jsonObject);
    TransactionInclusionStatus(const QJsonValue& jsonValue) :
        TransactionInclusionStatus(jsonValue.toObject()) {}

    /*! @brief Returns true if this TransactionInclusionStatus is valid and contains reasonable information.
     *         TransactionInclusionStatus is considered to be valid if txCount() field contains anything but not -1. */
    bool      isValid() const     { return (m_txCount != -1); }

    bool      included() const    { return m_included; }
    qint32    index() const       { return m_index; }
    qint32    txCount() const     { return m_txCount; }

    operator bool() const         { return m_included; }

private:
    bool      m_included;
    qint32    m_index;
    qint32    m_txCount;
};

inline QDebug operator<< (QDebug dbg, const TransactionInclusionStatus& status)
{
    dbg.nospace() << qUtf8Printable(QString("TransactionInclusionStatus(included=%1; index=%2)")
                                    .arg((status.included()) ? "true" : "false")
                                    .arg(status.index()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_TRANSACTIONINCLUDED_H
