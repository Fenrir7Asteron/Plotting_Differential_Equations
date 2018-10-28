#include "abstract_computation_method.h"

void abstract_computation_method::compute_approximation()
{
    if (!computed_once) {
        std::pair<QPolygonF, QPolygonF> result;

        double xi = x0;
        QPointF current_point = QPointF(x0, y0);
        QPointF prev_point;
        QPolygonF approximate_points;
        QPolygonF approximation_errors;

        approximate_points << current_point;
        approximation_errors << QPointF(x0, 0);

        while (xi < X) {
            prev_point = current_point;

            current_point = get_next_point(current_point);
            approximate_points << current_point;

            approximation_errors << get_next_error(current_point);

            xi = current_point.x();
            prev_point.~QPointF();
        }

        current_point.~QPointF();

        result.first = approximate_points;
        result.second = approximation_errors;

        approximation_curves = result;
    }
}

std::pair<QPolygonF, QPolygonF> abstract_computation_method::get_approximation() {
    return approximation_curves;
}

QPointF abstract_computation_method::get_next_error(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    return QPointF(xi, exact_solution(xi, yi) - yi);
}

abstract_computation_method::abstract_computation_method(QPointF initial_point, double step, double border_x)
{
    h = step;
    X = border_x;
    x0 = initial_point.x();
    y0 = initial_point.y();
    computed_once = false;
}

void abstract_computation_method::update_initial_values(int field_to_update, double new_value) {
    switch (field_to_update) {
        case 0: {x0 = new_value; break;}
        case 1: {y0 = new_value; break;}
        case 2: {X = new_value; break;}
        case 3: {h = new_value;}
    }
    computed_once = false;
}
