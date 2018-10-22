#ifndef IMPROVED_EULERS_METHOD_H
#define IMPROVED_EULERS_METHOD_H

#include <QMainWindow>
#include "abstract_computation_method.h"

class improved_eulers_method : public abstract_computation_method
{
public:
    improved_eulers_method(QPointF, double, double);
    std::pair<QPolygonF, QPolygonF> get_approximation();

protected:
    QPointF get_next_point(QPointF prev_point);
    QPointF get_next_error(QPointF);
};

#endif // IMPROVED_EULERS_METHOD_H
