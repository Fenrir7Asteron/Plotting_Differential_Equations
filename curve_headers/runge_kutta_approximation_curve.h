#ifndef RUNGE_KUTTA_APPROXIMATION_CURVE_H
#define RUNGE_KUTTA_APPROXIMATION_CURVE_H

#include "curve.h"

class runge_kutta_approximation_curve : public approximation_curve
{
public:
    runge_kutta_approximation_curve();
    void attach_to_plot(QwtPlot*);
    void update_initial_values(abstract_computation_method *method, int field_to_update, double new_value);
};

#endif // RUNGE_KUTTA_APPROXIMATION_CURVE_H
