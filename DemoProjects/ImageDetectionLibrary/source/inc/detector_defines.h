#ifndef DETECTOR_DEFINES_H_
#define DETECTOR_DEFINES_H_

#ifndef _WIN32
  #define DETECTOR_DLLEXPORT
#else
  #ifdef DETECTOR_LIB_EXPORT
    #define DETECTOR_DLLEXPORT __declspec(dllexport)
	#pragma message("---DETECTOR exporting")
  #else
    #define DETECTOR_DLLEXPORT __declspec(dllimport)
	#pragma message("---DETECTOR importing")
  #endif
  
#endif
  
#endif
