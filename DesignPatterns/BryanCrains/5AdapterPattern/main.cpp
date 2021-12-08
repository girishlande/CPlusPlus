#include <QCoreApplication>
#include "filelogger.h"
#include "logadapter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileLogger logger;
    logger.write("Hello Girish");


    LogAdapter adapter;
    adapter.write("How are you??");

    return a.exec();
}
