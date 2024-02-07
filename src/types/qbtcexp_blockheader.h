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

#ifndef QT_BTCEXPLORER_BLOCKHEADER_H
#define QT_BTCEXPLORER_BLOCKHEADER_H

#include <QJsonObject>

namespace QtBtcExplorer {

/*! @class BlockHeader src/types/qtbtcexp_blockheader.h
 *  @brief Object of this class represents reply of API::getBlockHeaderByHash and API::getBlockHeaderByHeight methods
 *         ( /api/block/header/$HASH and /api/block/header/$HEIGHT ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class BlockHeader
{
public:
    /*! @brief Default constructor. Constructs invalid BlockHeader object. */
    BlockHeader();
    BlockHeader(const QJsonObject& jsonObject);
    BlockHeader(const QJsonValue& jsonValue) :
        BlockHeader(jsonValue.toObject()) {}

    /*! @brief Returns true if this BlockHeader object is containing valid infromation. BlockHeader object is considered
     *         to be valid if height() field is containing anything but not -1 and if hash() field contains non-empty
     *         string. */
    bool      isValid() const               { return (m_height != 0) && (!m_hash.isEmpty()); }

    QString   hash() const                  { return m_hash; }
    qint64    confirmations() const         { return m_confirmations; }
    qint64    height() const                { return m_height; }
    qint64    version() const               { return m_version; }
    QString   merkleRoot() const            { return m_merkleRoot; }
    qint64    time() const                  { return m_time; }
    qint64    medianTime() const            { return m_medianTime; }
    qint64    nonce() const                 { return m_nonce; }
    qint64    bits() const                  { return m_bits; }
    double    difficulty() const            { return m_difficulty; }
    QString   chainwork() const             { return m_chainwork; }
    qint32    nTx() const                   { return m_nTx; }
    QString   previousBlockHash() const     { return m_previousBlockHash; }
    QString   nextBlockHash() const         { return m_nextBlockHash; }

private:
    QString   m_hash;
    qint64    m_confirmations;
    qint64    m_height;
    qint64    m_version;
    QString   m_merkleRoot;
    qint64    m_time;
    qint64    m_medianTime;
    qint64    m_nonce;
    qint64    m_bits;
    double    m_difficulty;
    QString   m_chainwork;
    qint32    m_nTx;
    QString   m_previousBlockHash;
    QString   m_nextBlockHash;
};

inline QDebug operator<< (QDebug dbg, const BlockHeader& blockHeader)
{
    dbg.nospace() << qUtf8Printable(QString("BlockHeader(hash=%1; confirmations=%2; height=%3)")
                                    .arg(blockHeader.hash())
                                    .arg(blockHeader.confirmations())
                                    .arg(blockHeader.height()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_BLOCKHEADER_H
