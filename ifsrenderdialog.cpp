#include "ifsrenderdialog.h"
#include "ui_ifsrenderdialog.h"

IFSRenderDialog::IFSRenderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IFSRenderDialog)
{
    ui->setupUi(this);
}

IFSRenderDialog::~IFSRenderDialog()
{
    delete ui;
}

void IFSRenderDialog::timerEvent(QTimerEvent *event) {
    if (event->timerId() == this->timer) {
        ui->renderResult->step();
    }
}

void IFSRenderDialog::addFunction(TransformFunction f) {
    ui->renderResult->addFunction(f);
}

void IFSRenderDialog::toggleExecutingMode(int t)
{
    if (started) {
        this->killTimer(this->timer);
        ui->startButton->setText("Start");
    } else {
        this->timer = this->startTimer(t);
        ui->startButton->setText("End");
    }
    started = !started;
}

void IFSRenderDialog::on_startButton_released()
{
    toggleExecutingMode(ui->updTimer->value());
}

void IFSRenderDialog::on_updTimer_valueChanged(int arg)
{
    if (!started) return;
    toggleExecutingMode(arg);
    toggleExecutingMode(arg);
}
