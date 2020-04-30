#include <iomanip>
#include <cstdarg>
#include <ctime>
#include <cstdio>
#include <cstring>
#include "util/logger/LoggerStdOut.h"

LoggerStdOut::LoggerStdOut() {
}

void LoggerStdOut::Init(const char* c) {
}

void LoggerStdOut::LogInfo(
	const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("INFO", source_file, line_num, stdout, format, argp);
  va_end(argp); 
}

void LoggerStdOut::LogError(
        const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("ERROR", source_file, line_num, stderr, format, argp);
  va_end(argp); 
}

void LoggerStdOut::LogWarning(
	const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("WARN", source_file, line_num, stderr, format, argp);
  va_end(argp); 
}

void LoggerStdOut::LogDebug(
	const char* source_file, int line_num, const char* format, ...) {

  va_list argp;
  va_start(argp, format);
  LogFormattedMessage("DEBUG", source_file, line_num, stdout, format, argp);
  va_end(argp);
}

void LoggerStdOut::LogFormattedMessage(
	const char* level, const char* source_file, int line_num,
	FILE* fp, const char* format, va_list argp) {

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
  fprintf(fp, "%s\n", buffer);
}

void LoggerStdOut::Flush_()
{
  fflush(stdout);
}
