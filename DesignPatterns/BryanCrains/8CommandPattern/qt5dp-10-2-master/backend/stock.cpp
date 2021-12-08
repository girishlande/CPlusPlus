#include "stock.h"

Stock::Stock(QString name, int value, QObject *parent) : QObject(parent)
{
    m_symbol = name;
    m_quantity = value;
}

QString Stock::symbol() const
{
    return m_symbol;
}

void Stock::setSymbol(const QString &symbol)
{
    m_symbol = symbol;
}

int Stock::quantity() const
{
    return m_quantity;
}

void Stock::setQuantity(int quantity)
{
    m_quantity = quantity;
}

void Stock::buy()
{
    qInfo() << "Buying" << m_quantity << "of" << m_symbol;
}

void Stock::sell()
{
    qInfo() << "Selling" << m_quantity << "of" << m_symbol;
}
