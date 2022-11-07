QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/../
LIBS += -L$$OUT_PWD/../AbduMessengerLib -labdumessengerlib \
        -L$$OUT_PWD/../AbduMessengerClient -labdumessengerclient

SOURCES += \
    src/button.cpp \
    src/connectionerrorpage.cpp \
    src/constants.cpp \
    src/label.cpp \
    src/lineedit.cpp \
    src/loginpage.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/passwordlineedit.cpp \
    src/uiloginpage.cpp \
    src/uinoconnectionpage.cpp

HEADERS += \
    src/button.h \
    src/connectionerrorpage.h \
    src/constants.h \
    src/label.h \
    src/lineedit.h \
    src/loginpage.h \
    src/mainwindow.h \
    src/passwordlineedit.h \
    src/uiloginpage.h \
    src/uinoconnectionpage.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/fonts.qrc \
    resources/images.qrc \
    resources/qrc.qrc
