#include "AppWindow.h"

#include <QApplication>
#include "EditableButton.h"
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    AppWindow w;
//    w.show();
    QDialog dlg;
    dlg.resize(480, 320);
    EditableButton btn(&dlg);
    btn.move(100, 100);
    dlg.show();
    return a.exec();
}
