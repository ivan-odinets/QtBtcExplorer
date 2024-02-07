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

#ifndef QT_BTCEXPLORER_SATS_H
#define QT_BTCEXPLORER_SATS_H

#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class Sats src/types/qbtcexp_sats.h
 *  @brief Object of this class represents reply of API::sats method ( /api/price/sats ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Sats
{
public:
    /*! @brief Default constructor. Constructs invalid Sats object. */
    Sats();
    Sats(const QJsonObject& jsonObject);
    Sats(const QJsonValue& jsonValue) :
        Sats(jsonValue.toObject()) {}

    /*! @brief Returns true if this Sats object is valid. Sats object is considered to be valid if all of its
     *         fields are containing anything but not -1. */
    bool   isValid() const   { return (m_usd != -1) && (m_eur != -1) && (m_gbp != -1) && (m_xau != -1); }

    qint64 usd() const { return m_usd; }
    qint64 eur() const { return m_eur; }
    qint64 gbp() const { return m_gbp; }
    qint64 xau() const { return m_xau; }

private:
    qint64 m_usd;
    qint64 m_eur;
    qint64 m_gbp;
    qint64 m_xau;
};

inline QDebug operator<< (QDebug dbg, const Sats& sats)
{
    dbg.nospace() << qUtf8Printable(QString("Sats(usd=%1; eur=%2)")
                                    .arg(sats.usd())
                                    .arg(sats.eur()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_SATS_H
