#ifndef ABSTRACT_COMPUTATION_METHOD_H
#define ABSTRACT_COMPUTATION_METHOD_H

#include <cmath>
#include <QMainWindow>

#define derivative(x, y) (sin(x) + y)
//#define derivative(x, y) ((y * y) / (x * x) - 2)

class abstract_computation_method
{
public:
    QPointF get_next_point(QPointF prev_point);
    QPolygonF find_approximate_curve();
    QPolygonF find_approximation_error_curve();
    abstract_computation_method();

    double h;
    double X;
    double x0;
    double y0;
};

#endif // ABSTRACT_COMPUTATION_METHOD_H
