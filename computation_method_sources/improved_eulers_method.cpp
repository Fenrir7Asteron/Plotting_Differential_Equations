#include "improved_eulers_method.h"

// constructor
improved_eulers_method::improved_eulers_method() : abstract_computation_method ()
{

}

// computes approximation at a specific point using approximation at previous point
QPointF improved_eulers_method::get_next_point(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    double k1 = derivative(xi, yi);
    double k2 = derivative(xi + h, yi + h * k1);
    return QPointF(xi + h, yi + (h * 0.5) * (k1 + k2));
}

// computes absolute error between exact and approximate solutions at a specific point
QPointF improved_eulers_method::get_next_error(QPointF prev_point)
{
    return abstract_computation_method::get_next_error(prev_point);
}

// returns computed curves
std::pair<QPolygonF, QPolygonF> improved_eulers_method::get_approximation() {
    return abstract_computation_method::get_approximation();
}
