#include "improved_eulers_method.h"

QPointF improved_eulers_method::get_next_point(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    double k1 = derivative(xi, yi);
    double k2 = derivative(xi + h, yi + h * k1);
    return QPointF(xi + h, yi + (h * 0.5) * (k1 + k2));
}

QPointF improved_eulers_method::get_next_error(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    return QPointF(xi, exact_solution(xi, yi) - yi);
}

std::pair<QPolygonF, QPolygonF> improved_eulers_method::get_approximation() {
    return abstract_computation_method::get_approximation();
}

improved_eulers_method::improved_eulers_method(QPointF initial_point, double step, double border_x) : abstract_computation_method (initial_point, step, border_x)
{

}
