cmake_minimum_required(VERSION 3.10)

project(ImageProcessingPrograms)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")

include_directories(${CMAKE_SOURCE_DIR}/include )


add_executable(1CopyImage 1CopyImage.cpp)
add_executable(2ChangeBrightness 2ChangeBrightness.cpp src/ImageProcessing.cpp)
add_executable(3ComputeHistogram 3ComputeHistogram.cpp src/ImageProcessing.cpp)
add_executable(4EqualizaHistogram 4EqualizaHistogram.cpp src/ImageProcessing.cpp)
add_executable(5ImageRotation 5ImageRotation.cpp)
add_executable(6ImageNegative 6ImageNegative.cpp src/ImageProcessing.cpp)
add_executable(7BlueImage 7BlueImage.cpp)


