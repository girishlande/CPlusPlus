#include "util/logger/Logger.h"
#include "util/logger/LoggerNull.h"
// the default logger will be log to null for safety

LOGGER_DLLEXPORT Logger* Logger::logger_ = nullptr;
LOGGER_DLLEXPORT std::mutex Logger::lock_;

Logger::Logger() {

}

Logger* Logger::GetLogger() {
  std::unique_lock<std::mutex> lk(lock_);
  if (!logger_) {
    logger_ = new LoggerNull();
  }
  return logger_;
}

void Logger::SetLogger(Logger* logger) {
  std::unique_lock<std::mutex> lk(lock_);
  logger_ = logger;
}

void Logger::ResetLogger() {
  std::unique_lock<std::mutex> lk(lock_);
  delete logger_;
  logger_ = nullptr;
}

void Logger::Flush() {
  if (logger_) logger_->Flush_();
}
