#ifndef ABSTRACT_COMPUTATION_METHOD_H
#define ABSTRACT_COMPUTATION_METHOD_H

#include <cmath>
#include <QMainWindow>

// define mathematical constants
#define EPS 0.000000001
#define e 2.718281828459

// define initial parameters of differential equation to plot
#define X0 0
#define Y0 1
#define BORDER_X 12.5
#define STEP 0.1

class abstract_computation_method
{
public:
    abstract_computation_method();
    void compute_approximation();
    std::pair <QPolygonF, QPolygonF> get_approximation();
    double get_global_error();

    void update_initial_values(int field_to_update, double new_value);

protected:
    virtual QPointF get_next_point(QPointF prev_point) = 0;
    QPointF get_next_local_error(QPointF);
    std::pair <QPolygonF, QPolygonF> computed_curves;

    double derivative(double x, double y);
    double C();
    double exact_solution(double x);

    double h; // step
    double X;
    double x0;
    double y0;
    bool need_to_recompute; // shows whether there is need to recompute points
    double global_error;
};

#endif // ABSTRACT_COMPUTATION_METHOD_H
