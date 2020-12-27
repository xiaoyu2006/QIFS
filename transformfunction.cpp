#include "transformfunction.h"

Point::Point()
{
    this->x = this->y = 0.0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

TransformFunction::TransformFunction()
{
    a = b = c = d = e = f = 0.0;
    weight = 1.0;
}

double TransformFunction::getWidget()
{
    return weight;
}

Point TransformFunction::transform(Point p)
{
    double resultX = a * p.x + b * p.y + c;
    double resultY = d * p.x + e * p.y + f;
    return Point(resultX, resultY);
}
