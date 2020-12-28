#ifndef IFSRENDERDIALOG_H
#define IFSRENDERDIALOG_H

#include <QDialog>
#include <QTimerEvent>

#include "transformfunction.h"

namespace Ui {
class IFSRenderDialog;
}

class IFSRenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IFSRenderDialog(QWidget *parent = nullptr);
    ~IFSRenderDialog();

    void addFunction(TransformFunction f);

protected:
    void timerEvent(QTimerEvent *event) override;

private slots:
    void on_startButton_released();

    void on_updTimer_valueChanged(int arg);

private:
    void toggleExecutingMode(int t);

    Ui::IFSRenderDialog *ui;
    bool started = false;
    int timer;
};

#endif // IFSRENDERDIALOG_H
