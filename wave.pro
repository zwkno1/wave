#-------------------------------------------------
#
# Project created by QtCreator 2014-08-31T21:23:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wave
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sinewave.cpp \
    controlwidget.cpp \
    display.cpp

HEADERS  += mainwindow.h \
    sinewave.h \
    controlwidget.h \
    display.h

FORMS    += mainwindow.ui \
    controlwidget.ui
