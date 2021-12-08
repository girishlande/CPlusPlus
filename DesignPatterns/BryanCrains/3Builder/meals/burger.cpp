#include "burger.h"

Burger::Burger(QObject *parent) : QObject(parent)
{
    qInfo() << this << "created";
}

Burger::~Burger()
{
   qInfo() << this << "destroyed";
}

void Burger::prepair()
{
    qInfo() << this << "prepairing";

    qInfo() << this << "grilling patty";
    qInfo() << this << "toasting bun";

    foreach(QString item, m_list)
    {
        qInfo() << this << "adding" << item;
    }

    qInfo() << this << "complete";
}

QStringList Burger::ingredients()
{
    return m_list;
}

void Burger::setIngredients(QStringList list)
{
    m_list = list;
}

void Burger::show()
{
    qInfo() << this << "burger with:";
    foreach(QString item, m_list)
    {
        qInfo() << "-" << item;
    }
}
