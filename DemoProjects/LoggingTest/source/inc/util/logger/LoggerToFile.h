#ifndef _LOGGER_TO_FILE_H_
#define _LOGGER_TO_FILE_H_

#include <string>
#include "util/logger/logger_defines.h"
#include "util/logger/Logger.h"

#ifdef _WIN32
// keep windows from complaining about stdlib fields since they are private anyways
// keep windows from complaining about 'safe' version of **print**(...) fncs
#pragma warning( disable: 4251 4996)
#endif

class LOGGER_DLLEXPORT LoggerToFile : public Logger
{
public:
  LoggerToFile();
  ~LoggerToFile();
  void SetPrefix(std::string prefix);
  void SetSuffix(std::string suffix);

  virtual void Init(const char* c);
  virtual void LogInfo(const char* source_file, int line_num, const char* format, ...);
  virtual void LogError(const char* source_file, int line_num, const char* format, ...);
  virtual void LogWarning(const char* source_file, int line_num, const char* format, ...);
  virtual void LogDebug(const char* source_file, int line_num, const char* format, ...);

protected:
  virtual void LogFormattedMessage(const char* level, const char* source_file, int line_num, FILE* fp, const char* format, va_list argp);
  virtual void Flush_();

private:
  std::string current_date_time_;
  std::string file_path_;
  std::string file_name_;
  std::string prefix_;
  std::string suffix_;
  FILE* fp_;
  bool PathExists(std::string path);
  std::string GetDateTimeString();
  void UpdatePaths(std::string new_date_time);
};

#endif
