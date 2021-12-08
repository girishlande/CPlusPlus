#include "lion.h"

Lion::Lion(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created";
}

Lion::~Lion()
{
    qInfo() << this << "Destroyed";
}

void Lion::eat()
{
    qInfo() << this << "Eat";
}

void Lion::sleep()
{
    qInfo() << this << "Sleep";
}

void Lion::move()
{
    qInfo() << this << "Move";
}
