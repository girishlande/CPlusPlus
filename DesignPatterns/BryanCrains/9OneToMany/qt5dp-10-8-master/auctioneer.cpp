#include "auctioneer.h"

Auctioneer::Auctioneer(QObject *parent) : QObject(parent)
{
    connect(&m_timer,&QTimer::timeout,this, &Auctioneer::timeout);
    m_timer.setInterval(1000);
}

void Auctioneer::sellThing(QString item, int limit)
{
    m_count = limit;
    m_limit = limit;
    m_item = item;

    qInfo() << "Selling: " << m_item << " auction ends in " << m_limit << "seconds";
    m_timer.start();
    emit placeBids(m_item);
}

void Auctioneer::bid(int value)
{
    if(!m_timer.isActive()) return;
    if(!sender()) return;

    m_bids.insert(sender(),value);
    qInfo() << sender() << " bids: " << value;
}

void Auctioneer::timeout()
{
    qInfo() << "Time left:" << m_count;
    m_count--;
    if(m_count <= 0) pickWinner();
}

void Auctioneer::pickWinner()
{
    m_timer.stop();
    QObject *winner;
    int highest = 0;

    foreach(QObject* key, m_bids.keys())
    {
        int value = m_bids.value(key, 0);

        if(value > highest)
        {
            winner = key;
            highest = value;
        }
    }

    if(!winner)
    {
        qInfo() << "No Winners!";
    }
    else
    {
        qInfo() << "Sold to:" << winner << " for " << highest;
    }

    m_bids.clear();
}
