#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdarg>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// this is a backup to defaults somehow not being set in CMake
#ifndef LOGGER_LOG_PATH
  #ifdef __linux__
    #define LOGGER_LOG_PATH "/tmp/log/"
  #elif _WIN32
    #define LOGGER_LOG_PATH "C:\\Faxitron\\log\\"
  #endif
#endif

// same
#ifndef LOG_FILE_PREFIX
  #define LOG_FILE_PREFIX "imager-"
#endif
#ifndef LOG_FILE_SUFFIX
  #define LOG_FILE_SUFFIX ".log"
#endif

#include "util/logger/LoggerToFile.h"

LoggerToFile::LoggerToFile() 
  : prefix_(LOG_FILE_PREFIX),
    suffix_(LOG_FILE_SUFFIX) 
{

  std::time_t t = std::time(nullptr);
  struct std::tm* plt = std::localtime(&t);
  char date_buffer[32];
  strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d-%H", plt);

  current_date_time_ = GetDateTimeString();

  file_name_.append(prefix_);
  file_name_.append(GetDateTimeString());
  file_name_.append(suffix_);

  #ifdef __linux__
    std::string root_path = LOGGER_LOG_PATH;
    if (!PathExists(root_path)) {
      mkdir(root_path.c_str(), ACCESSPERMS);
    }

  #elif _WIN32
    std:: string root_path = LOGGER_LOG_PATH;
    if (!PathExists(root_path)) {
      _mkdir(root_path.c_str());
    }

  #else
    // give up and write log to active dir
  #endif

  file_path_ = root_path;
  std::string full_path = file_path_;
  full_path.append(file_name_); 
  fp_ = fopen(full_path.c_str(), "a");

}

LoggerToFile::~LoggerToFile() {
  if(fp_) fclose(fp_);
}

void LoggerToFile::SetPrefix(std::string prefix) {
  prefix_ = prefix;
}

void LoggerToFile::SetSuffix(std::string suffix) {
  suffix_ = suffix;
}

void LoggerToFile::Init(const char* c) {

}

void LoggerToFile::LogInfo(
	const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("INFO", source_file, line_num, fp_, format, argp);
  va_end(argp);
}

void LoggerToFile::LogError(
	const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("ERROR", source_file, line_num, fp_, format, argp);
  va_end(argp);
}

void LoggerToFile::LogWarning(
	const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("WARN", source_file, line_num, fp_, format, argp);
  va_end(argp);
}

void LoggerToFile::LogDebug(
	const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("DEBUG", source_file, line_num, fp_, format, argp);
  va_end(argp);
}

void LoggerToFile::LogFormattedMessage(
	const char* level, const char* source_file, int line_num,
	FILE* fp, const char* format, va_list argp) {

  // if the hour has changed we will start a new file
  std::string tmp;
  tmp = GetDateTimeString();
  if (tmp != current_date_time_) {
    UpdatePaths(tmp);
  }

  std::time_t t = std::time(nullptr);
  struct std::tm* plt = std::localtime(&t);

  const unsigned int buff_sz = 1024;
  char buffer[buff_sz];

  // show only name of file, not full path
  const char* last_slash = strrchr(source_file, '/');
  #ifdef _WIN32
    last_slash = strrchr(source_file, '\\');
  #endif
  const char* file_name = last_slash + 1;

  strftime(buffer, 12, "[%H:%M:%S]", plt);
  sprintf(&buffer[strlen(buffer)], " %-25s (%4d): %-5s: ", file_name, line_num, level);

  vsnprintf(&buffer[strlen(buffer)], buff_sz - strlen(buffer), format, argp);
  #ifdef _WIN32
    fprintf(fp, "%s\n", buffer);
  #else
    fprintf(fp, "%s\n", buffer);
  #endif

}

bool LoggerToFile::PathExists(std::string path) {
  struct stat info;
  if (0 != stat( path.c_str(), &info ) ) {
    return false;
  } else if (info.st_mode & S_IFDIR) {
    return true;
  } else {
    return false;
  }
}

std::string LoggerToFile::GetDateTimeString()
{
  std::time_t t = std::time(nullptr);
  struct std::tm* plt = std::localtime(&t);
  char date_buffer[32];
  strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d-%H", plt);

  std::string ret;
  ret.append(date_buffer);
  return ret;
} 

void LoggerToFile::UpdatePaths(std::string new_date_time) {
  current_date_time_ = new_date_time;
  if (fp_) fclose(fp_);
  file_name_= prefix_;
  file_name_.append(new_date_time);
  file_name_.append(suffix_);

  std::string full_path = file_path_;
  full_path.append(file_name_);
  fp_ = fopen(full_path.c_str(), "a");

  return;
}

void LoggerToFile::Flush_()
{
  fflush(fp_);
}
