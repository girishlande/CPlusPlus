#ifndef CATFACTORY_H
#define CATFACTORY_H

#include <QObject>
#include "housecat.h"
#include "bobcat.h"
#include "lion.h"
#include "../interfaces/iAnimalFactory.h"

class CatFactory : public QObject, public iAnimalFactory
{
    Q_OBJECT
public:
    explicit CatFactory(QObject *parent = nullptr);

signals:


    // iAnimalFactory interface
public:
    iAnimal *createSmall() override;
    iAnimal *createMedium() override;
    iAnimal *createLarge() override;
};

#endif // CATFACTORY_H
