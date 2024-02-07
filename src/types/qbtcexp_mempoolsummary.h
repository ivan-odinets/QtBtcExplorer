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

#ifndef QT_BTCEXPLORER_MEMPOOLSUMMARY_H
#define QT_BTCEXPLORER_MEMPOOLSUMMARY_H

#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class MempoolSummary src/types/qbtcexp_mempoolsummary.h
 *  @brief Object of this class represents reply of API::mempoolSummary ( /api/mempool/summary ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class MempoolSummary
{
public:
    /*! @brief Default constructor. Constructs invalid MempoolSummary object. */
    MempoolSummary();
    MempoolSummary(const QJsonObject& jsonObject);
    MempoolSummary(const QJsonValue& jsonValue) :
        MempoolSummary(jsonValue.toObject()) {}

    /*! @brief Returns true if this MempoolSUmmary object is valid. MempoolSummary object is considered to be valid if
     *         size() field contains anything but not -1. */
    bool      isValid() const { return m_size != -1; }

    bool      loaded() const                { return m_loaded; }
    qint32    size() const                  { return m_size; }
    qint64    bytes() const                 { return m_bytes; }
    qint64    usage() const                 { return m_usage; }
    double    totalFee() const              { return m_totalFee; }
    qint64    maxMempool() const            { return m_maxMempool; }
    double    mempoolMinFee() const         { return m_mempoolminfee; }
    double    minRelayTxFee() const         { return m_minrelaytxfee; }
    double    incrementalRelayFee() const   { return m_incrementalrelayfee; }
    qint32    unbroadcastCount() const      { return m_unbroadcastcount; }
    bool      fullRbf() const               { return m_fullrbf; }

private:
    bool      m_loaded;
    qint32    m_size;
    qint64    m_bytes;
    qint64    m_usage;
    double    m_totalFee;
    qint64    m_maxMempool;
    double    m_mempoolminfee;
    double    m_minrelaytxfee;
    double    m_incrementalrelayfee;
    qint32    m_unbroadcastcount;
    bool      m_fullrbf;
};

inline QDebug operator<< (QDebug dbg, const MempoolSummary& mempoolSummary)
{
    dbg.nospace() << qUtf8Printable(QString("MempoolSummary(size=%1; totalFee=%2)")
                                    .arg(mempoolSummary.size())
                                    .arg(mempoolSummary.totalFee()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_MEMPOOLSUMMARY_H
