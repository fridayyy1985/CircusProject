QT += core gui sql widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    artistsdialog.cpp \
    categoriesdialog.cpp \
    databasemanager.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    showsdialog.cpp \
    venuesdialog.cpp \
    worklogdialog.cpp

HEADERS += \
    artistsdialog.h \
    categoriesdialog.h \
    databasemanager.h \
    logindialog.h \
    mainwindow.h \
    showsdialog.h \
    venuesdialog.h \
    worklogdialog.h

FORMS += \
    artistsdialog.ui \
    categoriesdialog.ui \
    logindialog.ui \
    mainwindow.ui \
    showsdialog.ui \
    venuesdialog.ui \
    worklogdialog.ui

TRANSLATIONS += \
    circus_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
