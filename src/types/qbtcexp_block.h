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

#ifndef QT_BTCEXPLORER_BLOCK_H
#define QT_BTCEXPLORER_BLOCK_H

#include "qbtcexp_btc.h"
#include "qbtcexp_blockheader.h"
#include "qbtcexp_miner.h"

namespace QtBtcExplorer {

/*! @class Block src/types/qtbtcexp_block.h
 *  @brief Object of this class represents reply of API::getBlockByHash and API::getBlockByHeigh methods ( /api/block/$HASH
 *         and /api/block/$HEIGHT ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Block : public BlockHeader
{
public:
    /*! @brief Default constructor. Constructs invalid Block object. */
    Block();
    Block(const QJsonObject& jsonObject);
    Block(const QJsonValue& jsonValue) :
        Block(jsonValue.toObject()) {}

    /*! @brief Returns true if this Block object is containing valid information. Block object is considered to be valid
     *         if BlockHeader::isValid returns true. And if size() field is containing anything but not -1. */
    bool           isValid() const          { return (BlockHeader::isValid()) && (m_size != -1); }

    qint32         strippedSize() const     { return m_strippedSize; }
    qint32         size() const             { return m_size; }
    qint32         weight() const           { return m_weight; }
    QStringList    tx() const               { return m_tx; }

    Btc            totalFees() const        { return m_totalFees; }
    double         totalFeesDouble() const  { return m_totalFees.btc(); }
    Miner          miner() const            { return m_miner; }
    Btc            subsidy() const          { return m_subsidy; }
    double         subsidyDouble() const    { return m_subsidy.btc(); }

private:
    qint32         m_strippedSize;
    qint32         m_size;
    qint32         m_weight;
    QStringList    m_tx;
    Btc            m_totalFees;
    Miner          m_miner;
    Btc            m_subsidy;
};

inline QDebug operator<< (QDebug dbg, const Block& blockHeader)
{
    dbg.nospace() << qUtf8Printable(QString("Block(hash=%1; confirmations=%2; height=%3; tx.count()=%4; miner.name()=%5)")
                                    .arg(blockHeader.hash())
                                    .arg(blockHeader.confirmations())
                                    .arg(blockHeader.height())
                                    .arg(blockHeader.tx().count())
                                    .arg(blockHeader.miner().name()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_BLOCK_H
