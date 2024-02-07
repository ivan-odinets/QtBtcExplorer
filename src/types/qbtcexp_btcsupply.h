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

#ifndef QT_BTCEXPLORER_BTCSUPPLY_H
#define QT_BTCEXPLORER_BTCSUPPLY_H

#include "qbtcexp_btc.h"

#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class BtcSupply src/types/qbtcexp_btcsupply.h
 *  @brief Object of this class represents reply of API::getCoins method ( /api/blockchain/coins ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class BtcSupply
{
public:
    enum Type {
        Calculated,
        Unknown
    };

    /*! @brief Default constructor. Constructs invalid BtcSupply object. */
    BtcSupply();
    BtcSupply(const QJsonObject& jsonObject);
    BtcSupply(const QJsonValue& jsonValue) :
        BtcSupply(jsonValue.toObject()) {}

    /*! @brief Returns true if this BtcSupply object contains valid information. BtcSupply object is considered to be valid
     *         if supply object is valid (see Btc::isValid). */
    bool      isValid() const     { return m_supply.isValid(); }

    Btc       supply() const      { return m_supply; }
    Type      type() const        { return m_type; }
    QString   typeString() const  { return m_typeString; }

private:
    Btc       m_supply;
    Type      m_type;
    QString   m_typeString;
};

inline QDebug operator<< (QDebug dbg, const BtcSupply& btcSupply)
{
    dbg.nospace() << qUtf8Printable(QString("BtcSupply(supply.btc()=%1 BTC; typeString=%2)")
                                    .arg(btcSupply.supply().btc()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_BTCSUPPLY_H
