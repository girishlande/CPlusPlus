cmake_minimum_required(VERSION 3.10)

project(ImageProcessingPrograms)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")

include_directories(${CMAKE_SOURCE_DIR}/include )


add_executable(1copyimage 1copyimage.cpp)
add_executable(2ChangeBrightness 2ChangeBrightness.cpp src/ImageProcessing.cpp)


