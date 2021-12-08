 #include "sellorder.h"

SellOrder::SellOrder(Stock *stock, QObject *parent) : QObject(parent)
{
    qInfo() << this << "Create" << stock;
    m_stock = stock;
    if(m_stock) m_stock->setParent(this);
}


void SellOrder::execute()
{
    qInfo() << this << "Execute" << m_stock;
    if(!m_stock) return;
    m_stock->sell();
}

Stock *SellOrder::stock() const
{
    return m_stock;
}
