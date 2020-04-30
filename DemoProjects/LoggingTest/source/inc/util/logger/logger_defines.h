#ifndef LOGGER_DEFINES_H_
#define LOGGER_DEFINES_H_

#ifndef _WIN32
  #define LOGGER_DLLEXPORT
#else
  #ifdef LOGGER_LIB_EXPORT
    #define LOGGER_DLLEXPORT __declspec(dllexport)
	#pragma message("---LOGGER exporting")
  #else
    #define LOGGER_DLLEXPORT __declspec(dllimport)
	#pragma message("---LOGGER importing")
  #endif
  
#endif
  
#endif
