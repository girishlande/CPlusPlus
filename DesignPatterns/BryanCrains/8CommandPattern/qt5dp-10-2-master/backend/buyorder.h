#ifndef BUYORDER_H
#define BUYORDER_H

#include <QObject>
#include <QDebug>
#include "stock.h"
#include "../interfaces/iOrder.h"

class BuyOrder : public QObject, public iOrder
{
    Q_OBJECT
public:
    explicit BuyOrder(Stock *stock,QObject *parent = nullptr);
    void execute() override;
    Stock *stock() const;

signals:


private:
    Stock *m_stock;
};

#endif // BUYORDER_H
