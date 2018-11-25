#-------------------------------------------------
#
# Project created by QtCreator 2018-10-11T20:35:15
#
#-------------------------------------------------

CONFIG	 += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = bin/
TARGET = raytracing
TEMPLATE = app

INCLUDEPATH += include \
    += $$PWD/googletest/googletest \
    += $$PWD/googletest/googletest/include

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
#        src/Octree.cpp \
        src/Point.cpp \
        src/Ray.cpp \
        src/Triangle.cpp \
        src/Vector.cpp \
        src/mainwindow.cpp \
        src/Grid.cpp \
        src/Slot.cpp \
        src/DigitalDifferentialAnalyser.cpp \
        tests/TestPoint.cpp \
        tests/TestTriangle.cpp \
        tests/TestVector.cpp \
        tests/TestSlot.cpp \
        tests/TestDDA.cpp

HEADERS += \
#        include/Octree.h \
        include/Point.h \
        include/Ray.h \
        include/Triangle.h \
        include/Vector.h \
        include/mainwindow.h \
        include/Grid.h \
        include/DigitalDifferentialAnalyser.h \
        include/Slot.h

FORMS += \
        forms/mainwindow.ui

LIBS += -lgtest -L$$PWD/googletest/googletest/build/lib
