#include "abstract_computation_method.h"

// constructor
abstract_computation_method::abstract_computation_method()
{
    x0 = X0;
    y0 = Y0;
    X = BORDER_X;
    h = STEP;
    need_to_recompute = true;
}

// given DE to compute in form y' = f(x, y)
double abstract_computation_method::derivative(double x, double y)
{
    return sin(x) + y;
}

// "constant" that is computed for particular initial values
double abstract_computation_method::C() {
    return (y0 + (sin(x0) + cos(x0)) * 0.5) / pow(e, x0);
}

// Exact solution that I received analytically. It depends on a "constant" C and not depends on y (since it is in explicit form y = ...).
double abstract_computation_method::exact_solution(double x)
{
    return (-sin(x) - cos(x)) * 0.5 + C() * pow(e, x);
}

// procedure to compute points of a curves (both approximation and error) using an appropriate method
void abstract_computation_method::compute_approximation()
{
    if (need_to_recompute) {
        std::pair<QPolygonF, QPolygonF> result;

        QPointF current_point = QPointF(x0, y0);
        QPointF prev_point;
        QPolygonF computed_points;
        QPolygonF error_points;

        computed_points << current_point;
        error_points << QPointF(x0, 0);

        double xi = x0 + h;

        while (xi < X) {
            prev_point = current_point;

            current_point = get_next_point(current_point); // calls function of an appropriate heir of abstract_computation_method
            computed_points << current_point;

            error_points << get_next_error(current_point);

            xi = current_point.x();
        }

        result.first = computed_points;
        result.second = error_points;

        computed_curves = result;
        need_to_recompute = false;
    }
}

// returns computed curves
std::pair<QPolygonF, QPolygonF> abstract_computation_method::get_approximation()
{
    return computed_curves;
}

// computes absolute error between exact and approximate solutions at a specific point
QPointF abstract_computation_method::get_next_error(QPointF prev_point)
{
    double xi = prev_point.x();
    double yi = prev_point.y();
    return QPointF(xi, fabs(exact_solution(xi) - yi));
}

// Updates initial values (IV). Is called when fields for initial values are changed.
void abstract_computation_method::update_initial_values(int field_to_update, double new_value)
{
    switch (field_to_update) {
        case 0: {
            if (fabs(x0 - new_value) > EPS) {
                x0 = new_value;
                need_to_recompute = true; // mark that points must be recomputed since IV are changed
            }
            break;
        }
        case 1: {
            if (fabs(y0 - new_value) > EPS) {
                y0 = new_value;
                need_to_recompute = true; // mark that points must be recomputed since IV are changed
            }
            break;
        }
        case 2: {
            if (fabs(X - new_value) > EPS) {
                X = new_value;
                need_to_recompute = true; // mark that points must be recomputed since IV are changed
            }
            break;
        }
        case 3: {
            if (fabs(h - new_value) > EPS) {
                h = new_value;
                need_to_recompute = true; // mark that points must be recomputed since IV are changed
            }
        }
    }
}
