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
    deletedialog.cpp \
    errorpopup.cpp \
    selecterror.cpp

HEADERS  += mainwindow.h \
    addpopup.h \
    deletedialog.h \
    book.h \
    errorpopup.h \
    selecterror.h

FORMS    += mainwindow.ui \
    addpopup.ui \
    deletedialog.ui \
    errorpopup.ui \
    selecterror.ui
