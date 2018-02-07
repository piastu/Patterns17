#-------------------------------------------------
#
# Project created by QtCreator 2018-01-15T16:55:04
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11 c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VidEff
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    clip.cpp \
    track.cpp \
    filter.cpp \
    clipsource.cpp \
    transition.cpp \
    frame.cpp \
    util.cpp \
    effectlib.cpp \
    transitionfactory.cpp \
    filterfactory.cpp \
    mediaproject.cpp \
    dialognewproject.cpp \
    fltpropslider.cpp \
    dialogaddclip.cpp \
    dialogaddtransition.cpp \
    dialogaddfilter.cpp

HEADERS  += mainwindow.h \
    clip.h \
    track.h \
    filter.h \
    clipsource.h \
    transition.h \
    frame.h \
    util.h \
    effectlib.h \
    transitionfactory.h \
    filterfactory.h \
    defs.h \
    mediaproject.h \
    dialognewproject.h \
    fltpropslider.h \
    dialogaddclip.h \
    dialogaddtransition.h \
    dialogaddfilter.h

FORMS    += mainwindow.ui \
    dialognewproject.ui \
    fltpropslider.ui \
    dialogaddclip.ui \
    dialogaddtransition.ui \
    dialogaddfilter.ui
