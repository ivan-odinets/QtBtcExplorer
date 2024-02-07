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

#ifndef QT_BTCEXPLORER_MARKETCAP_H
#define QT_BTCEXPLORER_MARKETCAP_H

#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class Marketcap src/types/qbtcexp_marketcap.h
 *  @brief Object of this class represents reply of API::marketcap method ( /api/price/marketcap ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Marketcap
{
public:
    /*! @brief Default constructor. Constructs invalid Marketcap object. */
    Marketcap();
    Marketcap(const QJsonObject& jsonObject);
    Marketcap(const QJsonValue& jsonValue) :
        Marketcap(jsonValue.toObject()) {}

    /*! @brief Returns true if this Marketcap object is valid. Marketcap object is considered to be valid if all of its
     *         fields are containing anything but not -1. */
    bool   isValid() const   { return (m_usd != -1.0) && (m_eur != -1.0) && (m_gbp != -1.0) && (m_xau != -1.0); }

    double usd() const { return m_usd; }
    double eur() const { return m_eur; }
    double gbp() const { return m_gbp; }
    double xau() const { return m_xau; }

private:
    double m_usd;
    double m_eur;
    double m_gbp;
    double m_xau;
};

inline QDebug operator<< (QDebug dbg, const Marketcap& marketcap)
{
    dbg.nospace() << qUtf8Printable(QString("Marketcap(usd=%1; eur=%2)")
                                    .arg(marketcap.usd())
                                    .arg(marketcap.eur()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_MARKETCAP_H
