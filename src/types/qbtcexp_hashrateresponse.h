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

#ifndef QT_BTCEXPLORER_HASHRATERESPONSE_H
#define QT_BTCEXPLORER_HASHRATERESPONSE_H

#include <QJsonObject>
#include <QJsonValue>

namespace QtBtcExplorer {

/*! @class Hashrate src/types/qbtcexp_hashrateresponse.h
 *  @brief This class represents field of HashrateResponse object. HashrateResponse object is returned by
 *         API::getHashrate method ( /api/mining/hashrate ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Hashrate
{
public:
    /*! @brief Default constructor. Constructs invalid Hashrate object. */
    Hashrate();
    Hashrate(const QJsonObject& jsonObject);
    Hashrate(const QJsonValue& jsonValue) :
        Hashrate(jsonValue.toObject()) {}

    /*! @brief Returns true if this Hashrate object contains valid information. Hashrate object is considered to be valid
     *         if value() and raw() fields are containing anything but not -1. */
    bool      isValid() const                    { return (m_value != -1.0) && (m_raw != -1); }

    double    value() const                      { return m_value; }
    QString   unitString() const                 { return m_unitString; }
    QString   unitAbbreviationString() const     { return m_unitAbbreviationString; }
    qint16    unitExponent() const               { return m_unitExponent; }
    qint64    unitMultiplier() const             { return m_unitMultiplier; }
    double    raw() const                        { return m_raw; }
    QString   stringOne() const                  { return m_stringOne; }
    QString   stringTwo() const                  { return m_stringTwo; }
    QString   stringThree() const                { return m_stringThree; }

private:
    double    m_value;
    QString   m_unitString;
    QString   m_unitAbbreviationString;
    qint16    m_unitExponent;
    qint64    m_unitMultiplier;
    double    m_raw;
    QString   m_stringOne;
    QString   m_stringTwo;
    QString   m_stringThree;
};

inline QDebug operator<< (QDebug dbg, const Hashrate& hashrate)
{
    dbg.nospace() << qUtf8Printable(QString("Hashrate(value=%1; stringOne=%2)")
                                    .arg(hashrate.value())
                                    .arg(hashrate.stringOne()));

    return dbg.maybeSpace();
}

/*! @class HashrateResponse src/types/qbtcexp_hashrateresponse.h
 *  @brief Object of this class is returned by API::getHashrate method ( /api/mining/hashrate ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class HashrateResponse
{
public:
    /*! @brief Default constructor. Constructs invalid hashrate response object. */
    HashrateResponse();
    HashrateResponse(const QJsonObject& jsonObject);
    HashrateResponse(const QJsonValue& jsonValue) :
        HashrateResponse(jsonValue.toObject()) {}

    /*! @brief Returns true if this HashrateResponse object contains valid information. HashrateResponse object is
     *         considered to be valid if all of its fields are also valid. See Hashrate::isValid method. */
    bool      isValid() const     { return m_day.isValid() && m_week.isValid() && m_mounth.isValid() &&
                                           m_threeMounth.isValid() && m_year.isValid(); }

    Hashrate  day() const         { return m_day; }
    Hashrate  week() const        { return m_week; }
    Hashrate  mounth() const      { return m_mounth; }
    Hashrate  threeMounth() const { return m_threeMounth; }
    Hashrate  year() const        { return m_year; }

private:
    Hashrate  m_day;
    Hashrate  m_week;
    Hashrate  m_mounth;
    Hashrate  m_threeMounth;
    Hashrate  m_year;
};

inline QDebug operator<< (QDebug dbg, const HashrateResponse& hashrateResponse)
{
    dbg.nospace() << qUtf8Printable(QString("HashrateResponse(day.value()=%1; week.value()=%2; mounth.value()=%3; threeMounth.value()=%4; year.value()=%5)")
                                    .arg(hashrateResponse.day().value())
                                    .arg(hashrateResponse.week().value())
                                    .arg(hashrateResponse.mounth().value())
                                    .arg(hashrateResponse.threeMounth().value())
                                    .arg(hashrateResponse.year().value()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_HASHRATERESPONSE_H
