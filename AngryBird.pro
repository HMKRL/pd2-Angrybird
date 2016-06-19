#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T16:15:37
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AngryBird
TEMPLATE = app
LIBS += -lBox2D


SOURCES += main.cpp\
        mainwindow.cpp \
    gameitem.cpp \
    movepoint.cpp \
    bird.cpp \
    planet.cpp \
    land.cpp \
    contectlistener.cpp \
    block.cpp \
    enemy.cpp \
    yellowbird.cpp \
    blackbird.cpp \
    flappybird.cpp \
    resultdialog.cpp \
    tnt.cpp

HEADERS  += mainwindow.h \
    gameitem.h \
    movepoint.h \
    bird.h \
    planet.h \
    land.h \
    contectlistener.h \
    block.h \
    enemy.h \
    yellowbird.h \
    blackbird.h \
    flappybird.h \
    resultdialog.h \
    tnt.h

FORMS    += mainwindow.ui \
    resultdialog.ui

RESOURCES += \
    resource.qrc
