#include <QCoreApplication>

/*

  What
  Builder Pattern

  Description
  Separate the construction of a complex object from its representation so that the
  same construction process can create different representations.

  Why
  Constructors are not always the best answer

  Example
  Vehicle builder
  Object - that we are creating
  Builder - creates the complex object
  Director - controls how the builder builds

  Very abstracted at this level!

*/

#include "interfaces/iDirector.h"
#include "interfaces/iBuilder.h"
#include "interfaces/iMeal.h"
#include "directors/burgerdirector.h"
#include "builders/hamburgerbuilder.h"
#include "builders/turkeyburgerbuilder.h"
#include "builders/veggieburgerbuilder.h"
#include "meals/burger.h"
#include <QScopedPointer>

QStringList getToppings()
{
    //Taking the customers order
    QStringList list;
    list.append("pickles");
    list.append("lettuce");
    list.append("ketup");
    list.append("mustard");
    return list;
}

iMeal* buildNormal(iDirector &director)
{
    HamBurgerBuilder builder;
    builder.setIngredients(getToppings());
    return director.create(&builder);
}

iMeal* buildTurkey(iDirector &director)
{
    TurkeyBurgerBuilder builder;
    builder.setIngredients(getToppings());
    return director.create(&builder);
}

iMeal* buildVeggie(iDirector &director)
{
    VeggieBurgerBuilder builder;
    builder.setIngredients(getToppings());
    return director.create(&builder);
}

void test()
{
    BurgerDirector director;

    QScopedPointer<iMeal> p_normal(buildNormal(director));
    p_normal->show();

    QScopedPointer<iMeal> p_turkey(buildTurkey(director));
    p_turkey->show();

    QScopedPointer<iMeal> p_veggie(buildVeggie(director));
    p_veggie->show();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();

    return a.exec();
}
