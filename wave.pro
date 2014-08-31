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
    displayer.cpp \
    sinewave.cpp

HEADERS  += mainwindow.h \
    displayer.h \
    sinewave.h

FORMS    += mainwindow.ui
