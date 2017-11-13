#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T22:03:52
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serial
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    curvewidget.cpp \
    titlecurvewidget.cpp \
    quadglwidget.cpp \
    modelobj.cpp

HEADERS  += mainwindow.h \
        ui_mainwindow.h \
    curvewidget.h \
    titlecurvewidget.h \
    quadglwidget.h \
    modelobj.h

FORMS    += titlecurvewidget.ui


RESOURCES += \
    icon.qrc \
    shaders.qrc \
    model.qrc

CONFIG +=console

DISTFILES +=
