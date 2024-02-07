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

#ifndef QT_BTCEXPLORER_BTCPRICE_H
#define QT_BTCEXPLORER_BTCPRICE_H

#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class BtcPrice src/types/qbtcexp_btcprice.h
 *  @brief Object of this class represents reply of API::price method ( /api/price ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class BtcPrice
{
public:
    /*! @brief Default constructor. Constructs invalid BtcPrice object. */
    BtcPrice();
    BtcPrice(const QJsonObject& jsonObject);
    BtcPrice(const QJsonValue& jsonValue) :
        BtcPrice(jsonValue.toObject()) {}

    /*! @brief Returns true if this BtcPrice object contains valid information. BtcPrice object is considered to be valid
     *         if all price fields are containing anything but not -1. */
    bool isValid() const  { return (m_btcUsd != -1.0) && (m_btcEur != -1.0) &&
                                   (m_btcGbp != -1.0) && (m_btcXau != -1.0); }

    double btcUsd() const { return m_btcUsd; }
    double btcEur() const { return m_btcEur; }
    double btcGbp() const { return m_btcGbp; }
    double btcXau() const { return m_btcXau; }

private:
    double m_btcUsd;
    double m_btcEur;
    double m_btcGbp;
    double m_btcXau;
};

inline QDebug operator<< (QDebug dbg, const BtcPrice& btcPrice)
{
    dbg.nospace() << qUtf8Printable(QString("BtcPrice(usd=%1; eur=%2)")
                                    .arg(btcPrice.btcUsd())
                                    .arg(btcPrice.btcEur()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_BTCPRICE_H
