#ifndef _LOGGER_STDOUT_H_
#define _LOGGER_STDOUT_H_

#include "util/logger/logger_defines.h"
#include "util/logger/Logger.h"

#ifdef _WIN32
// keep windows from complaining about 'safe' version of **print**(...) fncs
#pragma warning( disable: 4996)
#endif

class LOGGER_DLLEXPORT LoggerStdOut : public Logger
{
public:
  LoggerStdOut();

  virtual void Init(const char* c);
  virtual void LogInfo(const char* source_file, int line_num, const char* format, ...);
  virtual void LogError(const char* source_file, int line_num, const char* format, ...);
  virtual void LogWarning(const char* source_file, int line_num, const char* format, ...);
  virtual void LogDebug(const char* source_file, int line_num, const char* format, ...);

protected:
  virtual void LogFormattedMessage(const char* level, const char* source_file, int line_num, FILE* fp, const char* format, va_list argp); 
  virtual void Flush_();
};

#endif
