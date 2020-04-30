#ifndef _LOGGER_NULL_H_
#define _LOGGER_NULL_H_

#include "util/logger/logger_defines.h"
#include "Logger.h"

class LOGGER_DLLEXPORT LoggerNull : public Logger
{
public:
  LoggerNull() {}
  virtual ~LoggerNull() {}

  virtual void Init(const char* c) {}
  virtual void LogInfo(const char* source_file, int line_num, const char* c, ...) {}
  virtual void LogError(const char* source_file, int line_num, const char* c, ...) {}
  virtual void LogWarning(const char* source_file, int line_num, const char* c, ...) {}
  virtual void LogDebug(const char* source_file, int line_num, const char* c, ...) {}

protected:
  virtual void Flush_() {}
};

#endif
