#include "eulers_method.h"

QPointF eulers_method::get_next_point(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    return QPointF(xi + h, yi + h * derivative(xi, yi));
}

QPointF eulers_method::get_next_error(QPointF prev_point)
{
    return abstract_computation_method::get_next_error(prev_point);
}

std::pair<QPolygonF, QPolygonF> eulers_method::get_approximation() {
    return abstract_computation_method::get_approximation();
}

eulers_method::eulers_method(QPointF initial_point, double step, double border_x) : abstract_computation_method (initial_point, step, border_x)
{

}
