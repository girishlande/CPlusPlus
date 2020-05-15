cmake_minimum_required(VERSION 3.10)

project(ImageProcessingPrograms)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")

include_directories(${CMAKE_SOURCE_DIR}/include )


add_executable(1Convolution 1Convolution.cpp src/ImageProcessing.cpp)
add_executable(2DetectLine 2DetectLine.cpp src/ImageProcessing.cpp)
add_executable(3Convolve 3Convolve.cpp src/ImageProcessing.cpp)
add_executable(4laplace 4laplace.cpp src/ImageProcessing.cpp)
add_executable(5Kirshach 5Kirshach.cpp src/ImageProcessing.cpp)
add_executable(6Robinson 6Robinson.cpp src/ImageProcessing.cpp)
