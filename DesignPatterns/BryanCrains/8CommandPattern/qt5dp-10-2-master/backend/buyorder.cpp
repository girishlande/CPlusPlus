#include "buyorder.h"

BuyOrder::BuyOrder(Stock *stock, QObject *parent) : QObject(parent)
{
    qInfo() << this << "Create" << stock;
    m_stock = stock;
    if(m_stock) m_stock->setParent(this);
}


void BuyOrder::execute()
{
    qInfo() << this << "Execute" << m_stock;
    if(!m_stock) return;
    m_stock->buy();
}

Stock *BuyOrder::stock() const
{
    return m_stock;
}
