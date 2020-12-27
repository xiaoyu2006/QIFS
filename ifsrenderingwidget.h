#ifndef IFSRENDERINGWIDGET_H
#define IFSRENDERINGWIDGET_H

#include <QWidget>
#include <QPainter>

#include "ifscalccore.h"

class IFSRenderingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IFSRenderingWidget(QWidget *parent = nullptr);
    void addFunction(TransformFunction f);
    void step();

signals:

private:
    IFSCalcCore calculator;
    QPainter* painter;
};

#endif // IFSRENDERINGWIDGET_H
