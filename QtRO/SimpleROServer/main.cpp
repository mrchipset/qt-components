#include <QCoreApplication>
#include <QRemoteObjectHost>
#include "SimpleROInterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto host = new QRemoteObjectHost(&a);
    host->setHostUrl(QUrl("local:interfaces"));
    auto interface = new SimpleROInterface(&a);
    host->enableRemoting(interface);

    return a.exec();
}
