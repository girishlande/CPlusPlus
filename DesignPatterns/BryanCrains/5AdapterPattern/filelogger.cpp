#include "filelogger.h"
#include <qtextstream.h>
#include <QFile>
#include <qdebug.h>

FileLogger::FileLogger(QObject *parent) : QObject(parent)
{

}

void FileLogger::write(QString message) {
    QFile file("log.txt");
    if (!file.open(QIODevice::Append)) {
        qCritical() << "File cannot be opened";
        return;
    }

    QTextStream stream(&file);
    stream << message << "\n";
    file.close();

    qInfo() << "Logged:" << message;
}
