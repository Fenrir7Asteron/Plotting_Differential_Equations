#include "runge_kutta_method.h"

// constructor
runge_kutta_method::runge_kutta_method() : abstract_computation_method ()
{

}

// computes approximation at a specific point using approximation at previous point
QPointF runge_kutta_method::get_next_point(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    double k1 = derivative(xi, yi);
    double k2 = derivative(xi + h * 0.5, yi + h * 0.5 * k1);
    double k3 = derivative(xi + h * 0.5, yi + h * 0.5 * k2);
    double k4 = derivative(xi + h, yi + h * k3);
    return QPointF(xi + h, yi + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4));
}

// computes absolute error between exact and approximate solutions at a specific point
QPointF runge_kutta_method::get_next_error(QPointF prev_point)
{
    return abstract_computation_method::get_next_error(prev_point);
}

// returns computed curves
std::pair<QPolygonF, QPolygonF> runge_kutta_method::get_approximation() {
    return abstract_computation_method::get_approximation();
}
