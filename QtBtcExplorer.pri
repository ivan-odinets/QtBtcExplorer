INCLUDEPATH += $$PWD

DEFINES     += QTBTCEXPLORER_VERSION='\\"0.0.1\\"'

QT          += core network

CONFIG      += c++17

OTHER_FILES += \
    $$PWD/README.md

HEADERS += \
    $$PWD/QtBtcExplorer.h \
    $$PWD/src/qbtcexp_api.h \
    $$PWD/src/qbtcexp_networking.h \
    $$PWD/src/types/qbtcexp_address.h \
    $$PWD/src/types/qbtcexp_btc.h \
    $$PWD/src/types/qbtcexp_btcprice.h \
    $$PWD/src/types/qbtcexp_quote.h \
    $$PWD/src/types/qtbtcexp_json_objectslist.h

SOURCES += \
    $$PWD/src/qbtcexp_api.cpp \
    $$PWD/src/qbtcexp_networking.cpp \
    $$PWD/src/types/qbtcexp_address.cpp \
    $$PWD/src/types/qbtcexp_btcprice.cpp \
    $$PWD/src/types/qbtcexp_quote.cpp
