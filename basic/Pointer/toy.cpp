#include "toy.h"

Toy::Toy(QObject *parent, QString name) : QObject(parent)
{
    setObjectName(name);
    qInfo() << "TOY : Constructed" << this;
}

Toy::~Toy()
{
    qInfo() << "TOY : Deconstructed" << this;
}
