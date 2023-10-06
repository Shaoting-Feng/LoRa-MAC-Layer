#-------------------------------------------------
#
# Project created by QtCreator 2022-09-17T19:18:55
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SD-PHY_Front_End
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    domain6.cpp \
    domain10.cpp \
    domain11.cpp \
    domain12.cpp \
    domain13.cpp \
    domain14.cpp \
    domain7.cpp \
    domain15.cpp \
    domain8.cpp \
    domain9.cpp

HEADERS  += dialog.h \
    domain6.h \
    domain10.h \
    domain11.h \
    domain12.h \
    domain13.h \
    domain14.h \
    domain7.h \
    domain15.h \
    domain8.h \
    domain9.h

FORMS    += dialog.ui \
    domain6.ui \
    domain10.ui \
    domain11.ui \
    domain12.ui \
    domain13.ui \
    domain14.ui \
    domain7.ui \
    domain15.ui \
    domain8.ui \
    domain9.ui
#UI_DIR = ../build-SD-PHY_Front_End-Desktop_Qt_5_9_0_MinGW_32bit-Debug
