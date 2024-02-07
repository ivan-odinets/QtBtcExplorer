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

#ifndef QT_BTCEXPLORER__GLOBAL_H
#define QT_BTCEXPLORER__GLOBAL_H

#include <QString>

namespace QtBtcExplorer {

enum Sort {
    Asc,
    Desc,
    Unknown
};

inline Sort stringToSort(const QString& string)
{
    if (string == QLatin1String("desc"))
        return Desc;
    if (string == QLatin1String("asc"))
        return Asc;

    return Unknown;
}

inline QString sortToSrting(Sort sort)
{
    switch (sort) {
    case Asc:
        return QLatin1String("asc");
    case Desc:
        return QLatin1String("desc");
    case Unknown:
        return QLatin1String("");
    }
    Q_ASSERT(false);
    return QString();
}

} // namespace QtBtcExplorer

#endif // QBTCEXP_GLOBAL_H
