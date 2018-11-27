QT += core
QT -= gui



#TARGET = main.cpp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    useandfindobj.cpp

   INCLUDEPATH += C://opencv//build//include

    CONFIG(debug,debug|release){
        #debug
        LIBS += -LC://opencv//build//x64//vc15//lib -lopencv_world344d
    } else {
        #release
        LIBS += -LC://opencv//build//x64//vc15//lib -lopencv_world344
    }

HEADERS += \
    useandfindobj.h
