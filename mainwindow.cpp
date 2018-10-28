#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setToolBar1();
    setToolBar2();

    d_plot = new QwtPlot( this );
    setCentralWidget(d_plot);

    d_plot->setMinimumWidth(700);

    d_plot->setTitle("Approximate plot of DE"); // name of the plot
    d_plot->setCanvasBackground(Qt::white); // background color

    // parameters of axises
    d_plot->setAxisTitle(QwtPlot::yLeft, "Y");
    d_plot->setAxisTitle(QwtPlot::xBottom, "X");

    d_plot->setAxisScale(QwtPlot::yLeft, 0, 40);

    QwtLegend *legend = new QwtLegend();
    d_plot->insertLegend( legend, QwtPlot::BottomLegend );

    // turn on a grid
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen(QPen( Qt::gray, 2 )); // color and thickness of lines
    grid->attach( d_plot ); // attach grid to a plot

    // create curves for different approximations and attach them to the plot
    euler_curve = new eulers_approximation_curve();
    euler_curve->attach_to_plot(d_plot);

    improved_euler_curve = new improved_eulers_approximation_curve();
    improved_euler_curve->attach_to_plot(d_plot);

    runge_kutta_curve = new runge_kutta_approximation_curve();
    runge_kutta_curve->attach_to_plot(d_plot);

    // create curves for different approximation errors and attach them to the plot
    euler_error = new eulers_error_curve();
    euler_error->attach_to_plot(d_plot);

    improved_euler_error = new improved_eulers_error_curve();
    improved_euler_error->attach_to_plot(d_plot);

    runge_kutta_error = new runge_kutta_error_curve();
    runge_kutta_error->attach_to_plot(d_plot);

    // save curves to an array in order to update initial values later
    array_of_curves[0] = euler_curve;
    array_of_curves[1] = improved_euler_curve;
    array_of_curves[2] = runge_kutta_curve;
    array_of_curves[3] = euler_error;
    array_of_curves[4] = improved_euler_error;
    array_of_curves[5] = runge_kutta_error;

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

    // create check boxes for toggling curves;
    box1 = new QCheckBox( toolBar1 );
    add_box(box1, "Euler approximation");
    connect(box1, SIGNAL(toggled(bool)), SLOT(toggle_euler_approximation(bool)));

    box2 = new QCheckBox( toolBar1 );
    add_box(box2, "Improved Euler approximation");
    connect(box2, SIGNAL(toggled(bool)), SLOT(toggle_improved_euler_approximation(bool)));

    box3 = new QCheckBox( toolBar1 );
    add_box(box3, "Runge-Kutta approximation");
    connect(box3, SIGNAL(toggled(bool)), SLOT(toggle_runge_kutta_approximation(bool)));

    box4 = new QCheckBox( toolBar1 );
    add_box(box4, "Euler error");
    connect(box4, SIGNAL(toggled(bool)), SLOT(toggle_euler_error(bool)));

    box5 = new QCheckBox( toolBar1 );
    add_box(box5, "Improved Euler error");
    connect(box5, SIGNAL(toggled(bool)), SLOT(toggle_improved_euler_error(bool)));

    box6 = new QCheckBox( toolBar1 );
    add_box(box6, "Runge-Kutta error");
    connect(box6, SIGNAL(toggled(bool)), SLOT(toggle_runge_kutta_error(bool)));

    // create fields for entering initial values (x0, y0, X, step)
    QLabel *x0_label = new QLabel(toolBar2);
    add_label(x0_label, "x0");

    QLineEdit *x0 = new QLineEdit();
    add_line_edit(x0);
    connect(x0, SIGNAL(textChanged(QString)), SLOT(update_x0(QString)));
    x0->setText("0"); // set default value to x0 field

    QLabel *y0_label = new QLabel(toolBar2);
    add_label(y0_label, "y0");

    QLineEdit *y0 = new QLineEdit();
    add_line_edit(y0);
    connect(y0, SIGNAL(textChanged(QString)), SLOT(update_y0(QString)));
    y0->setText("1"); // set default value to y0 field

    QLabel *X_label = new QLabel(toolBar2);
    add_label(X_label, "X");

    QLineEdit *X = new QLineEdit();
    add_line_edit(X);
    connect(X, SIGNAL(textChanged(QString)), SLOT(update_X(QString)));
    X->setText("12.5"); // set default value to X field

    QLabel *step_label = new QLabel(toolBar2);
    add_label(step_label, "step [0.0001, +inf)"); //TODO: remove when the boundary will be updated

    QLineEdit *step = new QLineEdit();
    add_line_edit(step);
    connect(step, SIGNAL(textChanged(QString)), SLOT(update_step(QString)));
    step->setText("0.1"); // set default value to step field
}

