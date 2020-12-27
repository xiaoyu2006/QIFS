#ifndef TRANSFORMFUNCTIONDISPLAY_H
#define TRANSFORMFUNCTIONDISPLAY_H

#include <QWidget>
#include "transformfunction.h"

namespace Ui {
class TransformFunctionDisplay;
}

class TransformFunctionDisplay : public QWidget
{
    Q_OBJECT

public:

    explicit TransformFunctionDisplay(QWidget *parent = nullptr);
    ~TransformFunctionDisplay();
    void setFunction(TransformFunction f);

    TransformFunction getFunction();

private slots:

    void on_doubleSpinBox_valueChanged(double arg);
    void on_doubleSpinBox_2_valueChanged(double arg);
    void on_doubleSpinBox_3_valueChanged(double arg);
    void on_doubleSpinBox_4_valueChanged(double arg);
    void on_doubleSpinBox_5_valueChanged(double arg);
    void on_doubleSpinBox_6_valueChanged(double arg);

    void on_doubleSpinBox_widget_valueChanged(double arg);

private:

    Ui::TransformFunctionDisplay* ui;
    TransformFunction f;
};

#endif // TRANSFORMFUNCTIONDISPLAY_H
