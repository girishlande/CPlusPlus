#include <QCoreApplication>

/*

  What
  Creational - Abstract Factory

  Description
  Create related items without specifying a concrete class

  Why
  Future proof the application

  Example
  "Think of constructors as factories that churn out objects".
  https://sourcemaking.com/design_patterns/abstract_factory

 */

#include <QDebug>
#include <QRandomGenerator>
#include "cats/catfactory.h"
#include "interfaces/iAnimal.h"

void makeAnimals(QList<iAnimal*> &animals, int count)
{
    CatFactory factory;

    for(int i = 0; i < count; i++)
    {
        iAnimal* animal;
        int value = QRandomGenerator::global()->bounded(0,3);

        switch (value) {
        case 0:
            animal = factory.createSmall();
            break;
        case 1:
            animal = factory.createMedium();
            break;
        case 2:
            animal = factory.createLarge();
            break;
        default:
            qInfo() << "OTHER";
        }

        animals.append(animal);
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<iAnimal*> animals;
    makeAnimals(animals, 25);

    foreach(iAnimal* animal, animals)
    {
        animal->eat();
        animal->sleep();
    }

    qDeleteAll(animals);
    animals.clear();


    return a.exec();
}
