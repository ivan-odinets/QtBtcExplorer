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

#ifndef QT_BTCEXPLORER_CHAINTIP_H
#define QT_BTCEXPLORER_CHAINTIP_H

#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class ChainTip src/types/qbtcexp_chaintip.h
 *  @brief Object of this class represents reply of API::getChainTip method ( /api/blocks/tip ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class ChainTip
{
public:
    /*! @brief Default constructor. Constructs invalid ChainTip object. */
    ChainTip();
    ChainTip(const QJsonObject& jsonObject);
    ChainTip(const QJsonValue& jsonValue) :
        ChainTip(jsonValue.toObject()) {}

    /*! @brief Returns true if this ChainTip object contains valid information. ChainTip object is considered to be valid
     *         if height() field contains enything but not -1 and if hash() field is not empty. */
    bool      isValid() const     { return (m_height != -1) && (!m_hash.isEmpty()); }

    qint32    height() const      { return m_height; }
    QString   hash() const        { return m_hash; }

private:
    qint32    m_height;
    QString   m_hash;
};

inline QDebug operator<< (QDebug dbg, const ChainTip& chainTip)
{
    dbg.nospace() << qUtf8Printable(QString("ChainTip(height%1; hash=%2)")
                                    .arg(chainTip.height())
                                    .arg(chainTip.hash()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // CHAINTIP_H
