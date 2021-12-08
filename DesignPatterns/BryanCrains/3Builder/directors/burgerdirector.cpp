#include "burgerdirector.h"

BurgerDirector::BurgerDirector(QObject *parent) : QObject(parent)
{
    qInfo() << this << "created";
}

BurgerDirector::~BurgerDirector()
{
    qInfo() << this << "destroyed";
}

iMeal *BurgerDirector::create(iBuilder *builder)
{
    qInfo() << this << "building a burger";

    //Do things in the order you want
    //builder->someting();

    return builder->build();
}
