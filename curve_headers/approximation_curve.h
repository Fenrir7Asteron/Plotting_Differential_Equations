#ifndef APPROXIMATION_CURVE_H
#define APPROXIMATION_CURVE_H

#include <qwt_symbol.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "abstract_computation_method.h"

class approximation_curve : public QwtPlotCurve
{
public:
    approximation_curve();
    void attach_to_plot(QwtPlot*);
    virtual void update_initial_values(abstract_computation_method *method, int field_to_update, double new_value);
};

#endif // APPROXIMATION_CURVE_H
