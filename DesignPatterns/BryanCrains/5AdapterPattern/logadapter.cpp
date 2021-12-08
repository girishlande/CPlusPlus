#include "logadapter.h"
#include <qdatetime.h>

LogAdapter::LogAdapter(QObject *parent) : QObject(parent)
{

}

void LogAdapter::write(QString message) {
    QString timestamp = QDateTime::currentDateTime().toString();
    QString msg = timestamp + " : " + message;
    m_logger.write(msg);
}
