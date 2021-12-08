#include "catfactory.h"

CatFactory::CatFactory(QObject *parent) : QObject(parent)
{

}


iAnimal *CatFactory::createSmall()
{
    return new HouseCat();
}

iAnimal *CatFactory::createMedium()
{
    return new BobCat();
}

iAnimal *CatFactory::createLarge()
{
    return new Lion();
}
