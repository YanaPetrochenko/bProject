#include "developer.h"

Developer::Developer(const QString &name):
    name_(name)
{
}

void Developer::setName(const QString &name)
{
    name_=name;
}

QString Developer::name() const
{
    return name_;
}
