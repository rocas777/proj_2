TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Address.cpp \
        Agency.cpp  \
        Client.cpp  \
        Date.cpp  \
        Menus.cpp  \
        Packet.cpp  \
        main.cpp\
        funcs.cpp

HEADERS += \
        defs.h \
        Address.h  \
        Agency.h  \
        Client.h  \
        Date.h  \
        Menus.h  \
        Packet.h\
        funcs.h

DISTFILES += \
    clients.txt\
    packets.txt\
    agency.txt
