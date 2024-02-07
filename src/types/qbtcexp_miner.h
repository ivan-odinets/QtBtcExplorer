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

#ifndef QT_BTCEXPLORER_MINER_H
#define QT_BTCEXPLORER_MINER_H

#include <QJsonObject>

namespace QtBtcExplorer {

/*! @class Miner src/types/qtbtcexp_miner.h
 *  @brief Object of this class is contained in Block object (represents reply of /api/block/$HASH and /api/block/$HEIGHT
 *         methods).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Miner
{
public:
    /*! @brief Default constructor. Constructs invalid Miner object. */
    Miner();
    Miner(const QJsonObject& jsonObject);
    Miner(const QJsonValue& jsonValue) :
        Miner(jsonValue.toObject()) {}

    /*! @brief Returns true if this Miner object contains valid information. Miner object is considered to be valid if
     *         all of its fields are containing non-empty strings. */
    bool      isValid() const          { return !(m_name.isEmpty() && m_link.isEmpty() && m_identifiedBy.isEmpty()); }

    QString   name() const             { return m_name; }
    QString   link() const             { return m_link; }
    QString   identifiedBy() const     { return m_identifiedBy; }

private:
    QString   m_name;
    QString   m_link;
    QString   m_identifiedBy;
};

inline QDebug operator<< (QDebug dbg, const Miner& miner)
{
    dbg.nospace() << qUtf8Printable(QString("Miner(name=%1; link=%2; identifiedBy=%3)")
                                    .arg(miner.name())
                                    .arg(miner.link())
                                    .arg(miner.identifiedBy()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_MINER_H
