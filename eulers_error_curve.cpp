#include "eulers_error_curve.h"

eulers_error_curve::eulers_error_curve()
{
    // create curve for Euler's method
    this->setTitle( "Euler's method approximation error curve" );
    this->setPen( Qt::red, 5 ); // color and thickness of a curve
    this->setRenderHint
            ( QwtPlotItem::RenderAntialiased, true ); // antialiasing

    // graphical representation of points
    QwtSymbol *approximation_error_symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::black ), QPen( Qt::darkGray, 2 ), QSize( 7, 7 ) );
    this->setSymbol( approximation_error_symbol );

    // applying Euler's method to get points for our curve
    eulers_method *euler = new eulers_method(QPointF(X0, Y0), STEP, BORDER_X);
    euler->compute_approximation();
    QPolygonF euler_points = euler->get_approximation().second;

    //attach points to the curves
    this->setSamples( euler_points );
}

void eulers_error_curve::attach_to_plot(QwtPlot *d_plot)  {
    approximation_curve::attach_to_plot(d_plot);
}

