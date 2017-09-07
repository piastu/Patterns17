#-------------------------------------------------
#
# Project created by QtCreator 2016-07-02T20:52:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = practica
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    room.cpp \
    humen.cpp \
    fire.cpp \
    dialog.cpp \
    dialoguse.cpp

HEADERS  += mainwindow.h \
    room.h \
    humen.h \
    fire.h \
    dialog.h \
    dialoguse.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialoguse.ui
