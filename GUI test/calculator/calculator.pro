#-------------------------------------------------
#
# Project created by QtCreator 2016-06-05T17:59:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Scanner.cpp \
    Printer.cpp \
    Calculationer.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    Printer.h \
    Scanner.h \
    Calculationer.h \
    dialog.h

FORMS    += mainwindow.ui

RESOURCES += \
    dialog.qrc
