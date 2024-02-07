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

#ifndef QT_BTCEXPLORER_NEXTHALVING_H
#define QT_BTCEXPLORER_NEXTHALVING_H

#include <QJsonObject>

namespace QtBtcExplorer {

/*! @class NextHalving src/types/qbtcexp_nexthalving.h
 *  @brief Object of this class represents reply of API::nextHalving method ( /api/blockchain/next-halving ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class NextHalving
{
public:
    /*! @brief Default constructor. Constructs invalid NextHalving object. */
    NextHalving();
    NextHalving(const QJsonObject& jsonObject);
    NextHalving(const QJsonValue& jsonValue) :
        NextHalving(jsonValue.toObject()) {}

    /*! @brief Returns true if this NextHalving object is containing valid information. NextHalving object is considered
     *         to be valid if nextHalvingIndex() field contains anything but not -1. */
    bool      isValid() const { return m_nextHalvingIndex != -1; }

    qint32    nextHalvingIndex() const           { return m_nextHalvingIndex; }
    qint32    nextHalvingBlock() const           { return m_nextHalvingBlock; }
    double    nextHalvingSubsidy() const         { return m_nextHalvingSubsidy; }
    qint32    blocksUntillNextHalving() const    { return m_blocksUntilNextHalving; }
    QString   timeUntillNextHalving() const      { return m_timeUntilNextHalving; }
    QDateTime nextHalvingEstimatedDate() const   { return m_nextHalvingEstimatedDate; }

private:
    qint32    m_nextHalvingIndex;
    qint32    m_nextHalvingBlock;
    double    m_nextHalvingSubsidy;
    qint32    m_blocksUntilNextHalving;
    QString   m_timeUntilNextHalving;
    QDateTime m_nextHalvingEstimatedDate;
};

inline QDebug operator<< (QDebug dbg, const NextHalving& nextHalving)
{
    dbg.nospace() << qUtf8Printable(QString("NextHalving(nextHalvingSubsidy=%1; nextHalvingEstimatedDate=%2)")
                                    .arg(nextHalving.nextHalvingSubsidy())
                                    .arg(nextHalving.nextHalvingEstimatedDate().toString(Qt::ISODateWithMs)));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // NEXTHALVING_H
