#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mRemoteNode = new QRemoteObjectNode(this);
    qDebug() << "Connected: " << mRemoteNode->connectToNode(QUrl("local:interfaces"));
    mSimpleROInterface = mRemoteNode->acquire<SimpleROInterfaceReplica>();

    connect(mSimpleROInterface, &SimpleROInterfaceReplica::message, this, &MainWindow::onReceivedMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReceivedMessage(const QString &message)
{
    const QString str = QString("Server -> Client:").append(message);
    qDebug() << str;
    ui->TXT->append(str);
}


void MainWindow::on_PB_SEND_clicked()
{
    const QString message = ui->LE_MSG->text();
    if (message.isEmpty()) {
        return;
    }

    mSimpleROInterface->onMessage(message);
    const QString str = QString("Client -> Server:").append(message);
    ui->TXT->append(str);

}

