#include "eulers_method.h"

QPointF eulers_method::get_next_point(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    return QPointF(xi + h, yi + h * derivative(xi, yi));
}

QPolygonF eulers_method::find_approximate_curve()
{
    double xi = x0;
    QPointF current_point = QPointF(x0, y0);
    QPointF prev_point;
    QPolygonF result;

    result << current_point;

    while (xi < X) {
        prev_point = current_point;
        current_point = get_next_point(current_point);
        result << current_point;
        xi = current_point.x();
        prev_point.~QPointF();
    }

    current_point.~QPointF();

    return result;
}

QPolygonF eulers_method::find_approximation_error_curve()
{
//TODO: find error
}

eulers_method::eulers_method(QPointF initial_point, double step, double border_x)
{
    h = step;
    X = border_x;
    x0 = initial_point.x();
    y0 = initial_point.y();
}
