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

#ifndef QT_BTCEXPLORER_RELATEDKEY_H
#define QT_BTCEXPLORER_RELATEDKEY_H

#include <QJsonObject>

#include "qbtcexp_json_objectslist.h"

namespace QtBtcExplorer {

/*! @class RelatedKey src/types/qbtcexp_relatedkey.h
 *  @brief A list of such objects (RelatedKeyList) is contained as one of the fields of PublicKeyDetails object, which
 *         is returned by API::getPublicKeyDetails method ( /api/xyzpub/$XPUB )
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class RelatedKey
{
public:
    /*! @brief Default constructor. Constructs invalid RelatedKey object. */
    RelatedKey();
    RelatedKey(const QJsonObject& jsonObject);
    RelatedKey(const QJsonValue& jsonValue) :
        RelatedKey(jsonValue.toObject()) {}

    /*! @brief Returns true if this RelatedKey object contains reasonable information. RelatedKey object is considered
     *         to be valid if key() field is not empty. */
    bool isValid() const { return !m_key.isEmpty(); }

    QString   keyTypeString() const         { return m_keyTypeString; }
    QString   key() const                   { return m_key; }
    QString   outputTypeString() const      { return m_outputTypeString; }
    QString   firstAddressString() const    { return m_firstAddressString; }

private:
    QString   m_keyTypeString;
    QString   m_key;
    QString   m_outputTypeString;
    QString   m_firstAddressString;
};

inline QDebug operator<< (QDebug dbg, const RelatedKey& relatedKey)
{
    dbg.nospace() << qUtf8Printable(QString("RelatedKey(keyTypeString=%1; key=%2; firstAddressString=%3)")
                                    .arg(relatedKey.keyTypeString())
                                    .arg(relatedKey.key())
                                    .arg(relatedKey.firstAddressString()));
    return dbg.maybeSpace();
}

/*! @typedef RelatedKeyList
 *  @brief This is a list of RelatedKey objects. It is present as obe of the fields of PublicKeyDetails object, which is
 *         returned by API::getPublicKeyDetails method ( /api/xyzpub/$XPUB ). Nothing more than a QList with some extra
 *         constructors (JsonObjectsList).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

typedef JsonObjectsList<RelatedKey> RelatedKeyList;

inline QDebug operator<< (QDebug dbg, const RelatedKeyList& relatedKeyList)
{
    dbg.nospace() << qUtf8Printable(QString("RelatedKeyList(count=%1)")
                   .arg(relatedKeyList.count()));

    return dbg.maybeSpace();
}

} // nameserver QtBtcExplorer

#endif // QT_BTCEXPLORER_RELATEDKEY_H
