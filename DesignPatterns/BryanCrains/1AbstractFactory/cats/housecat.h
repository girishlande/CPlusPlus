#ifndef HOUSECAT_H
#define HOUSECAT_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iAnimal.h"

class HouseCat : public QObject, public iAnimal
{
    Q_OBJECT
public:
    explicit HouseCat(QObject *parent = nullptr);
    ~HouseCat();
signals:


    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // HOUSECAT_H
