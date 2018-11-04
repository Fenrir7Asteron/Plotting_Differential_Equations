#ifndef EXACT_SOLUTION_CURVE_H
#define EXACT_SOLUTION_CURVE_H

#include "curve.h"

class exact_solution_curve : public approximation_curve
{
public:
    exact_solution_curve();
    void attach_to_plot(QwtPlot*);
    void update_initial_values(abstract_computation_method *method, int field_to_update, double new_value);
};

#endif // EXACT_SOLUTION_CURVE_H
