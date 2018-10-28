#ifndef RUNGE_KUTTA_ERROR_CURVE_H
#define RUNGE_KUTTA_ERROR_CURVE_H

#include "approximation_curve.h"
#include "runge_kutta_method.h"

class runge_kutta_error_curve : public approximation_curve
{
public:
    runge_kutta_error_curve();
    void attach_to_plot(QwtPlot*);
    void update_initial_values(int field_to_update, double new_value);
};

#endif // RUNGE_KUTTA_ERROR_CURVE_H
