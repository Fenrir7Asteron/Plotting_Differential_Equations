#ifndef EULERS_METHOD_H
#define EULERS_METHOD_H

#include <QMainWindow>
#include "abstract_computation_method.h"

class eulers_method : public abstract_computation_method
{
public:
    QPointF get_next_point(QPointF prev_point);
    QPolygonF find_approximate_curve();
    QPolygonF find_approximation_error_curve();
    eulers_method(QPointF, double, double);
};

#endif // EULERS_METHOD_H
