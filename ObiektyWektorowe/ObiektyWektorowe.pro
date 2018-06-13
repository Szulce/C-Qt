#-------------------------------------------------
#
# Project created by QtCreator 2018-05-23T14:37:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ObiektyWektorowe
TEMPLATE = app

CONFIG += c++11
SOURCES += main.cpp\
        mainwindow.cpp \
    obrazek.cpp

HEADERS  += mainwindow.h \
    obrazek.h \
    point.h

FORMS    += mainwindow.ui
