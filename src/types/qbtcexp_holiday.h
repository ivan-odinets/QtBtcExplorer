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

#ifndef QT_BTCEXPLORER_HOLIDAY_H
#define QT_BTCEXPLORER_HOLIDAY_H

#include <QDate>
#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>

#include "qbtcexp_json_objectslist.h"

namespace QtBtcExplorer {

/*! @class Holiday src/types/qbtcexp_holiday.h
 *  @brief A list of such objects is returned either as a reply of API::allHolidays method ( /api/holidays/all ). And it
 *         is present as one of the fields of API::getTodayHoliday and API::getHoliday methods ( /api/holidays/today
 *         and /api/holidays/$DAY ). See HolidayAtDate class.
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class Holiday
{
public:
    Holiday();
    Holiday(const QJsonObject& jsonObject);
    Holiday(const QJsonValue& jsonValue) :
        Holiday(jsonValue.toObject()) {}

    bool isValid() const { return (!m_name.isEmpty()) && (m_date.isValid()); }

    QString name() const { return m_name; }
    QDate   date() const { return m_date; }
    QString desc() const { return m_desc; }

private:
    QString m_name;
    QDate   m_date;
    QString m_desc;
};

inline QDebug operator<< (QDebug dbg, const Holiday& holiday)
{
    dbg.nospace() << qUtf8Printable(QString("Holiday(name=%1; date=%2; desc=%3)")
                                    .arg(holiday.name())
                                    .arg(holiday.date().toString(Qt::ISODate))
                                    .arg(holiday.desc()));

    return dbg.maybeSpace();
}

/*! @typedef HolidayList
 *  @brief This is a list of Holiday objects. It is returned by method API::allHolidays ( /api/holidays/all ). And it
 *         is present as one of the fields of API::getTodayHoliday and API::getHoliday methods ( /api/holidays/today
 *         and /api/holidays/$DAY ). See HolidayAtDate class. Nothing more than a QList with some extra constructors
 *         (JsonObjectsList).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

typedef JsonObjectsList<Holiday> HolidayList;

inline QDebug operator<< (QDebug dbg, const HolidayList& holidayList)
{
    dbg.nospace() << qUtf8Printable(QString("HolidayList(count=%1)")
                   .arg(holidayList.count()));

    return dbg.maybeSpace();
}



} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_HOLIDAY_H
