#include "ifsinput.h"
#include "./ui_ifsinput.h"

IFSInput::IFSInput(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IFSInput)
{
    ui->setupUi(this);
    displays.clear();
}

IFSInput::~IFSInput()
{
    delete ui;
}

void IFSInput::addFunction(TransformFunction f)
{
    TransformFunctionDisplay* newDisplay = new TransformFunctionDisplay;
    newDisplay->setFunction(f);
    ui->rules->addWidget(newDisplay);
    displays.push_back(newDisplay);
}

void IFSInput::clearAllFunction()
{
    while (!displays.empty()) {
        // 'past the end of the sequence'
        TransformFunctionDisplay* display = *(displays.end() - 1);
        ui->rules->removeWidget(display);
        delete display;
        displays.pop_back();
    }
}

void IFSInput::on_addButton_released()
{
    this->addFunction(ui->newTranasformFunction->getFunction());
}

void IFSInput::on_clearAllButton_released()
{
    this->clearAllFunction();
}

void IFSInput::on_saveButton_released()
{
    QString saveTo = QFileDialog::getSaveFileName(this, "Save to...");
    std::ofstream file;
    file.open(saveTo.toStdString());
    for (TransformFunctionDisplay* disp : displays) {
        TransformFunction f = disp->getFunction();
        file << f.a << ' ' << f.b << ' ' << f.c << ' ' << f.d << ' ' << f.e << ' '
          << f.f << ' ' << f.weight << std::endl;
    }
}

void IFSInput::on_loadButton_released()
{
    // TODO: impl
}

void IFSInput::on_renderButton_released()
{
    IFSRenderDialog* renderDlg = new IFSRenderDialog(this);
    renderDlg->open();
}