// procedures for creating toolbars
void MainWindow::setToolBar1()
{
    toolBar1 = new QToolBar( this );
    toolBar1->setMovable(false);
    addToolBar( toolBar1 );
}

void MainWindow::setToolBar2()
{
    toolBar2 = new QToolBar(this );
    toolBar2->setMovable(false);
    addToolBar(  Qt::RightToolBarArea, toolBar2 );
}

// procedure for creating a checkbox
void MainWindow::add_box(QCheckBox *box, QString text)
{
    box->setText( text );
    box->setCheckable( true );
    box->setChecked(true);

    toolBar1->addWidget( box ); // add button to the check boxes tool bar (first)
}

// procedure for creating a label
void MainWindow::add_label(QLabel *label, QString text) {
    label->setText(text);
    toolBar2->addWidget(label); // add label to the initial values tool bar (second)
}

// procedure for creating a field for an initial value
void MainWindow::add_line_edit(QLineEdit *line) {
    line->setMaximumWidth(80);
    toolBar2->addWidget(line); // add box for editing an initial value to the initial values tool bar (second)
}

// slots that handle signals
void MainWindow::toggle_euler_approximation(bool is_checked) {
    is_checked ? euler_curve->show() : euler_curve->hide();
    d_plot->replot();
}

void MainWindow::toggle_improved_euler_approximation(bool is_checked) {
    is_checked ? improved_euler_curve->show() : improved_euler_curve->hide();
    d_plot->replot();
}

void MainWindow::toggle_runge_kutta_approximation(bool is_checked) {
    is_checked ? runge_kutta_curve->show() : runge_kutta_curve->hide();
    d_plot->replot();
}

void MainWindow::toggle_euler_error(bool is_checked) {
    is_checked ? euler_error->show() : euler_error->hide();
    d_plot->replot();
}

void MainWindow::toggle_improved_euler_error(bool is_checked) {
    is_checked ? improved_euler_error->show() : improved_euler_error->hide();
    d_plot->replot();
}

void MainWindow::toggle_runge_kutta_error(bool is_checked) {
    is_checked ? runge_kutta_error->show() : runge_kutta_error->hide();
    d_plot->replot();
}

void MainWindow::update_x0(QString text) {
    double x0 = text.toDouble();

    for (auto curve : array_of_curves) {
        curve->update_initial_values(0, x0);
    }
    d_plot->replot();
}

void MainWindow::update_y0(QString text) {
    double y0 = text.toDouble();

    for (auto curve : array_of_curves) {
        curve->update_initial_values(1, y0);
    }
    d_plot->replot();
}

void MainWindow::update_X(QString text) {
    double X = text.toDouble();

    for (auto curve : array_of_curves) {
        curve->update_initial_values(2, X);
    }
    d_plot->replot();
}

void MainWindow::update_step(QString text) {
    double step = text.toDouble();

    if (step >= 0.0001) { // TODO: replace by (x0 / step * 6) < 1000000 (need getters for x0 and step)
        for (auto curve : array_of_curves) {
            curve->update_initial_values(3, step);
        }
        d_plot->replot();
    }
}

// destructor
MainWindow::~MainWindow()
{
    delete ui;
}
