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


}

AppWindow::~AppWindow()
{
    delete ui;
}

