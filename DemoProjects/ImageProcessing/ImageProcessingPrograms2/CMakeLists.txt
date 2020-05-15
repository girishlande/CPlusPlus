cmake_minimum_required(VERSION 3.10)

project(ImageProcessingPrograms)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")

include_directories(${CMAKE_SOURCE_DIR}/include )


add_executable(1MinimumFilter 1MinimumFilter.cpp src/ImageProcessing.cpp)
add_executable(2MedianFilter 2MedianFilter.cpp src/ImageProcessing.cpp)
add_executable(3MaximumFilter 3MaximumFilter.cpp src/ImageProcessing.cpp)
add_executable(4GaussianNoise 4GaussianNoise.cpp src/ImageProcessing.cpp)
add_executable(5SaltAndPepper 5SaltAndPepper.cpp src/ImageProcessing.cpp)
