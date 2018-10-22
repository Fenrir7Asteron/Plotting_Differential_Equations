#ifndef APPROXIMATION_CURVE_H
#define APPROXIMATION_CURVE_H

#include <qwt_symbol.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>

class approximation_curve : public QwtPlotCurve
{
public:
    approximation_curve();
    void attach_to_plot(QwtPlot*);
};

#endif // APPROXIMATION_CURVE_H
