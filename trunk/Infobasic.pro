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
    aboutdialog.cpp \
    echoserver.cpp \
    scanner.cpp

HEADERS  += mainwindow.h \
    IForm.h \
    echoclient.h \
    aboutdialog.h \
    echoserver.h \
    scanner.h

FORMS    += mainwindow.ui \
    echoclient.ui \
    aboutdialog.ui \
    echoserver.ui \
    scanner.ui

RESOURCES += \
    resources.qrc
