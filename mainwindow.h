#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>

#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_legend.h>

#include <qlineedit.h>

#include <thread>

#include "exact_method.h"
#include "eulers_method.h"
#include "improved_eulers_method.h"
#include "runge_kutta_method.h"

#include "approximation_curve.h"
#include "exact_solution_curve.h"
#include "eulers_approximation_curve.h"
#include "improved_eulers_approximation_curve.h"
#include "runge_kutta_approximation_curve.h"
#include "eulers_error_curve.h"
#include "improved_eulers_error_curve.h"
#include "runge_kutta_error_curve.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void thread_function(int field_to_update, double new_value, approximation_curve *curve, abstract_computation_method *method);

private:
    Ui::MainWindow *ui;
    QwtPlot *d_plot;
    QToolBar *checkbox_toolbar;
    QToolBar *iv_toolbar; // initial value fields toolbar
    QCheckBox *box[7];

    approximation_curve *array_of_curves[7]; // [0] - exact, [1 - 3] - approximations, [4 - 6] - absolute errors
    abstract_computation_method *array_of_methods[4]; // [0] - exact, [1] - Euler, [2] - Improved Euler, [3] - Runge-Kutta

    void set_checkbox_toolbar();
    void set_iv_toolbar();
    void add_box(QCheckBox *box, QString text);
    void add_label(QLabel *label, QString text);
    void add_line_edit(QLineEdit *line);

private Q_SLOTS:
    void toggle_exact_solution(bool is_checked);
    void toggle_euler_approximation(bool is_checked);
    void toggle_improved_euler_approximation(bool is_checked);
    void toggle_runge_kutta_approximation(bool is_checked);
    void toggle_euler_error(bool is_checked);
    void toggle_improved_euler_error(bool is_checked);
    void toggle_runge_kutta_error(bool is_checked);

    void update_x0(QString text);
    void update_y0(QString text);
    void update_X(QString text);
    void update_step(QString text);
};

#endif // MAINWINDOW_H
