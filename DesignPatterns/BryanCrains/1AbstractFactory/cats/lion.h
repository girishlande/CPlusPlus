#ifndef LION_H
#define LION_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iAnimal.h"

class Lion : public QObject, public iAnimal
{
    Q_OBJECT
public:
    explicit Lion(QObject *parent = nullptr);
    ~Lion();
signals:


    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // LION_H
