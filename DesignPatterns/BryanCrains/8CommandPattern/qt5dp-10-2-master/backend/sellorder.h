#ifndef SELLORDER_H
#define SELLORDER_H

#include <QObject>
#include <QDebug>
#include "stock.h"
#include "../interfaces/iOrder.h"


class SellOrder : public QObject, public iOrder
{
    Q_OBJECT
public:
    explicit SellOrder(Stock *stock,QObject *parent = nullptr);
    void execute() override;
    Stock *stock() const;

signals:


private:
    Stock *m_stock;
};
#endif // SELLORDER_H
