#-------------------------------------------------
#
# Project created by QtCreator 2018-11-27T12:03:07
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = ThrowBot
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
        main.cpp \
        throwbot.cpp \
        imageprocessing.cpp

HEADERS += \
        throwbot.h \
        imageprocessing.h

FORMS += \
        throwbot.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# For OpenCV
INCLUDEPATH += C://opencv//build//include

    CONFIG(debug,debug|release){
        #debug
        LIBS += -LC://opencv//build//x64//vc15//lib -lopencv_world344d
    } else {
        #release
        LIBS += -LC://opencv//build//x64//vc15//lib -lopencv_world344
    }
