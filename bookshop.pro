#-------------------------------------------------
#
# Project created by QtCreator 2022-12-24T11:46:57
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bookshop
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        add.cpp \
        booklist.cpp \
        edit.cpp \
        main.cpp \
        bookshopmain.cpp \
        md.cpp \
        menu.cpp

HEADERS += \
        add.h \
        booklist.h \
        bookshopmain.h \
        edit.h \
        md.h \
        menu.h

FORMS += \
        add.ui \
        booklist.ui \
        bookshopmain.ui \
        edit.ui \
        md.ui \
        menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
