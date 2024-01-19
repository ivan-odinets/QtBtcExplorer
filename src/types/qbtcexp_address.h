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

#ifndef QT_BTCEXPLORER_ADDRESS_H
#define QT_BTCEXPLORER_ADDRESS_H

#include <QJsonObject>
#include <QJsonValue>

#include "./qbtcexp_btc.h"

namespace QtBtcExplorer {

/*! @brief Address src/types/qtbtcexp_address.h
 *  @class Object of this class represents reply of /api/address/$ADDRESS method.
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Address
{
public:
    Address();
    Address(const QJsonObject& jsonObject);
    Address(const QJsonValue& jsonValue) :
        Address(jsonValue.toObject()) {}

    QString   encoding() const         { return m_encoding; }

    QString   address() const          { return m_address; }
    QString   scriptPubKey() const     { return m_scriptPubKey; }
    bool      isScript() const         { return m_isScript; }
    bool      isWitness() const        { return m_isWintess; }
    qint32    witnessVersion() const   { return m_witnessVersion; }
    QString   witnessProgram() const   { return m_witnessProgram; }

    qint64         txCount() const     { return m_txCount; }
    QStringList    txIds() const       { return m_txIds; }
    Btc            balance() const     { return m_balance; }
    qint64         balanceSat() const  { return m_balance.satoshi(); }

private:
    QString        m_encoding;

    // Values contained in jsonField "validateaddress"
    QString   m_address;
    QString   m_scriptPubKey;
    bool      m_isScript;
    bool      m_isWintess;
    qint32    m_witnessVersion;
    QString   m_witnessProgram;

    // Values contained in jsonField "txHistory"
    qint64         m_txCount;
    QStringList    m_txIds;
    Btc            m_balance;
};

inline QDebug operator<< (QDebug dbg, const Address& address)
{
    dbg.nospace() << qUtf8Printable(QString("Address(address=%1; balance=%2 BTC)")
                                    .arg(address.address())
                                    .arg(address.balance().btc()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_ADDRESS_H
