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
