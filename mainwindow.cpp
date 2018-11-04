#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set toolbars
    set_checkbox_toolbar();
    set_iv_toolbar();

    d_plot = new QwtPlot( this );
    setCentralWidget(d_plot);

    d_plot->setMinimumWidth(820);

    d_plot->setTitle("Approximate plot of DE"); // name of the plot
    d_plot->setCanvasBackground(Qt::white); // background color

    // parameters of axises
    d_plot->setAxisTitle(QwtPlot::yLeft, "Y");
    d_plot->setAxisTitle(QwtPlot::xBottom, "X");
    d_plot->setAxisScale(QwtPlot::yLeft, 0, 100);

    // enable legend
    QwtLegend *legend = new QwtLegend();
    d_plot->insertLegend( legend, QwtPlot::BottomLegend );

    // turn on a grid
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen(QPen( Qt::gray, 2 )); // color and thickness of lines
    grid->attach( d_plot ); // attach grid to a plot

    // create computational methods
    array_of_methods[0] = new exact_method();
    array_of_methods[1] = new eulers_method();
    array_of_methods[2] = new improved_eulers_method();
    array_of_methods[3] = new runge_kutta_method();

    // create curves and attach them to the plot
    array_of_curves[0] = new exact_solution_curve();
    array_of_curves[1] = new eulers_approximation_curve();
    array_of_curves[2] = new improved_eulers_approximation_curve();
    array_of_curves[3] = new runge_kutta_approximation_curve();
    array_of_curves[4] = new eulers_error_curve();
    array_of_curves[5] = new improved_eulers_error_curve();
    array_of_curves[6] = new runge_kutta_error_curve();

    for (int i = 0; i < 7; ++i) {
        array_of_curves[i]->attach_to_plot(d_plot);
    }

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

    // create checkboxes for toggling curves;
    for (int i = 0; i < 7; ++i) {
        box[i] = new QCheckBox( checkbox_toolbar );
    }

    add_box(box[0], "Exact solution");
    add_box(box[1], "Euler approximation");
    add_box(box[2], "Improved Euler approximation");
    add_box(box[3], "Runge-Kutta approximation");
    add_box(box[4], "Euler error");
    add_box(box[5], "Improved Euler error");
    add_box(box[6], "Runge-Kutta error");

    // connect signals of boxes to corresponding handlers (slots)
    connect(box[0], SIGNAL(toggled(bool)), SLOT(toggle_exact_solution(bool)));
    connect(box[1], SIGNAL(toggled(bool)), SLOT(toggle_euler_approximation(bool)));
    connect(box[2], SIGNAL(toggled(bool)), SLOT(toggle_improved_euler_approximation(bool)));
    connect(box[3], SIGNAL(toggled(bool)), SLOT(toggle_runge_kutta_approximation(bool)));
    connect(box[4], SIGNAL(toggled(bool)), SLOT(toggle_euler_error(bool)));
    connect(box[5], SIGNAL(toggled(bool)), SLOT(toggle_improved_euler_error(bool)));
    connect(box[6], SIGNAL(toggled(bool)), SLOT(toggle_runge_kutta_error(bool)));

    // create fields for entering initial values (x0, y0, X, step)
    QLabel *x0_label = new QLabel(iv_toolbar);
    add_label(x0_label, "x0");

    QLineEdit *x0 = new QLineEdit();
    add_line_edit(x0);
    connect(x0, SIGNAL(textChanged(QString)), SLOT(update_x0(QString)));
    x0->setText("0"); // set default value to x0 field

    QLabel *y0_label = new QLabel(iv_toolbar);
    add_label(y0_label, "y0");

    QLineEdit *y0 = new QLineEdit();
    add_line_edit(y0);
    connect(y0, SIGNAL(textChanged(QString)), SLOT(update_y0(QString)));
    y0->setText("1"); // set default value to y0 field

    QLabel *X_label = new QLabel(iv_toolbar);
    add_label(X_label, "X");

    QLineEdit *X = new QLineEdit();
    add_line_edit(X);
    connect(X, SIGNAL(textChanged(QString)), SLOT(update_X(QString)));
    X->setText("12.5"); // set default value to X field

    QLabel *step_label = new QLabel(iv_toolbar);
    add_label(step_label, "step [0.0001, +inf)");

    QLineEdit *step = new QLineEdit();
    add_line_edit(step);
    connect(step, SIGNAL(textChanged(QString)), SLOT(update_step(QString)));
    step->setText("0.1"); // set default value to step field
}

