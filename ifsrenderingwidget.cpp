#include "ifsrenderingwidget.h"

IFSRenderingWidget::IFSRenderingWidget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(640, 320);
    buffer = new QPixmap(10000, 10000);
    QPainter painter(buffer);
    painter.fillRect(0, 0, 10000, 10000, Qt::white);
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

void IFSRenderingWidget::step()
{
    QPainter painter;
    painter.begin(buffer);
    Point toDraw = calculator.step();
    double w = 600, h = 300;
    double x = (toDraw.x + 2) * w * 0.2;
    double y = (toDraw.y + 2) * h * 0.2;
    painter.drawPoint(x, y);
    painter.end();
    this->update();
}

void IFSRenderingWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0, 0, *buffer);
    painter.end();
}
