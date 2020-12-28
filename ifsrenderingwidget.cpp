#include "ifsrenderingwidget.h"

IFSRenderingWidget::IFSRenderingWidget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(640, 320);
    buffer = new QPixmap(size());
    QPainter painter(buffer);
    painter.fillRect(0, 0, width(), height(), Qt::white);
    painter.end();
}

IFSRenderingWidget::~IFSRenderingWidget()
{
    delete buffer;
}

void IFSRenderingWidget::resizeEvent(QResizeEvent *event)
{
}

void IFSRenderingWidget::addFunction(TransformFunction f)
{
    calculator.addFunction(f);
}

void IFSRenderingWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter;

    painter.begin(buffer);
    Point toDraw = calculator.step();
    double w = buffer->width(), h = buffer->height();
    double x = toDraw.x * w, y = toDraw.y * h;
    painter.drawPoint(x, y);
    painter.end();

    painter.begin(this);
    painter.drawPixmap(0, 0, *buffer);
    painter.end();
}
