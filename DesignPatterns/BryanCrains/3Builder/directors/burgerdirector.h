#ifndef BURGERDIRECTOR_H
#define BURGERDIRECTOR_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iDirector.h"
#include "../interfaces/iBuilder.h"
#include "../interfaces/iMeal.h"


class BurgerDirector : public QObject, public iDirector
{
    Q_OBJECT
public:
    explicit BurgerDirector(QObject *parent = nullptr);
    ~BurgerDirector();
signals:


    // iDirector interface
public:
    iMeal *create(iBuilder *builder) override;
};

#endif // BURGERDIRECTOR_H
