#include "approximation_curve.h"

approximation_curve::approximation_curve()
{

}

void approximation_curve::attach_to_plot(QwtPlot *d_plot) {
    this->attach(d_plot);
}

void approximation_curve::update_initial_values(int field_to_update, double new_value) {
    method->update_initial_values(field_to_update, new_value);
    method->compute_approximation();
}
