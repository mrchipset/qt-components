#include "AppWindow.h"

#include <QApplication>
#include "LongPressButton.h"
#include <QDialog>
#include <QDebug>
#include "FooAPI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    AppWindow w;
//    w.show();
    QDialog dlg;
    dlg.resize(480, 320);
    LongPressButton btn(&dlg);
    btn.setText(QObject::tr("Long Press Me"));
    QObject::connect(&btn, &LongPressButton::clicked, [=](){
        qDebug() << "Click";
    });
    QObject::connect(&btn, &LongPressButton::pressed, [=](){
        qDebug() << "Pressed";
    });

    QObject::connect(&btn, &LongPressButton::longPressed, [=](){
        qDebug() << "Long Pressed";
    });
    QObject::connect(&btn, &LongPressButton::released, [=](){
        qDebug() << "Release";
    });
    btn.move(100, 100);
    dlg.show();

    FooAPI foo;
    foo.foo();
    qDebug() << "3 + 5 = " << foo.sum(3, 5);
    return a.exec();
}
