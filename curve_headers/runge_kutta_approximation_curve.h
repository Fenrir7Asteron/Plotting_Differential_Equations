#ifndef RUNGE_KUTTA_APPROXIMATION_CURVE_H
#define RUNGE_KUTTA_APPROXIMATION_CURVE_H

#include "approximation_curve.h"
#include "runge_kutta_method.h"

class runge_kutta_approximation_curve : public approximation_curve
{
public:
   runge_kutta_approximation_curve();
   void attach_to_plot(QwtPlot*);
};

#endif // RUNGE_KUTTA_APPROXIMATION_CURVE_H
