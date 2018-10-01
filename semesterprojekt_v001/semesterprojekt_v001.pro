QT += core
QT -= gui



#TARGET = main.cpp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp

INCLUDEPATH += C://opencv//release//install//include

LIBS += C://opencv//release//bin//libopencv_core343.dll
LIBS += C://opencv//release//bin//libopencv_highgui343.dll
LIBS += C://opencv//release//bin//libopencv_imgcodecs343.dll
LIBS += C://opencv//release//bin//libopencv_imgproc343.dll
LIBS += C://opencv//release//bin//libopencv_features2d343.dll
LIBS += C://opencv//release//bin//libopencv_calib3d343.dll

