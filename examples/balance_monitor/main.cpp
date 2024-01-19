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

#include <QCoreApplication>

#include "QtBtcExplorer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QtBtcExplorer::API explorer;

    // If needed - setup a proxy
    explorer.setProxy(QNetworkProxy(QNetworkProxy::Socks5Proxy,"localhost",9050));

    // If needed - set api host
    explorer.setApiHost("http://btcexpz7xlwrqknqw6p3bok6shf73qtkd6zxct4x4qta2ktvh7ntprad.onion/");

    QtBtcExplorer::Address addres = explorer.getAddress("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");
    if (explorer.errorCode() != QtBtcExplorer::API::NoError) {
        qDebug() << "This should not happen!";
    }
    qDebug() << "Address="<<addres;

    return a.exec();
}
