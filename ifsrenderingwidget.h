#ifndef IFSRENDERINGWIDGET_H
#define IFSRENDERINGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QResizeEvent>

#include "ifscalccore.h"

class IFSRenderingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IFSRenderingWidget(QWidget *parent = nullptr);
    ~IFSRenderingWidget();
    void addFunction(TransformFunction f);

    void step();
    
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

signals:

private:
    IFSCalcCore calculator;
    QPixmap* buffer;
};

#endif // IFSRENDERINGWIDGET_H
