#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T19:47:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CanteenModel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderwidget.cpp \
    model.cpp \
    entity.cpp \
    dish.cpp \
    person.cpp \
    util.cpp \
    item.cpp \
    dialogdish.cpp

HEADERS  += mainwindow.h \
    renderwidget.h \
    model.h \
    entity.h \
    dish.h \
    person.h \
    util.h \
    item.h \
    dialogdish.h

FORMS    += mainwindow.ui \
    dialogdish.ui

CONFIG += c++11
