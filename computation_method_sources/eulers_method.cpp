#include "eulers_method.h"

// constructor
eulers_method::eulers_method() : abstract_computation_method ()
{

}

// computes approximation at a specific point using approximation at previous point
QPointF eulers_method::get_next_point(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    return QPointF(xi + h, yi + h * derivative(xi, yi));
}

// computes local error between exact and approximate solutions at a specific point
QPointF eulers_method::get_next_local_error(QPointF prev_point)
{
    return abstract_computation_method::get_next_local_error(prev_point);
}

// returns computed curves
std::pair<QPolygonF, QPolygonF> eulers_method::get_approximation()
{
    return abstract_computation_method::get_approximation();
}
