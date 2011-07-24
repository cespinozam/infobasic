#-------------------------------------------------
#
# Project created by QtCreator 2011-07-09T15:51:09
#
#-------------------------------------------------

QT       += core gui network

TARGET = Infobasic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    echoclient.cpp \
    qtudpclient.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    IForm.h \
    echoclient.h \
    qtudpclient.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    echoclient.ui \
    aboutdialog.ui
