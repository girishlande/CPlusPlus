#ifndef BOBCAT_H
#define BOBCAT_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iAnimal.h"

class BobCat : public QObject, public iAnimal
{
    Q_OBJECT
public:
    explicit BobCat(QObject *parent = nullptr);
    ~BobCat();
signals:


    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // BOBCAT_H
