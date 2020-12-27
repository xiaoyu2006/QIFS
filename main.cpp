#include "ifsinput.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IFSInput w;
    w.show();
    return a.exec();
}
