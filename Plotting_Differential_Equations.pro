#-------------------------------------------------
#
# Project created by QtCreator 2018-10-15T20:36:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Plotting_Differential_Equations
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
        mainwindow.cpp \
    eulers_method.cpp \
    abstract_computation_method.cpp \
    improved_eulers_method.cpp \
    eulers_approximation_curve.cpp \
    approximation_curve.cpp \
    eulers_error_curve.cpp \
    improved_eulers_approximation_curve.cpp \
    improved_eulers_error_curve.cpp

HEADERS += \
        mainwindow.h \
    eulers_method.h \
    abstract_computation_method.h \
    improved_eulers_method.h \
    eulers_approximation_curve.h \
    approximation_curve.h \
    eulers_error_curve.h \
    improved_eulers_approximation_curve.h \
    improved_eulers_error_curve.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += qwt
