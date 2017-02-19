QT += core
QT -= gui

CONFIG += c++11

TARGET = Cash
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    lru_cache.cpp \
    data_class.cpp

HEADERS += \
    lru_cache.h \
    data_class.h
