#ifndef IFSINPUT_H
#define IFSINPUT_H

#include <QMainWindow>
#include <QFileDialog>

#include <vector>
#include <iostream>
#include <fstream>

#include "transformfunction.h"
#include "transformfunctiondisplay.h"
#include "ifsrenderdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IFSInput; }
QT_END_NAMESPACE

class IFSInput : public QMainWindow
{
    Q_OBJECT

public:

    IFSInput(QWidget *parent = nullptr);
    ~IFSInput();

private slots:
    void on_addButton_released();

    void on_clearAllButton_released();

    void on_saveButton_released();

    void on_loadButton_released();

    void on_renderButton_released();

private:
    void addFunction(TransformFunction f);
    void clearAllFunction();

    Ui::IFSInput* ui;
    std::vector<TransformFunctionDisplay*> displays;
};
#endif // IFSINPUT_H
