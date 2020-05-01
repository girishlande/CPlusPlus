cmake_minimum_required(VERSION 3.0)
project(Phantomdetector VERSION 1.0.4 LANGUAGES CXX)

set(DETECTOR_LIBRARY "detector")

include_directories (${PROJECT_BINARY_DIR})

add_subdirectory(src)
