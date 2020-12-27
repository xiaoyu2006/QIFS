#ifndef IFSRENDERINGWIDGET_H
#define IFSRENDERINGWIDGET_H

#include <QWidget>

#include "ifscalccore.h"

class IFSRenderingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IFSRenderingWidget(QWidget *parent = nullptr);

signals:

private:
    IFSCalcCore calculator;
};

#endif // IFSRENDERINGWIDGET_H
