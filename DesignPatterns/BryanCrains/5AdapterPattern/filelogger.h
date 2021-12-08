#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <QObject>

class FileLogger : public QObject
{
    Q_OBJECT
public:
    explicit FileLogger(QObject *parent = nullptr);

    void write(QString message);

};

#endif // FILELOGGER_H
