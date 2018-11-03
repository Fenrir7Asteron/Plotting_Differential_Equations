#ifndef EXACT_METHOD_H
#define EXACT_METHOD_H

#include "abstract_computation_method.h"

class exact_method : public abstract_computation_method
{
public:
    exact_method();
    std::pair<QPolygonF, QPolygonF> get_approximation();

protected:
    QPointF get_next_point(QPointF prev_point);
};

#endif // EXACT_METHOD_H
