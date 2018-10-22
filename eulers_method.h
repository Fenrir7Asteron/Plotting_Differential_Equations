#ifndef EULERS_METHOD_H
#define EULERS_METHOD_H

#include <QMainWindow>
#include "abstract_computation_method.h"

class eulers_method : public abstract_computation_method
{
public:
    eulers_method(QPointF, double, double);
    void compute_approximation();
    std::pair<QPolygonF, QPolygonF> get_approximation();

protected:
    QPointF get_next_point(QPointF prev_point);
    QPointF get_next_error(QPointF);
};

#endif // EULERS_METHOD_H
