#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{

}

void Person::placeBids(QString item)
{
    //I MUST HAVE IT!!!!

    Q_UNUSED(item);

    int value = QRandomGenerator::global()->bounded(1,100000);
     emit bid(value);
}
