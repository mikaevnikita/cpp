QT += core
QT -= gui
QT += widgets
CONFIG += c++11

TARGET = untitled1
CONFIG -= console
CONFIG -= app_bundle
CONFIG += release
TEMPLATE = app

SOURCES += main.cpp \
    my_window.cpp

HEADERS += \
    my_window.h