// procedures for creating toolbars
void MainWindow::set_checkbox_toolbar()
{
    checkbox_toolbar = new QToolBar( this );
    checkbox_toolbar->setMovable(false);
    addToolBar( checkbox_toolbar );
}

void MainWindow::set_iv_toolbar()
{
    iv_toolbar = new QToolBar(this );
    iv_toolbar->setMovable(false);
    addToolBar(  Qt::RightToolBarArea, iv_toolbar );
}

// procedure for creating a checkbox
void MainWindow::add_box(QCheckBox *box, QString text)
{
    box->setText( text );
    box->setCheckable( true );
    box->setChecked(true);

    checkbox_toolbar->addWidget( box ); // add button to the check boxes tool bar (first)
}

// procedure for creating a label
void MainWindow::add_label(QLabel *label, QString text) {
    label->setText(text);
    iv_toolbar->addWidget(label); // add label to the initial values tool bar (second)
}

// procedure for creating a field for an initial value
void MainWindow::add_line_edit(QLineEdit *line) {
    line->setMaximumWidth(80);
    iv_toolbar->addWidget(line); // add box for editing an initial value to the initial values tool bar (second)
}

// slots that handle signals from checkboxes
void MainWindow::toggle_exact_solution(bool is_checked) {
    is_checked ? array_of_curves[0]->show() : array_of_curves[0]->hide();
    d_plot->replot();
}

void MainWindow::toggle_euler_approximation(bool is_checked) {
    is_checked ? array_of_curves[1]->show() : array_of_curves[1]->hide();
    d_plot->replot();
}

void MainWindow::toggle_improved_euler_approximation(bool is_checked) {
    is_checked ? array_of_curves[2]->show() : array_of_curves[2]->hide();
    d_plot->replot();
}

void MainWindow::toggle_runge_kutta_approximation(bool is_checked) {
    is_checked ? array_of_curves[3]->show() : array_of_curves[3]->hide();
    d_plot->replot();
}

void MainWindow::toggle_euler_error(bool is_checked) {
    is_checked ? array_of_curves[4]->show() : array_of_curves[4]->hide();
    d_plot->replot();
}

void MainWindow::toggle_improved_euler_error(bool is_checked) {
    is_checked ? array_of_curves[5]->show() : array_of_curves[5]->hide();
    d_plot->replot();
}

void MainWindow::toggle_runge_kutta_error(bool is_checked) {
    is_checked ? array_of_curves[6]->show() : array_of_curves[6]->hide();
    d_plot->replot();
}

// Function that is called from a new thread. It updates initial values using this new thread.
void MainWindow::thread_function(int field_to_update, double new_value, approximation_curve *curve, abstract_computation_method *method) {
    curve->update_initial_values(method, field_to_update, new_value);
}

// slot that updates x0 and recalculates curves, replots the plot
void MainWindow::update_x0(QString text) {
    std::vector <std::thread> threads;
    double x0 = text.toDouble();

    // update approximation curves
    for (int i = 0; i < 4; ++i) {
        // create a new thread that will update initial values and recalculate an appropriate approximation/exact curve
        threads.push_back(std::thread(&MainWindow::thread_function, this, 0, x0, array_of_curves[i], array_of_methods[i]));
    }
    // wait for termination of new threads (synchronization)
    for (unsigned int i = 0; i < 4; ++i) {
        threads[i].join();
    }

    // update error curves
    for (int i = 4; i < 7; ++i) {
        // create a new thread that will recalculate an appropriate error curve
        threads.push_back(std::thread(&MainWindow::thread_function, this, 0, x0, array_of_curves[i], array_of_methods[i - 3]));
    }
    // wait for termination of new threads (synchronization)
    for (unsigned int i = 4; i < 7; ++i) {
        threads[i].join();
    }

    d_plot->replot();
    threads.clear();
}

