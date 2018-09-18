#-------------------------------------------------
#
# Project created by QtCreator 2018-07-27T07:43:21
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += xml

TARGET = Sim
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        server.cpp \
        NetworkPacket.cpp

HEADERS  += mainwindow.h \
         server.h \
         NetworkPacket.h

FORMS    += mainwindow.ui

RESOURCES +=
