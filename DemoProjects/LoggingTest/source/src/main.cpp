#include <iostream>

#include "util/logger/Logger.h"
#include "util/logger/LoggerToFile.h"
#include "util/logger/LoggerStdOut.h"

int main(int argc, char** argv)
{
  std::cout<<"This is main"<<std::endl;
  
  Logger* logger_to_file = new LoggerToFile();
  Logger::SetLogger(logger_to_file);
  
   return 0;
}
