#-------------------------------------------------
#
# Project created by QtCreator 2022-03-05T16:53:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalAndSlots
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    teacher.cpp \
    student.cpp

HEADERS  += widget.h \
    teacher.h \
    student.h

FORMS    += widget.ui
