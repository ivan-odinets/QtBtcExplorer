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

#ifndef QT_BTCEXPLORER_BTC_H
#define QT_BTCEXPLORER_BTC_H

#include <QDebug>

namespace QtBtcExplorer {

/*! @class Btc src/types/qtbtcexp_btc.h
 *  @brief Object of this class represents amount of BTC. */

class Btc
{
public:
    explicit Btc(qint64 sats = -1) :
        m_satoshi{sats} {}

    /*! @brief Returns true if this Btc object contains reasonable information. Btc object is considered valid if
     *         satoshi() returns anything but not -1. */
    bool   isValid() const   { return m_satoshi != -1; }

    /*! @brief Returns amount of bitcoin in BTC. */
    double btc() const       { return m_satoshi / 100000000.0; }

    /*! @brief Returns amount of bitcoin in mBTC. */
    double mBtc() const      { return m_satoshi / 100000.0; }

    /*! @brief Returns amount of bitcoin in uBTC. */
    double uBtc() const      { return m_satoshi / 100.0; }

    /*! @brief Returns amount of bitcoin in sats. */
    qint64 satoshi() const   { return m_satoshi; }

    /*! @brief Returns Btc object with BTC amount specified in input string.
     *  @details Accepts strings containing values with floating point. In case of wrong input - invalid Btc object is
     *           returned. */
    static Btc fromBtcString(const QString& btc);

    /*! @brief Returns Btc object with BTC amount specified in input double. */
    static Btc fromBtcDouble(double btc);

private:
    qint64 m_satoshi;
};

inline QDebug operator<< (QDebug dbg, const Btc& btc)
{
    dbg.nospace() << qUtf8Printable(QString("Btc(%1 BTC)")
                                    .arg(btc.btc()));

    return dbg.maybeSpace();
}

} //namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_BTC_H
