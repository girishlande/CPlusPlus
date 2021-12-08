#include "bobcat.h"

BobCat::BobCat(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created";
}

BobCat::~BobCat()
{
    qInfo() << this << "Destroyed";
}

void BobCat::eat()
{
    qInfo() << this << "Eat";
}

void BobCat::sleep()
{
    qInfo() << this << "Sleep";
}

void BobCat::move()
{
    qInfo() << this << "Move";
}
