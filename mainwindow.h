#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>

#include "approximation_curve.h"
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

private:
    Ui::MainWindow *ui;
    QwtPlot *d_plot;
    QToolBar *toolBar1;
    QToolBar *toolBar2;

    QCheckBox *box1;
    QCheckBox *box2;
    QCheckBox *box3;
    QCheckBox *box4;
    QCheckBox *box5;
    QCheckBox *box6;

    eulers_approximation_curve *euler_curve;
    improved_eulers_approximation_curve *improved_euler_curve;
    runge_kutta_approximation_curve *runge_kutta_curve;
    eulers_error_curve *euler_error;
    improved_eulers_error_curve *improved_euler_error;
    runge_kutta_error_curve *runge_kutta_error;

    void setToolBar1();
    void setToolBar2();
    void add_box(QCheckBox *box, QString text);
    void add_label(QLabel *label, QString text);
    void add_line_edit(QLineEdit *line);

private Q_SLOTS:
    void toggle_euler_approximation(bool is_checked);
    void toggle_improved_euler_approximation(bool is_checked);
    void toggle_runge_kutta_approximation(bool is_checked);
    void toggle_euler_error(bool is_checked);
    void toggle_improved_euler_error(bool is_checked);
    void toggle_runge_kutta_error(bool is_checked);
};

#endif // MAINWINDOW_H
