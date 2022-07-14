#-------------------------------------------------
#
# Project created by QtCreator 2022-03-11T14:44:17
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 05_Tcp
TEMPLATE = app


SOURCES += main.cpp widget.cpp client.cpp

HEADERS  += widget.h client.h

FORMS    += widget.ui client.ui
