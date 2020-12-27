#ifndef TRANSFORMFUNCTION_H
#define TRANSFORMFUNCTION_H


struct Point {
    double x, y;

    Point();
    Point(double x, double y);
};


class TransformFunction
{
public:

    TransformFunction();

    void setWidget(double w);
    double getWidget();

    Point transform(Point P);

    double weight;
    double a, b, c, d, e, f;
};


#endif // TRANSFORMFUNCTION_H
