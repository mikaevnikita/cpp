QT += core
QT += widgets
CONFIG += c++11
TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp indicator.cpp

HEADERS += indicator.h

RESOURCES += \
    resources.qrc

