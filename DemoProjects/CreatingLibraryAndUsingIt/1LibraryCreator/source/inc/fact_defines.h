#ifndef FACT_DEFINES_H_
#define FACT_DEFINES_H_

#ifndef _WIN32
  #define FACT_DLLEXPORT
#else
  #ifdef FACT_LIB_EXPORT
    #define FACT_DLLEXPORT __declspec(dllexport)
	#pragma message("---FACT exporting")
  #else
    #define FACT_DLLEXPORT __declspec(dllimport)
	#pragma message("---FACT importing")
  #endif
  
#endif
  
#endif
