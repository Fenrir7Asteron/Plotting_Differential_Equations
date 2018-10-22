#ifndef EULERS_APPROXIMATION_CURVE_H
#define EULERS_APPROXIMATION_CURVE_H

#include "approximation_curve.h"
#include "eulers_method.h"

class eulers_approximation_curve : public approximation_curve
{
public:
    eulers_approximation_curve();
    void attach_to_plot(QwtPlot*);
};

#endif // EULERS_APPROXIMATION_CURVE_H
