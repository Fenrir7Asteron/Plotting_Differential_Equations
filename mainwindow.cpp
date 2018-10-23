#include <qwt_plot.h>
#include <qwt_plot_grid.h>

#include <qwt_legend.h>

#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

#include <qwt_plot_magnifier.h>

#include <qwt_plot_panner.h>

#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>

#include <utility>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "eulers_approximation_curve.h"
#include "improved_eulers_approximation_curve.h"
#include "runge_kutta_approximation_curve.h"
#include "eulers_error_curve.h"
#include "improved_eulers_error_curve.h"
#include "runge_kutta_error_curve.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QwtPlot *d_plot = new QwtPlot( this );
    setCentralWidget(d_plot);

    d_plot->setTitle("Approximate plot of DE"); // name of the plot
    d_plot->setCanvasBackground(Qt::white); // background color

    // parameters of axises
    d_plot->setAxisTitle(QwtPlot::yLeft, "Y");
    d_plot->setAxisTitle(QwtPlot::xBottom, "X");

    d_plot->setAxisScale(QwtPlot::yLeft, 0, 40);

    d_plot->insertLegend( new QwtLegend() );

    // turn on a grid
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen(QPen( Qt::gray, 2 )); // color and thickness of lines
    grid->attach( d_plot ); // attach grid to a plot

    // create curves for different approximations and attach them to the plot
    eulers_approximation_curve *euler_curve = new eulers_approximation_curve();
    euler_curve->attach_to_plot(d_plot);

    improved_eulers_approximation_curve *improved_euler_curve = new improved_eulers_approximation_curve();
    improved_euler_curve->attach_to_plot(d_plot);

    runge_kutta_approximation_curve *runge_kutta_curve = new runge_kutta_approximation_curve();
    runge_kutta_curve->attach_to_plot(d_plot);

    // create curves for different approximation errors and attach them to the plot
    eulers_error_curve *euler_error = new eulers_error_curve();
    euler_error->attach_to_plot(d_plot);

    improved_eulers_error_curve *improved_euler_error = new improved_eulers_error_curve();
    improved_euler_error->attach_to_plot(d_plot);

    runge_kutta_error_curve *runge_kutta_error = new runge_kutta_error_curve();
    runge_kutta_error->attach_to_plot(d_plot);

    //enable scaling with rotation of middle mouse button
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(d_plot->canvas());
    magnifier->setMouseButton(Qt::MiddleButton);

    //enable dragging of plot with left mouse button
    QwtPlotPanner *d_panner = new QwtPlotPanner( d_plot->canvas() );
    d_panner->setMouseButton( Qt::LeftButton );

    //enable coordinate showing with perpendicular lines during dragging
    QwtPlotPicker *d_picker =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // association with axises
    QwtPlotPicker::CrossRubberBand, // type of showed lines during dragging (perpendicular in this case)
    QwtPicker::ActiveOnly, // show only on event trigger (dragging with LMB in this case)
    d_plot->canvas() ); // association with field

    // color of showed lines
    d_picker->setRubberBandPen( QColor( Qt::darkGray ) );

    // color of showed coordinates
    d_picker->setTrackerPen( QColor( Qt::black ) );

    // attach new state machine that will check whether we drag plot or not
    d_picker->setStateMachine( new QwtPickerDragPointMachine() );
}

MainWindow::~MainWindow()
{
    delete ui;
}
