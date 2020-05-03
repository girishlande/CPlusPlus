cmake_minimum_required(VERSION 3.0)

project(facttest)

# configure the flags and paths
set(FACTLIB_DEV_ROOT "C:/Girish-dev/")
set(FACTLIB_INSTALL_INC "${FACTLIB_DEV_ROOT}/include/factlib/")
set(FACTLIB_INSTALL_LIB "${FACTLIB_DEV_ROOT}/lib/fact/")

SET( LIB_INSTALL_PATH "C:/Girish-dev/lib/factlib/")
SET( RUNTIME_INSTALL_PATH "C:/Girish/")

find_library(FACTLIB_LIBRARY 
			NAMES factlib 
			HINTS ${LIB_INSTALL_PATH} REQUIRED)

#overrides above to use local logger
set(FACTLIB_LIBRARY "factlib")

include_directories(${FACTLIB_INSTALL_INC})
add_executable(main main.cpp)
target_link_libraries(main factlib)

