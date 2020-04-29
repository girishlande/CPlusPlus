cmake_minimum_required(VERSION 3.0)
project(LoggingTest VERSION 1.0.4 LANGUAGES CXX)

# no need to set c++11 flag for VS2013 and greater
SET( LIB_INSTALL_PATH "D:/Girish/lib/")
SET( RUNTIME_INSTALL_PATH "C:/Girish/")

find_library(LOGGER_LIBRARY logger HINTS ${LIB_INSTALL_PATH} REQUIRED)

#overrides above to use local logger
set(LOGGER_LIBRARY "logger")

include_directories (${PROJECT_BINARY_DIR})

add_subdirectory(src)
