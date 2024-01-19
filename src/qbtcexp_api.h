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

#ifndef QT_BTCEXPLORER_API_H
#define QT_BTCEXPLORER_API_H

#include <QObject>

#include "qbtcexp_networking.h"

#include "./src/types/qbtcexp_address.h"
#include "./src/types/qbtcexp_btcprice.h"
#include "./src/types/qbtcexp_quote.h"

namespace QtBtcExplorer {

/*! @class API "QtBtcExplorer.h"
 *  @brief API class provides interface to communicate with btc-rpc-explorer server
 *
 * @see https://bitcoinexplorer.org/api/docs
 * @see https://github.com/janoside/btc-rpc-explorer */

class API : public QObject
{
public:
    /*! @brief This enum holds information about what exactly error happened */
    enum Error {
        NoError,                       /*!< @brief If the request was successfull */
        NetworkError,                  /*!< @brief If during request some networking error happened */
        UnknownError                   /*!< @brief Corresponds to any other error which have happened */
    };

    explicit API(QObject* parent = nullptr);
    ~API() {}

    /*! @brief This method can be used to setup btc-rpc-explorer server address. If nothing was setup manualy by user -
     *         default server will be used (https://bitcoinexplorer.org/) */
    void      setApiHost(const QString& newHost)      { m_net.setApiHost(newHost); }

    /*! @brief This method returns btc-rpc-explorer server address with which this API object is communicating. */
    QString   apiHost() const                         { return m_net.apiHost(); }

    /*! @brief This method can be used to configure proxy, through which communication with btc-rpc-explorer server will
     *         be done
     *  @param QNetworkProxy newProxy - new proxy configuration */
    void           setProxy(const QNetworkProxy& newProxy) { m_net.setProxy(newProxy); }

    /*! @brief This method can be used to get information about currently configured proxy.
     *  @return QNetworkProxy object, representing current proxy configuration */
    QNetworkProxy  proxy() const                           { return m_net.proxy(); }

    /*! @brief This method allows to setup a timeout for requests to btc-rpc-explorer server.
     *  @param quint32 timeout (in mseconds) after which request will be aborted. Pass 0 to disable timeout */
    void           setRequestTimeout(quint32 msec)         { m_net.setRequestTimeout(msec); }

    /*! @brief This method returns information about timeout */
    quint32        requestTimeout() const                  { return m_net.requestTimeout(); }

    /*! @brief This method can be used to get information about errors.
     *  @details If the last request to btc-rpc-explorer server failed due to whatever reason - this method should return
     *           value from enum QtBtcEcplorer::API::Error which is representing occured error. If the last request was
     *           successfull - this method should return QtBtcExplorer::API::NoError value. */
    Error          errorCode() const                       { return m_errorCode; }

    /// @name Implemented API methods
    /// @{

    /*! @brief Returns a summary of data pertaining to the given address.
     *  @details The output of this call will depend heavily on the configured 'Address API' (see .env-sample file).
     *           If an Address API is configured, transactions related to the given address will be returned (the below
     *           optional parameters apply to those transactions).
     * @see https://bitcoinexplorer.org/api/docs */
    Address getAddress(const QString& btcAddress);

    /*! @brief Returns the price of 1 BTC, in USD, EUR, GBP, and XAU
     *
     * @see https://bitcoinexplorer.org/api/docs */
    BtcPrice price();

    /*! @brief Returns the full curated list of Bitcoin quotes.
     *
     * @see https://bitcoinexplorer.org/api/docs */
    QuoteList allQuotes();

    /*! @brief Returns a random Bitcoin quote from the curated list.
     *
     * @see https://bitcoinexplorer.org/api/docs */
    Quote randomQuote();

    /*! @brief Returns the Bitcoin quote with the given index from the curated list.
     *
     * @see https://bitcoinexplorer.org/api/docs */
    Quote quote(int index);

    /*! @brief Returns the semantic version of the public API, which is maintained separate from the app version.
     *
     * @see https://bitcoinexplorer.org/api/docs */
    QString version();

    /// @}

private:
    Networking m_net;
    Error      m_errorCode;

    template<class C>
    C makeApiCall(const QString& query);
};

} // namespace QtBtcExplorer

#endif // QT_BTCEXPLORER_API_H
