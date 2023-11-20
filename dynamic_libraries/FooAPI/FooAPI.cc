#include "FooAPI.h"
#include <QDebug>

FooAPI::FooAPI()
{
}

void FooAPI::foo()
{
    qDebug() << "Call foo.";
}

int FooAPI::sum(int a, int b)
{
    return a + b;
}
