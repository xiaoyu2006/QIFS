#ifndef IFSRENDERDIALOG_H
#define IFSRENDERDIALOG_H

#include <QDialog>

namespace Ui {
class IFSRenderDialog;
}

class IFSRenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IFSRenderDialog(QWidget *parent = nullptr);
    ~IFSRenderDialog();

private:
    Ui::IFSRenderDialog *ui;
};

#endif // IFSRENDERDIALOG_H
