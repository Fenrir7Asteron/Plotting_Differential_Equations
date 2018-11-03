#include "exact_method.h"

// constructor
exact_method::exact_method() : abstract_computation_method ()
{

}

// computes exact solution at a specific point
QPointF exact_method::get_next_point(QPointF prev_point)
{
    double xi = prev_point.x();
    return QPointF(xi + h, exact_solution(xi + h));
}

// returns computed curve
std::pair<QPolygonF, QPolygonF> exact_method::get_approximation() {
    return abstract_computation_method::get_approximation();
}
