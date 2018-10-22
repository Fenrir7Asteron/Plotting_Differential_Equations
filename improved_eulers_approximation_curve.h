#ifndef IMPROVED_EULERS_APPROXIMATION_CURVE_H
#define IMPROVED_EULERS_APPROXIMATION_CURVE_H

#include "approximation_curve.h"
#include "improved_eulers_method.h"

class improved_eulers_approximation_curve : public approximation_curve
{
public:
    improved_eulers_approximation_curve();
    void attach_to_plot(QwtPlot*);
};

#endif // IMPROVED_EULERS_APPROXIMATION_CURVE_H
