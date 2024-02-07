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

#ifndef QT_BTCEXPLORER_HOLIDAYATDATE_H
#define QT_BTCEXPLORER_HOLIDAYATDATE_H

#include "qbtcexp_holiday.h"

namespace QtBtcExplorer {

/*! @class HolidayAtDate src/types/qbtcexp_holidayatdate.h
 *  @brief Object of this class represents reply of API::getTodayHoliday and API::getHoliday methods ( /api/holidays/today
 *         and /api/holidays/$DAY ).
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class HolidayAtDate
{
public:
    /*! @brief Default constructor. Constructs invalid object. */
    HolidayAtDate();
    HolidayAtDate(const QJsonObject& jsonObject);
    HolidayAtDate(const QJsonValue& jsonValue) :
        HolidayAtDate(jsonValue.toObject()) {}

    /*! @brief Returns true if this HolidayAtDate object is containing valid information. HolidayAtDate object is
     *         considered to be valid if dateString() is not empty. */
    bool           isValid() const     { return !m_dateString.isEmpty(); }

    QString        dateString() const  { return m_dateString; }
    HolidayList    holidays() const    { return m_holidays; }

private:
    QString        m_dateString;
    HolidayList    m_holidays;
};

inline QDebug operator<< (QDebug dbg, const HolidayAtDate& holidayAtDate)
{
    dbg.nospace() << qUtf8Printable(QString("HolidayAtDate(date=%1; holidays.count()=%2)")
                                    .arg(holidayAtDate.dateString())
                                    .arg(holidayAtDate.holidays().count()));

    return dbg.maybeSpace();
}

} // namespace QtBtcExplorer

#endif // HOLIDAYATDATE_H
