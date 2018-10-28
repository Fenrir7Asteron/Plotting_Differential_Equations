#include "runge_kutta_method.h"

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

QPointF runge_kutta_method::get_next_error(QPointF prev_point)
{
    return abstract_computation_method::get_next_error(prev_point);
}

std::pair<QPolygonF, QPolygonF> runge_kutta_method::get_approximation() {
    return abstract_computation_method::get_approximation();
}

runge_kutta_method::runge_kutta_method(QPointF initial_point, double step, double border_x) : abstract_computation_method (initial_point, step, border_x)
{

}
