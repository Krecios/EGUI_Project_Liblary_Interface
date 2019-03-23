#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T13:05:34
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addpopup.cpp \
    editpopup.cpp \
    deletedialog.cpp \
    errorpopup.cpp

HEADERS  += mainwindow.h \
    addpopup.h \
    editpopup.h \
    deletedialog.h \
    book.h \
    errorpopup.h

FORMS    += mainwindow.ui \
    addpopup.ui \
    editpopup.ui \
    deletedialog.ui \
    errorpopup.ui
