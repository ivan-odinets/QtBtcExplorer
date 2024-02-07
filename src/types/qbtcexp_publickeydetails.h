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

#ifndef QT_BTCEXPLORER_PUBLICKEYDETAILS_H
#define QT_BTCEXPLORER_PUBLICKEYDETAILS_H

#include <QJsonObject>
#include <QJsonValue>
#include <QStringList>

#include "qbtcexp_relatedkey.h"

namespace QtBtcExplorer {

/*! @class PublicKeyDetails src/types/qbtcexp_publickeydetails.h
 *  @brief Object of this class represents reply of API::getPublicKeyDetails method ( /api/xyzpub/$XPUB ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class PublicKeyDetails
{
public:
    /*! @brief Default constructor. Constrcuts invalid PublicKeyDetails object. */
    PublicKeyDetails();
    PublicKeyDetails(const QJsonObject& jsonObject);
    PublicKeyDetails(const QJsonValue& jsonValue) :
        PublicKeyDetails(jsonValue.toObject()) {}

    /*! @brief Returns true if this PublicKeyDetails object contains reasonable information. PublicKeyDetails object is
     *         considered to be valid if fields changeAddresses() and recieveAddresses() are not empty. */
    bool isValid() const { return (!m_changeAddresses.isEmpty()) && (!m_receiveAddresses.isEmpty()); }

    QString        keyTypeString() const         { return m_keyTypeString; }
    RelatedKeyList relatedKeys() const           { return m_relatedKeys; }
    QString        outputTypeString() const      { return m_outputTypeString; }
    QString        outputTypeDescString() const  { return m_outputTypeDescString; }
    QString        bip32Path() const             { return m_bip32Path; }
    QStringList    receiveAddresses() const      { return m_receiveAddresses; }
    QStringList    changeAddresses() const       { return m_changeAddresses; }

private:
    QString        m_keyTypeString;
    RelatedKeyList m_relatedKeys;
    QString        m_outputTypeString;
    QString        m_outputTypeDescString;
    QString        m_bip32Path;
    QStringList    m_receiveAddresses;
    QStringList    m_changeAddresses;
};

inline QDebug operator<< (QDebug dbg, const PublicKeyDetails& publicKeyDetails)
{
    dbg.nospace() << qUtf8Printable(QString("PublicKeyDetails(keyTypeString=%1; recieveAddresses.count()=%2; changeAddresses.count()=%3)")
                                    .arg(publicKeyDetails.keyTypeString())
                                    .arg(publicKeyDetails.receiveAddresses().count())
                                    .arg(publicKeyDetails.changeAddresses().count()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer


#endif // PUBLICKEYDETAILS_H
