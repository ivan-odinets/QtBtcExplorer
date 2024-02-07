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

#ifndef QT_BTCEXPLORER_MEMPOOLFEES_H
#define QT_BTCEXPLORER_MEMPOOLFEES_H

#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class MempoolFees src/types/qtbtcexp_mempoolfees.h
 *  @brief Object of this class represents reply of API::mempoolFees method ( /api/mempool/fees  ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class MempoolFees
{
public:
    /*! @brief Default constructor. Constructs invalid MempoolFees object. */
    MempoolFees();
    MempoolFees(const QJsonObject& jsonObject);
    MempoolFees(const QJsonValue& jsonValue) :
        MempoolFees(jsonValue.toObject()) {}

    /*! @brief Returns true if this MempoolFees object is valid. MempoolFees object is considered to be valid if all of
     *         its fields are containing anything but not -1. */
    bool      isValid() const          { return (m_nextBlockSmart != -1) && (m_nextBlockMin != -1) &&
                                                (m_nextBlockMax != -1) && (m_nextBlockMedian != -1) &&
                                                (m_30min != -1) && (m_60min != -1) && (m_1day != -1); }

    qint32    nextBlockSmart() const   { return m_nextBlockSmart; }
    qint32    nextBlockMin() const     { return m_nextBlockMin; }
    qint32    nextBlockMax() const     { return m_nextBlockMax; }
    qint32    nextBlockMedian() const  { return m_nextBlockMedian; }
    qint32    fees30min() const        { return m_30min; }
    qint32    fees60min() const        { return m_60min; }
    qint32    fees1day() const         { return m_1day; }

private:
    qint32    m_nextBlockSmart;
    qint32    m_nextBlockMin;
    qint32    m_nextBlockMax;
    qint32    m_nextBlockMedian;
    qint32    m_30min;
    qint32    m_60min;
    qint32    m_1day;
};

inline QDebug operator<< (QDebug dbg, const MempoolFees& mempoolFees)
{
    dbg.nospace() << qUtf8Printable(QString("MempoolFees(nextBlockMedian=%1; fees30min=%2; fees60min=%3; fees1day=%4)")
                                    .arg(mempoolFees.nextBlockMedian())
                                    .arg(mempoolFees.fees30min())
                                    .arg(mempoolFees.fees60min())
                                    .arg(mempoolFees.fees1day()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_MEMPOOLFEES_H