// slot that updates y0 and recalculates curves, replots the plot
void MainWindow::update_y0(QString text) {
    std::vector <std::thread> threads;
    double y0 = text.toDouble();

    // update approximation curves
    for (int i = 0; i < 4; ++i) {
        // create a new thread that will update initial values and recalculate an appropriate approximation/exact curve
        threads.push_back(std::thread(&MainWindow::thread_function, this, 1, y0, array_of_curves[i], array_of_methods[i]));
    }
    // wait for termination of new threads (synchronization)
    for (unsigned int i = 0; i < 4; ++i) {
        threads[i].join();
    }

    // update error curves
    for (int i = 4; i < 7; ++i) {
        // create a new thread that will recalculate an appropriate error curve
        threads.push_back(std::thread(&MainWindow::thread_function, this, 1, y0, array_of_curves[i], array_of_methods[i - 3]));
    }
    // wait for termination of new threads (synchronization)
    for (unsigned int i = 4; i < 7; ++i) {
        threads[i].join();
    }

    d_plot->replot();
    threads.clear();
}

// slot that updates X and recalculates curves, replots the plot
void MainWindow::update_X(QString text) {
    std::vector <std::thread> threads;
    double X = text.toDouble();

    // update approximation curves
    for (int i = 0; i < 4; ++i) {
        // create a new thread that will update initial values and recalculate an appropriate approximation/exact curve
        threads.push_back(std::thread(&MainWindow::thread_function, this, 2, X, array_of_curves[i], array_of_methods[i]));
    }
    // wait for termination of new threads (synchronization)
    for (unsigned int i = 0; i < 4; ++i) {
        threads[i].join();
    }

    // update error curves
    for (int i = 4; i < 7; ++i) {
        // create a new thread that will recalculate an appropriate error curve
        threads.push_back(std::thread(&MainWindow::thread_function, this, 2, X, array_of_curves[i], array_of_methods[i - 3]));
    }
    // wait for termination of new threads (synchronization)
    for (unsigned int i = 4; i < 7; ++i) {
        threads[i].join();
    }

    d_plot->replot();
    threads.clear();
}

// slot that updates h (step) and recalculates curves, replots the plot
void MainWindow::update_step(QString text) {
    double step = text.toDouble();

    if (step >= 0.0001) { // minimal step is bounded in order to avoid program going into infinite calculations
        std::vector <std::thread> threads;

        // update approximation curves
        for (int i = 0; i < 4; ++i) {
            // create a new thread that will update initial values and recalculate an appropriate approximation/exact curve
            threads.push_back(std::thread(&MainWindow::thread_function, this, 3, step, array_of_curves[i], array_of_methods[i]));
        }
        // wait for termination of new threads (synchronization)
        for (unsigned int i = 0; i < 4; ++i) {
            threads[i].join();
        }

        // update error curves
        for (int i = 4; i < 7; ++i) {
            // create a new thread that will recalculate an appropriate error curve
            threads.push_back(std::thread(&MainWindow::thread_function, this, 3, step, array_of_curves[i], array_of_methods[i - 3]));
        }
        // wait for termination of new threads (synchronization)
        for (unsigned int i = 4; i < 7; ++i) {
            threads[i].join();
        }

        d_plot->replot();
        threads.clear();
    }
}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
    delete d_plot;
    delete checkbox_toolbar;
    delete iv_toolbar;
}
