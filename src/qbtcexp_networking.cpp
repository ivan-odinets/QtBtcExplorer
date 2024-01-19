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

#include "qbtcexp_networking.h"

#include <QEventLoop>
#include <QNetworkReply>
#include <QTimer>
#include <QUrlQuery>

namespace QtBtcExplorer {

Networking::Networking(QObject* parent) :
    QObject(parent),
    m_host{"https://bitcoinexplorer.org"},
    m_timeout(0)
{}

QByteArray Networking::get(const QString& urlPart)
{
    QNetworkRequest req;
    QUrl url(m_host + QLatin1String("/api") + urlPart);
    req.setUrl(url);

    QEventLoop waitLoop;

    if (m_timeout != 0)
        QTimer::singleShot(m_timeout,&waitLoop,&QEventLoop::quit);

    QNetworkReply *reply = m_nam.get(req);
    QObject::connect(reply, &QNetworkReply::finished, &waitLoop, &QEventLoop::quit);

    waitLoop.exec();
    if (reply->isRunning())
        reply->abort();

    QByteArray result = reply->readAll();
    reply->deleteLater();
    return result;
}

} //namespace QtBtcExplorer
