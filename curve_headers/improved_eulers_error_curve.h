#ifndef IMPROVED_EULERS_ERROR_CURVE_H
#define IMPROVED_EULERS_ERROR_CURVE_H

#include "approximation_curve.h"

class improved_eulers_error_curve : public approximation_curve
{
public:
    improved_eulers_error_curve();
    void attach_to_plot(QwtPlot*);
    void update_initial_values(abstract_computation_method *method, int field_to_update, double new_value);
};

#endif // IMPROVED_EULERS_ERROR_CURVE_H
