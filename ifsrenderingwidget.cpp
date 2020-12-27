#include "ifsrenderingwidget.h"

IFSRenderingWidget::IFSRenderingWidget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(640, 320);
    this->painter = new QPainter(this);
}

void IFSRenderingWidget::addFunction(TransformFunction f)
{
    calculator.addFunction(f);
}

void IFSRenderingWidget::step()
{
    Point toDraw = calculator.step();
    painter->fillRect(0, 0, this->width(), this->height(), QColor(0, 0, 0));
}
