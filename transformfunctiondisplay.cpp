#include "transformfunctiondisplay.h"
#include "ui_transformfunctiondisplay.h"

TransformFunctionDisplay::TransformFunctionDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransformFunctionDisplay)
{
    ui->setupUi(this);
}

TransformFunctionDisplay::~TransformFunctionDisplay()
{
    delete ui;
}

void TransformFunctionDisplay::setFunction(TransformFunction f)
{
    ui->doubleSpinBox->setValue(f.a);
    ui->doubleSpinBox_2->setValue(f.b);
    ui->doubleSpinBox_3->setValue(f.c);
    ui->doubleSpinBox_4->setValue(f.d);
    ui->doubleSpinBox_5->setValue(f.e);
    ui->doubleSpinBox_6->setValue(f.f);
    ui->doubleSpinBox_widget->setValue(f.weight);
    this->f = f;
}

void TransformFunctionDisplay::on_doubleSpinBox_valueChanged(double arg)
{
    this->f.a = arg;
}

void TransformFunctionDisplay::on_doubleSpinBox_2_valueChanged(double arg)
{
    this->f.b = arg;
}

void TransformFunctionDisplay::on_doubleSpinBox_3_valueChanged(double arg)
{
    this->f.c = arg;
}

void TransformFunctionDisplay::on_doubleSpinBox_4_valueChanged(double arg)
{
    this->f.d = arg;
}

void TransformFunctionDisplay::on_doubleSpinBox_5_valueChanged(double arg)
{
    this->f.e = arg;
}

void TransformFunctionDisplay::on_doubleSpinBox_6_valueChanged(double arg)
{
    this->f.f = arg;
}

void TransformFunctionDisplay::on_doubleSpinBox_widget_valueChanged(double arg)
{
    this->f.weight = arg;
}

TransformFunction TransformFunctionDisplay::getFunction() {
    return this->f;
}
