#-------------------------------------------------
#
# Project created by QtCreator 2016-08-06T14:36:42
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = song_loader
TEMPLATE = app


SOURCES += main.cpp\
        songloader.cpp

HEADERS  += songloader.h \
    observable.h \
    i_threadable.h \
    i_song_loader_observer.h

FORMS    += songloader.ui
