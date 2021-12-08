#ifndef STOCK_H
#define STOCK_H

#include <QObject>
#include <QDebug>

class Stock : public QObject
{
    Q_OBJECT
public:
    explicit Stock(QString name, int value, QObject *parent = nullptr);

    QString symbol() const;
    void setSymbol(const QString &symbol);

    int quantity() const;
    void setQuantity(int quantity);

    void buy();
    void sell();

signals:

private:
    QString m_symbol;
    int m_quantity;

};

#endif // STOCK_H
