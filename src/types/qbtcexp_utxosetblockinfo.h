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

#ifndef QT_BTCEXPLORER_UTXOSETBLOCKINFO_H
#define QT_BTCEXPLORER_UTXOSETBLOCKINFO_H

#include "qbtcexp_utxounspendables.h"

namespace QtBtcExplorer {

/*! @class UtxoSetBlockInfo src/types/qbtcexp_utxosetblockinfo.h
 *  @brief Object of this class is present as one of the fields of UtxoSet, which is returned by API::getUtxoSet method
 *         ( /api/blockchain/utxo-set ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class UtxoSetBlockInfo
{
public:
    /*! @brief Default constructor. Constructs invalid UtxoSetBlockInfo object. */
    UtxoSetBlockInfo();
    UtxoSetBlockInfo(const QJsonObject& jsonObject);
    UtxoSetBlockInfo(const QJsonValue& jsonValue) :
        UtxoSetBlockInfo(jsonValue.toObject()) {}

    /*! @brief Returns true if this UtxoSetBlockInfo object is containing valid information. UtxoSetBlockInfo object is
     *         considered to be valid if all of its fields are containing anything but not -1.0. */
    bool      isValid() const               { return (m_prevousSpent != -1.0) && (m_coinbase != -1.0) &&
                                                     (m_newOutputsExCoinbase != -1.0) && (m_unspendable != -1.0); }

    double              prevousSpent() const          { return m_prevousSpent; }
    double              coinbase() const              { return m_coinbase; }
    double              newOutputsExCoinbase() const  { return m_newOutputsExCoinbase; }
    double              unspendable() const           { return m_unspendable; }
    UtxoUnspendables    unspendables() const          { return m_unspendables; }
private:
    double              m_prevousSpent;
    double              m_coinbase;
    double              m_newOutputsExCoinbase;
    double              m_unspendable;
    UtxoUnspendables    m_unspendables;
};

inline QDebug operator<< (QDebug dbg, const UtxoSetBlockInfo& utxoSetBlockInfo)
{
    dbg.nospace() << qUtf8Printable(QString("UtxoSetBlockInfo(prevousSpent=%1; coinbase=%2; newOutputsExCoinbase=%3; unspendable=%4)")
                                    .arg(utxoSetBlockInfo.prevousSpent())
                                    .arg(utxoSetBlockInfo.coinbase())
                                    .arg(utxoSetBlockInfo.newOutputsExCoinbase())
                                    .arg(utxoSetBlockInfo.unspendable()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_UTXOSETBLOCKINFO_H
