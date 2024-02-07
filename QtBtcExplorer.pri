INCLUDEPATH += $$PWD

DEFINES     += QTBTCEXPLORER_VERSION='\\"0.0.2\\"'

QT          += core network

CONFIG      += c++17

OTHER_FILES += \
    $$PWD/README.md

HEADERS += \
    $$PWD/QtBtcExplorer.h \
    $$PWD/src/qbtcexp_api.h \
    $$PWD/src/qbtcexp_global.h \
    $$PWD/src/qbtcexp_networking.h \
    $$PWD/src/types/qbtcexp_address.h \
    $$PWD/src/types/qbtcexp_block.h \
    $$PWD/src/types/qbtcexp_blockheader.h \
    $$PWD/src/types/qbtcexp_btc.h \
    $$PWD/src/types/qbtcexp_btcprice.h \
    $$PWD/src/types/qbtcexp_btcsupply.h \
    $$PWD/src/types/qbtcexp_chaintip.h \
    $$PWD/src/types/qbtcexp_hashrateresponse.h \
    $$PWD/src/types/qbtcexp_holiday.h \
    $$PWD/src/types/qbtcexp_holidayatdate.h \
    $$PWD/src/types/qbtcexp_json_objectslist.h \
    $$PWD/src/types/qbtcexp_marketcap.h \
    $$PWD/src/types/qbtcexp_mempoolfees.h \
    $$PWD/src/types/qbtcexp_mempoolsummary.h \
    $$PWD/src/types/qbtcexp_miner.h \
    $$PWD/src/types/qbtcexp_minersummary.h \
    $$PWD/src/types/qbtcexp_minersummaryresponse.h \
    $$PWD/src/types/qbtcexp_nextblock.h \
    $$PWD/src/types/qbtcexp_nexthalving.h \
    $$PWD/src/types/qbtcexp_overallminersummary.h \
    $$PWD/src/types/qbtcexp_publickeydetails.h \
    $$PWD/src/types/qbtcexp_quote.h \
    $$PWD/src/types/qbtcexp_relatedkey.h \
    $$PWD/src/types/qbtcexp_sats.h \
    $$PWD/src/types/qbtcexp_transaction.h \
    $$PWD/src/types/qbtcexp_transactioninclusionstatus.h \
    $$PWD/src/types/qbtcexp_txhistory.h \
    $$PWD/src/types/qbtcexp_txhistoryrequest.h \
    $$PWD/src/types/qbtcexp_txidlist.h \
    $$PWD/src/types/qbtcexp_utxoset.h \
    $$PWD/src/types/qbtcexp_utxosetblockinfo.h \
    $$PWD/src/types/qbtcexp_utxounspendables.h

SOURCES += \
    $$PWD/src/qbtcexp_api.cpp \
    $$PWD/src/qbtcexp_networking.cpp \
    $$PWD/src/types/qbtcexp_address.cpp \
    $$PWD/src/types/qbtcexp_block.cpp \
    $$PWD/src/types/qbtcexp_blockheader.cpp \
    $$PWD/src/types/qbtcexp_btc.cpp \
    $$PWD/src/types/qbtcexp_btcprice.cpp \
    $$PWD/src/types/qbtcexp_btcsupply.cpp \
    $$PWD/src/types/qbtcexp_chaintip.cpp \
    $$PWD/src/types/qbtcexp_hashrateresponse.cpp \
    $$PWD/src/types/qbtcexp_holiday.cpp \
    $$PWD/src/types/qbtcexp_holidayatdate.cpp \
    $$PWD/src/types/qbtcexp_marketcap.cpp \
    $$PWD/src/types/qbtcexp_mempoolfees.cpp \
    $$PWD/src/types/qbtcexp_mempoolsummary.cpp \
    $$PWD/src/types/qbtcexp_miner.cpp \
    $$PWD/src/types/qbtcexp_minersummary.cpp \
    $$PWD/src/types/qbtcexp_minersummaryresponse.cpp \
    $$PWD/src/types/qbtcexp_nextblock.cpp \
    $$PWD/src/types/qbtcexp_nexthalving.cpp \
    $$PWD/src/types/qbtcexp_overallminersummary.cpp \
    $$PWD/src/types/qbtcexp_publickeydetails.cpp \
    $$PWD/src/types/qbtcexp_quote.cpp \
    $$PWD/src/types/qbtcexp_relatedkey.cpp \
    $$PWD/src/types/qbtcexp_sats.cpp \
    $$PWD/src/types/qbtcexp_transaction.cpp \
    $$PWD/src/types/qbtcexp_transactioninclusionstatus.cpp \
    $$PWD/src/types/qbtcexp_txhistory.cpp \
    $$PWD/src/types/qbtcexp_txhistoryrequest.cpp \
    $$PWD/src/types/qbtcexp_txidlist.cpp \
    $$PWD/src/types/qbtcexp_utxoset.cpp \
    $$PWD/src/types/qbtcexp_utxosetblockinfo.cpp \
    $$PWD/src/types/qbtcexp_utxounspendables.cpp
