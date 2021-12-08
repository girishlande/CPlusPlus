#include "housecat.h"

HouseCat::HouseCat(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created";
}

HouseCat::~HouseCat()
{
    qInfo() << this << "Destroyed";
}

void HouseCat::eat()
{
    qInfo() << this << "Eat";
}

void HouseCat::sleep()
{
    qInfo() << this << "Sleep";
}

void HouseCat::move()
{
    qInfo() << this << "Move";
}
