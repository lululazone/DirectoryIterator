QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acommand.cpp \
    acommandwithbaseoption.cpp \
    add.cpp \
    clear.cpp \
    databasemanager.cpp \
    diskscanner.cpp \
    get.cpp \
    indexer.cpp \
    inputmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    outputexec.cpp \
    push.cpp \
    search.cpp

HEADERS += \
    acommand.h \
    acommandwithbaseoption.h \
    add.h \
    clear.h \
    databasemanager.h \
    diskscanner.h \
    get.h \
    indexer.h \
    inputmanager.h \
    mainwindow.h \
    outputexec.h \
    push.h \
    search.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
