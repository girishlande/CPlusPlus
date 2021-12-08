#include "broker.h"
#include <qdebug.h>

Broker::Broker(QObject *parent) : QObject(parent)
{
    qInfo() << "Broker created!";
}

Broker::~Broker()
{
    cleanup();
    qInfo() << "Broker deleted!";
}

void Broker::addOrder(iOrder *order)
{
    qInfo() << this << "Adding order" << order;
    m_orders.append(order);
}

void Broker::placeOrders()
{
    foreach (iOrder* order, m_orders)
    {
        qInfo() << this << "Executing order" << order;
        order->execute();
    }
}

void Broker::cleanup()
{
    qDeleteAll(m_orders);
    m_orders.clear();
}
