#ifndef AUCTIONEER_H
#define AUCTIONEER_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QTimer>

class Auctioneer : public QObject
{
    Q_OBJECT
public:
    explicit Auctioneer(QObject *parent = nullptr);

    void sellThing(QString item, int limit);

signals:
    void placeBids(QString item);

public slots:
    void bid(int value);

private slots:
    void timeout();

private:
    QTimer m_timer;
    int m_limit;
    int m_count;
    QString m_item;
    QMap<QObject*,int> m_bids;

    void pickWinner();

};

#endif // AUCTIONEER_H
