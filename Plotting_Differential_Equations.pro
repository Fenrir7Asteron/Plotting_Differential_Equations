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

INCLUDEPATH += computation_method_headers \
    curve_headers


SOURCES += \
    computation_method_sources/abstract_computation_method.cpp \
    computation_method_sources/eulers_method.cpp \
    computation_method_sources/improved_eulers_method.cpp \
    computation_method_sources/runge_kutta_method.cpp \
    curve_sources/approximation_curve.cpp \
    curve_sources/eulers_approximation_curve.cpp \
    curve_sources/eulers_error_curve.cpp \
    curve_sources/improved_eulers_approximation_curve.cpp \
    curve_sources/improved_eulers_error_curve.cpp \
    main.cpp \
    mainwindow.cpp \
    curve_sources/runge_kutta_approximation_curve.cpp \
    curve_sources/runge_kutta_error_curve.cpp

HEADERS += \
    computation_method_headers/abstract_computation_method.h \
    computation_method_headers/eulers_method.h \
    computation_method_headers/improved_eulers_method.h \
    computation_method_headers/runge_kutta_method.h \
    curve_headers/approximation_curve.h \
    curve_headers/eulers_approximation_curve.h \
    curve_headers/eulers_error_curve.h \
    curve_headers/improved_eulers_approximation_curve.h \
    curve_headers/improved_eulers_error_curve.h \
    mainwindow.h \
    curve_headers/runge_kutta_approximation_curve.h \
    curve_headers/runge_kutta_error_curve.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += qwt
