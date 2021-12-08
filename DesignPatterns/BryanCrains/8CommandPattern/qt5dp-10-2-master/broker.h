#ifndef BROKER_H
#define BROKER_H

#include <QObject>
#include <QDebug>
#include "interfaces/iOrder.h"

class Broker : public QObject
{
    Q_OBJECT
public:
    explicit Broker(QObject *parent = nullptr);
    ~Broker();

    void addOrder(iOrder* order);
    void placeOrders();

signals:

private:
    QList<iOrder*> m_orders;
    void cleanup();

};

#endif // BROKER_H
