#-------------------------------------------------
#
# Project created by QtCreator 2013-07-07T18:20:08
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vge
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    renderarea.cpp \
    colors.cpp

HEADERS  += window.h \
    renderarea.h \
    colors.h

FORMS    += window.ui

RESOURCES += \
    vge.qrc
