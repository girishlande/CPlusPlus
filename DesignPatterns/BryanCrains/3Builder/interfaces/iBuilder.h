#ifndef IBUILDER_H
#define IBUILDER_H

#include <QString>
#include <QStringList>
#include "iMeal.h"


class iBuilder
{
public:

    virtual void setIngredients(QStringList value) = 0;
    virtual void prepair() = 0;
    virtual void cook() = 0;
    virtual iMeal* build() = 0;
    virtual ~iBuilder() {}; //we are going to make some people mad... but we need to free the memory

};

#endif // IBUILDER_H
