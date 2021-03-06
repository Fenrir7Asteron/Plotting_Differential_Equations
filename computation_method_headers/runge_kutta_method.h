#ifndef RUNGE_KUTTA_METHOD_H
#define RUNGE_KUTTA_METHOD_H

#include "abstract_computation_method.h"

class runge_kutta_method : public abstract_computation_method
{
public:
    runge_kutta_method();
    std::pair<QPolygonF, QPolygonF> get_approximation();

protected:
    QPointF get_next_point(QPointF prev_point);
    QPointF get_next_local_error(QPointF);
};

#endif // RUNGE_KUTTA_METHOD_H
