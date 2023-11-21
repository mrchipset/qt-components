#include "SimpleROInterface.h"
#include <QDebug>

SimpleROInterface::SimpleROInterface(QObject *parent)
    : SimpleROInterfaceSource{parent}
{

}

void SimpleROInterface::sendMessage(const QString &_message)
{
    Q_EMIT message(_message);
}

void SimpleROInterface::onMessage(const QString &message)
{
    qDebug() << "Client -> Server Message:" << message;
    QString flipMessage = message;
    std::reverse(flipMessage.begin(), flipMessage.end());
    sendMessage(flipMessage);
}
