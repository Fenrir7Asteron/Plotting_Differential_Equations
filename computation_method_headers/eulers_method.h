#ifndef EULERS_METHOD_H
#define EULERS_METHOD_H

#include "abstract_computation_method.h"

class eulers_method : public abstract_computation_method
{
public:
    eulers_method();
    std::pair<QPolygonF, QPolygonF> get_approximation();

protected:
    QPointF get_next_point(QPointF prev_point);
    QPointF get_next_local_error(QPointF);
};

#endif // EULERS_METHOD_H
