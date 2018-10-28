#include "eulers_error_curve.h"

eulers_error_curve::eulers_error_curve()
{
    // create error curve for Euler's method
    this->setTitle( "Euler's approximation error curve" );
    this->setPen( Qt::red, 5 ); // color and thickness of a curve
    this->setRenderHint
            ( QwtPlotItem::RenderAntialiased, true ); // antialiasing

    // graphical representation of points
    QwtSymbol *approximation_error_symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::black ), QPen( Qt::darkGray, 2 ), QSize( 7, 7 ) );
    this->setSymbol( approximation_error_symbol );

    // applying Euler's method to get points for our curve
    method = new eulers_method(QPointF(X0, Y0), STEP, BORDER_X);
    method->compute_approximation();
    QPolygonF euler_points = method->get_approximation().second;

    //attach points to the curves
    this->setSamples( euler_points );
}

void eulers_error_curve::attach_to_plot(QwtPlot *d_plot)  {
    approximation_curve::attach_to_plot(d_plot);
}

void eulers_error_curve::update_initial_values(int field_to_update, double new_value) {
    approximation_curve::update_initial_values(field_to_update, new_value);
    this->setSamples( method->get_approximation().second );
}
