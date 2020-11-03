QT += testlib
QT -= gui

TARGET = client-tests
TEMPLATE = app

CONFIG += c++17
CONFIG += console
CONFIG -= app_bundle

SOURCES +=  tst_testcase1.cpp

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)
