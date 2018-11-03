#include "runge_kutta_error_curve.h"

runge_kutta_error_curve::runge_kutta_error_curve()
{
    // create error curve for Runge-Kutta method
    this->setTitle( "Runge-Kutta approximation error curve" );
    this->setPen( Qt::magenta, 5 ); // color and thickness of a curve
    this->setRenderHint
            ( QwtPlotItem::RenderAntialiased, true ); // antialiasing

    // graphical representation of points
    QwtSymbol *approximation_error_symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::black ), QPen( Qt::darkGray, 2 ), QSize( 7, 7 ) );
    this->setSymbol( approximation_error_symbol );
}

// attach a curve to the plot
void runge_kutta_error_curve::attach_to_plot(QwtPlot *d_plot)  {
    approximation_curve::attach_to_plot(d_plot);
}

// update initial values of a method and recompute points, attach new points to a curve
void runge_kutta_error_curve::update_initial_values(abstract_computation_method *method, int field_to_update, double new_value) {
    approximation_curve::update_initial_values(method, field_to_update, new_value);
    this->setSamples( method->get_approximation().second );
}
