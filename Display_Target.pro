#-------------------------------------------------
#
# Project created by QtCreator 2015-12-25T22:07:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Display_Target
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    q_button.cpp \
    ../gpp_qt/wfunction/wfunction.cpp \
    listen_stdin.cpp

HEADERS  += mainwindow.h \
    q_button.h \
    ../gpp_qt/wfunction/wfunction.h \
    listen_stdin.h

FORMS    += mainwindow.ui
