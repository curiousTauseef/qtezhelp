#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T19:10:21
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtezhelp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helpdialog.cpp

HEADERS  += mainwindow.h \
    helpdialog.h

FORMS    += mainwindow.ui \
    helpdialog.ui

OTHER_FILES += \
    about.html \
    concept.html \
    help.html \
    index.html \
    main.html \
    measure.html \
    status.html \
    trigger.html \
    verthor.html \
    waveform.html \
    COPYING \
    help.css \
    LICENSE \
    qtezhelp.pro.user \
    README.md

RESOURCES += \
    qtezhelp.qrc
