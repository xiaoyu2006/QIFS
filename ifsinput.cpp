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
    if (saveTo=="") return;
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
    QString readFrom = QFileDialog::getOpenFileName(this, "Open...");
    if(readFrom=="") return;
    std::ifstream file;
    file.open(readFrom.toStdString());
    this->clearAllFunction();
    double a, b, c, d, e, f, w;
    while(file >> a >> b >> c >> d >> e >> f >> w) {
        TransformFunction func;
        func.a = a; func.b = b; func.c = c; func.d = f; func.e = e; func.f = f; func.weight = w;
        addFunction(func);
    }
}

void IFSInput::on_renderButton_released()
{
    if (displays.empty()) return;
    IFSRenderDialog* renderDlg = new IFSRenderDialog(this);
    for(auto f : displays) {
        renderDlg->addFunction(f->getFunction());
    }
    renderDlg->exec();
}
