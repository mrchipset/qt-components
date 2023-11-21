#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRemoteObjectNode>
#include "rep_SimpleRO_replica.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QRemoteObjectNode* mRemoteNode;
    SimpleROInterfaceReplica* mSimpleROInterface;

private Q_SLOTS:
    void onReceivedMessage(const QString& message);
    void on_PB_SEND_clicked();
};
#endif // MAINWINDOW_H
