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

#ifndef QT_BTCEXPLORER_UTXOUNSPENDABLES_H
#define QT_BTCEXPLORER_UTXOUNSPENDABLES_H

#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class UtxoUnspendables src/types/qbtcexp_utxounspendables.h
 *  @brief Object of this class is present as one of the fields of UtxoSetBlockInfo, which is returned as part of reply
 *         of API::getUtxoSet method ( /api/blockchain/utxo-set ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class UtxoUnspendables
{
public:
    UtxoUnspendables();
    UtxoUnspendables(const QJsonObject& jsonObject);
    UtxoUnspendables(const QJsonValue& jsonValue) :
        UtxoUnspendables(jsonValue.toObject()) {}

    bool      isValid() const          { return (m_genesisBlock != -1) && (m_bip30 != -1) &&
                                                (m_scripts != -1) && (m_unclaimedRewards != -1); }

    qint32    genesisBlock() const     { return m_genesisBlock; }
    qint32    bip30() const            { return m_bip30; }
    qint32    scripts() const          { return m_scripts; }
    qint32    unclaimedRewards() const { return m_unclaimedRewards; }

private:
    qint32 m_genesisBlock;
    qint32 m_bip30;
    qint32 m_scripts;
    qint32 m_unclaimedRewards;
};

inline QDebug operator<< (QDebug dbg, const UtxoUnspendables& utxoUnspendables)
{
    dbg.nospace() << qUtf8Printable(QString("UtxoUnspendables(genesisBlock=%1; bip30=%2; scripts=%3; unclaimedRewards=%4)")
                                    .arg(utxoUnspendables.genesisBlock())
                                    .arg(utxoUnspendables.bip30())
                                    .arg(utxoUnspendables.scripts())
                                    .arg(utxoUnspendables.unclaimedRewards()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // UTXOUNSPENDABLES_H
