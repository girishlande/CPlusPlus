#ifndef _LOGGER_BASE_H_
#define _LOGGER_BASE_H_

#include "util/logger/logger_defines.h"
#include <mutex>
#include <string>

#ifdef _WIN32
// keep windows from complaining about stdlib fields since they are private anyways
#pragma warning( disable: 4251)
#endif

class LOGGER_DLLEXPORT Logger
{
public:
  virtual void Init(const char* c) = 0;
  virtual void LogInfo(const char* source_file, int line_num, const char* c, ...) = 0;
  virtual void LogError(const char* source_file, int line_num, const char* c, ...) = 0;
  virtual void LogWarning(const char* source_file, int line_num, const char* c, ...) = 0;
  virtual void LogDebug(const char* source_file, int line_num, const char* c, ...) = 0;

  static Logger* GetLogger();
  static void SetLogger(Logger* logger);
  static void ResetLogger();
  static void Flush();

protected:
  Logger();
  virtual ~Logger() {};
  virtual void Flush_() = 0;

private:
  static std::mutex lock_;
  static Logger* logger_;
};

// macros
#define LOG_INFO(format, ...) Logger::GetLogger()->LogInfo(__FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) Logger::GetLogger()->LogError(__FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_WARNING(format, ...) Logger::GetLogger()->LogWarning(__FILE__, __LINE__, format, ##__VA_ARGS__)

#define LOG_RECON_INFO(format, ...) Logger::GetLogger()->LogInfo(__FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_RECON_ERROR(format, ...) Logger::GetLogger()->LogError(__FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_RECON_WARNING(format, ...) Logger::GetLogger()->LogWarning(__FILE__, __LINE__, format, ##__VA_ARGS__)

#ifdef DEBUG
#define LOG_DEBUG(format, ...) Logger::GetLogger()->LogDebug(__FILE__, __LINE__, format, ##__VA_ARGS__)  
#else
#define LOG_DEBUG(format, ...) 
#endif

#endif
