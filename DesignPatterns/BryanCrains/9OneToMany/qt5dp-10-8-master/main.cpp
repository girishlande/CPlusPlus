#include <QCoreApplication>

/*

  What
  Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

  Description
  Event notifications in objects

  Why
  We want to know something happened, and want to react to it

  Exmaple
  More Signals and Slot - Qt makes a lot of these issues go away

 */

#include "auctioneer.h"
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Auctioneer sales;
    QList<QObject*> people;

    for(int i = 0; i < 5; i++)
    {
        Person *p = new Person(&sales);
        p->setObjectName("Person" + QString::number(i));
        people.append(p);

        QObject::connect(&sales,&Auctioneer::placeBids, p, &Person::placeBids);
        QObject::connect(p,&Person::bid, &sales, &Auctioneer::bid);
    }

    sales.sellThing("cat", 5);

    return a.exec();
}
