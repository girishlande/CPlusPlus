#ifndef BURGER_H
#define BURGER_H

#include <QObject>
#include <QDebug>
#include <QStringList>
#include "../interfaces/iMeal.h"

class Burger : public QObject, public iMeal
{
    Q_OBJECT
public:
    explicit Burger(QObject *parent = nullptr);
    ~Burger();
signals:


    // iMeal interface
public:
    void prepair() override;
    QStringList ingredients() override;
    void setIngredients(QStringList list) override;
    void show() override;

private:
    QStringList m_list;



};

#endif // BURGER_H
