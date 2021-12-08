#ifndef LOGADAPTER_H
#define LOGADAPTER_H

#include <QObject>
#include "filelogger.h"

class LogAdapter : public QObject
{
    Q_OBJECT
public:
    explicit LogAdapter(QObject *parent = nullptr);

    void write(QString message);

private:
    FileLogger m_logger;

};

#endif // LOGADAPTER_H
