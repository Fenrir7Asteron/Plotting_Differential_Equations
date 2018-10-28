#ifndef ABSTRACT_COMPUTATION_METHOD_H
#define ABSTRACT_COMPUTATION_METHOD_H

#include <cmath>
#include <QMainWindow>

//define DE to plot
#define X0 0
#define Y0 1
#define STEP 1
#define BORDER_X 12.5
#define derivative(x, y) (sin(x) + y)
#define exact_solution(x, y) ((3 * exp(x) - sin(x) - cos(x)) * 0.5)

class abstract_computation_method
{
public:
    abstract_computation_method(QPointF, double, double);
    void compute_approximation();
    std::pair <QPolygonF, QPolygonF> get_approximation();

    void update_initial_values(int field_to_update, double new_value);

protected:
    virtual QPointF get_next_point(QPointF prev_point) = 0;
    QPointF get_next_error(QPointF);

    std::pair <QPolygonF, QPolygonF> approximation_curves;

    double h;
    double X;
    double x0;
    double y0;
    bool computed_once;
};

#endif // ABSTRACT_COMPUTATION_METHOD_H
