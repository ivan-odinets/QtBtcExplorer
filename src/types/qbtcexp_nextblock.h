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

#ifndef QT_BTCEXPLORER_NEXTBLOCK_H
#define QT_BTCEXPLORER_NEXTBLOCK_H

#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class NextBlock src/types/qbtcexp_nextblock.h
 *  @brief Object of this class represents reply of API::getNextBlock method ( /api/mining/next-block ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class NextBlock
{
public:
    /*! @brief Default constructor. Constructs invalid NextBlock object. */
    NextBlock();
    NextBlock(const QJsonObject& jsonObject);
    NextBlock(const QJsonValue& jsonValue) :
        NextBlock(jsonValue.toObject()) {}

    /*! @brief Returns true if this NextBlock object contains valid information. NextBlock object is considered to be
     *         valid if field txCount() contains anything but not -1. */
    bool      isValid() const     { return (m_txCount != -1); }

    qint32    txCount() const     { return m_txCount; }
    double    minFeeRate() const  { return m_minFeeRate; }
    double    maxFeeRate() const  { return m_maxFeeRate; }
    QString   minFeeTxId() const  { return m_minFeeTxId; }
    QString   maxFeeTxId() const  { return m_maxFeeTxId; }
    double    totalFees() const   { return m_totalFees; }

private:
    qint32    m_txCount;
    double    m_minFeeRate;
    double    m_maxFeeRate;
    QString   m_minFeeTxId;
    QString   m_maxFeeTxId;
    double    m_totalFees;
};

inline QDebug operator<< (QDebug dbg, const NextBlock& nextBlock)
{
    dbg.nospace() << qUtf8Printable(QString("NextBlock(txCount=%1; minFeeRate=%2; maxFeeRate=%3; totalFees=%4)")
                                    .arg(nextBlock.txCount())
                                    .arg(nextBlock.minFeeRate())
                                    .arg(nextBlock.maxFeeRate())
                                    .arg(nextBlock.totalFees()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_NEXTBLOCK_H
