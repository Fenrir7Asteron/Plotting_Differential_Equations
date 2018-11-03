#-------------------------------------------------
#
# Project created by QtCreator 2018-10-15T20:36:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Plotting_Differential_Equations
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += computation_method_headers \
    curve_headers


SOURCES += \
    computation_method_sources/abstract_computation_method.cpp \
    computation_method_sources/eulers_method.cpp \
    computation_method_sources/improved_eulers_method.cpp \
    computation_method_sources/runge_kutta_method.cpp \
    computation_method_sources/exact_method.cpp \
    curve_sources/approximation_curve.cpp \
    curve_sources/eulers_approximation_curve.cpp \
    curve_sources/eulers_error_curve.cpp \
    curve_sources/improved_eulers_approximation_curve.cpp \
    curve_sources/improved_eulers_error_curve.cpp \
    curve_sources/runge_kutta_approximation_curve.cpp \
    curve_sources/runge_kutta_error_curve.cpp \
    curve_sources/exact_solution_curve.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    computation_method_headers/abstract_computation_method.h \
    computation_method_headers/eulers_method.h \
    computation_method_headers/improved_eulers_method.h \
    computation_method_headers/runge_kutta_method.h \
    computation_method_headers/exact_method.h \
    curve_headers/approximation_curve.h \
    curve_headers/eulers_approximation_curve.h \
    curve_headers/eulers_error_curve.h \
    curve_headers/improved_eulers_approximation_curve.h \
    curve_headers/improved_eulers_error_curve.h \
    curve_headers/runge_kutta_approximation_curve.h \
    curve_headers/runge_kutta_error_curve.h \
    curve_headers/exact_solution_curve.h \
    mainwindow.h \

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += qwt
