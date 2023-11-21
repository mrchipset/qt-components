#ifndef SIMPLEROINTERFACE_H
#define SIMPLEROINTERFACE_H

#include <QObject>
#include "rep_SimpleRO_source.h"

class SimpleROInterface : public SimpleROInterfaceSource
{
    Q_OBJECT
public:
    explicit SimpleROInterface(QObject *parent = nullptr);

    void sendMessage(const QString& message);
public Q_SLOTS:
    virtual void onMessage(const QString& message) override;

};

#endif // SIMPLEROINTERFACE_H
