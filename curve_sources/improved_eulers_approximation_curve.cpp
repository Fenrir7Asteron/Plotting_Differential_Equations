#include "improved_eulers_approximation_curve.h"

improved_eulers_approximation_curve::improved_eulers_approximation_curve()
{
    // create approximation curve for Improved Euler's method
    this->setTitle( "Improved Euler's approximate solution" );
    this->setPen( Qt::darkBlue, 5 ); // color and thickness of a curve
    this->setRenderHint
            ( QwtPlotItem::RenderAntialiased, true ); // antialiasing

    // graphical representation of points
    QwtSymbol *approximation_symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::black ), QPen( Qt::darkGray, 2 ), QSize( 7, 7 ) );
    this->setSymbol( approximation_symbol );

    // applying Euler's method to get points for our curve
    method = new improved_eulers_method(QPointF(X0, Y0), STEP, BORDER_X);
    method->compute_approximation();
    QPolygonF euler_points = method->get_approximation().first;

    //attach points to the curves
    this->setSamples( euler_points );
}

void improved_eulers_approximation_curve::attach_to_plot(QwtPlot *d_plot)  {
    approximation_curve::attach_to_plot(d_plot);
}

void improved_eulers_approximation_curve::update_initial_values(int field_to_update, double new_value) {
    approximation_curve::update_initial_values(field_to_update, new_value);
    this->setSamples( method->get_approximation().first );
}
