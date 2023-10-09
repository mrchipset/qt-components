#include "AppWindow.h"
#include "ui_AppWindow.h"
#include <QDebug>
#include <QThread>
#include <QtConcurrent>
#include <QApplication>

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    qDebug() <<"MainWindow" << qApp->thread()->currentThreadId();

    QtConcurrent::run([](){
        for (int i = 0; i < 10; ++i) {
            qDebug() << "This concurrent:" << QThread::currentThreadId();
            qDebug() <<"Concurrent qApp Id is same to concurrent:" << (QThread::currentThread() == qApp->thread());
            QThread::msleep(50);
        }

    });
}

AppWindow::~AppWindow()
{
    delete ui;
}

