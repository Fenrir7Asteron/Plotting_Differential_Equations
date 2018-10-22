#include "approximation_curve.h"

approximation_curve::approximation_curve()
{

}

void approximation_curve::attach_to_plot(QwtPlot *d_plot) {
    this->attach(d_plot);
}
