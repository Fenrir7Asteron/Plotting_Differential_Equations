#include "curve.h"

// constructor
approximation_curve::approximation_curve()
{

}

// attach a curve to the plot
void approximation_curve::attach_to_plot(QwtPlot *d_plot) {
    this->attach(d_plot);
}

// update initial values of a method and recompute points
void approximation_curve::update_initial_values(abstract_computation_method *method, int field_to_update, double new_value) {
    method->update_initial_values(field_to_update, new_value);
    method->compute_approximation();
}
