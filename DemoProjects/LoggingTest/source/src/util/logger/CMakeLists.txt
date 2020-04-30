project(logger)

include_directories(${CMAKE_SOURCE_DIR}/inc)

# the files needed for lib_prep
set(LOGGER_SRC
    Logger.cpp
    LoggerStdOut.cpp
    LoggerToFile.cpp
      )
 
add_library(logger SHARED
            ${LOGGER_SRC}
	    )

# if on windows copy inc, lib, and binaries to expected dirs
if (WIN32)

   # only copy needed incs
   SET(INCLUDES_TO_COPY 
       Logger.h
       LoggerNull.h
       LoggerStdOut.h
       LoggerToFile.h
      )

   # post build hooks to install inc, libs, binaries
   foreach(inc_to_copy ${INCLUDES_TO_COPY})
   add_custom_command(TARGET logger POST_BUILD
                      COMMAND ${CMAKE_COMMAND} -E copy_if_different
		      ${CMAKE_SOURCE_DIR}/inc/${inc_to_copy}
		      ${LOGGER_INSTALL_INC}/${inc_to_copy})
		 
   endforeach(inc_to_copy)
	
   SET(LIBS_TO_COPY logger.lib
                    logger.dll)
    
   foreach(lib_to_copy ${LIBS_TO_COPY})
       add_custom_command(TARGET logger POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
  	        ${CMAKE_BINARY_DIR}/src/\$\(Configuration\)/${lib_to_copy}
		${LOGGER_INSTALL_LIB}/${lib_to_copy})
					   
   endforeach(lib_to_copy)
	
endif (WIN32)		 
