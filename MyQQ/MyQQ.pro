#-------------------------------------------------
#
# Project created by QtCreator 2022-03-15T14:17:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyQQ
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    dialoglist.cpp \
    login.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    singin.cpp

HEADERS  += widget.h \
    dialoglist.h \
    login.h \
    tcpclient.h \
    tcpserver.h \
    singin.h

FORMS    += widget.ui \
    dialoglist.ui \
    login.ui \
    tcpclient.ui \
    tcpserver.ui \
    singin.ui

RESOURCES += \
    res.qrc
