#ifndef ABSTRACT_COMPUTATION_METHOD_H
#define ABSTRACT_COMPUTATION_METHOD_H

#include <cmath>
#include <QMainWindow>

//define DE to plot
#define X0 0
#define Y0 1
#define STEP 0.08
#define BORDER_X 12.5
#define derivative(x, y) (sin(x) + y)
#define exact_solution(x, y) ((3 * exp(x) - sin(x) - cos(x)) * 0.5)

class abstract_computation_method
{
public:
    abstract_computation_method(QPointF, double, double);
    void compute_approximation();
    std::pair <QPolygonF, QPolygonF> get_approximation();

    double h;
    double X;
    double x0;
    double y0;

    bool computed_once;

protected:
    virtual QPointF get_next_point(QPointF prev_point) = 0;
    virtual QPointF get_next_error(QPointF) = 0;

    std::pair <QPolygonF, QPolygonF> approximation_curves;
};

#endif // ABSTRACT_COMPUTATION_METHOD_H
