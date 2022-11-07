QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += ABDUMESSENGERLIB_LIBRARY
TARGET = abdumessengerlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    constants.cpp \
    database.cpp \
    databaseconstants.cpp \
    datastream.cpp \
    requestandreply.cpp \
    user.cpp

HEADERS += \
    AbduMessengerLib_global.h \
    constants.h \
    database.h \
    databaseconstants.h \
    datastream.h \
    requestandreply.h \
    user.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
