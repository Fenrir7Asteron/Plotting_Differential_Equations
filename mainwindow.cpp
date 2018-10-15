#include <qwt_plot.h>
#include <qwt_plot_grid.h>

#include <qwt_legend.h>

#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

#include <qwt_plot_magnifier.h>

#include <qwt_plot_panner.h>

#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "eulers_method.h"

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


    // Включить сетку
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
    grid->attach( d_plot ); // добавить сетку к полю графика

    // Кривая
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setTitle( "Euler's method result" );
    curve->setPen( Qt::blue, 5 ); // цвет и толщина кривой
    curve->setRenderHint
            ( QwtPlotItem::RenderAntialiased, true ); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
    curve->setSymbol( symbol );

    // Добавить точки на ранее созданную кривую
    eulers_method *euler = new eulers_method(QPointF(X0, Y0), STEP, BORDER_X);
    QPolygonF points = euler->find_approximate_curve();

    curve->setSamples( points ); // ассоциировать набор точек с кривой

    curve->attach( d_plot ); // отобразить кривую на графике

    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(d_plot->canvas());
    // клавиша, активирующая приближение/удаление
    magnifier->setMouseButton(Qt::MiddleButton);

    QwtPlotPanner *d_panner = new QwtPlotPanner( d_plot->canvas() );
    // клавиша, активирующая перемещение
    d_panner->setMouseButton( Qt::LeftButton );

    // Включить отображение координат курсора и двух перпендикулярных
    // линий в месте его отображения
    // #include <qwt_plot_picker.h>

     // настройка функций
    QwtPlotPicker *d_picker =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
    QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
    QwtPicker::ActiveOnly, // включение/выключение
    d_plot->canvas() ); // ассоциация с полем

    // Цвет перпендикулярных линий
    d_picker->setRubberBandPen( QColor( Qt::gray ) );

    // цвет координат положения указателя
    d_picker->setTrackerPen( QColor( Qt::black ) );

    // непосредственное включение вышеописанных функций
    d_picker->setStateMachine( new QwtPickerDragPointMachine() );
}

MainWindow::~MainWindow()
{
    delete ui;
}
