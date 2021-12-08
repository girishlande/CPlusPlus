#include <QCoreApplication>

/*

  What
  Command pattern

  Description
  Object is used to encapsulate all information needed to perform an action or trigger an event at a later time

  Why
  Encapsulates business logic

  Example
  Stocks
  https://sourcemaking.com/design_patterns/command

 */

#include <QDebug>
#include "backend/buyorder.h"
#include "backend/sellorder.h"
#include "backend/stock.h"
#include "broker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        Broker broker;
        qInfo() << "Adding orders";
        broker.addOrder(new BuyOrder(new Stock("AAPL", 100)));
        broker.addOrder(new SellOrder(new Stock("JNJ", 15)));
        broker.addOrder(new BuyOrder(new Stock("ATVI", 5)));

        qInfo() << "Place orders...";
        broker.placeOrders();
    }

    return a.exec();
}
