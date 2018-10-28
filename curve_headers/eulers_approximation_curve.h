#ifndef EULERS_APPROXIMATION_CURVE_H
#define EULERS_APPROXIMATION_CURVE_H

#include "approximation_curve.h"
#include "eulers_method.h"

class eulers_approximation_curve : public approximation_curve
{
public:
    eulers_approximation_curve();
    void attach_to_plot(QwtPlot*);
    void update_initial_values(int field_to_update, double new_value);
};

#endif // EULERS_APPROXIMATION_CURVE_H
