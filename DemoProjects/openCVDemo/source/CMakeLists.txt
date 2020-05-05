cmake_minimum_required (VERSION 3.9)

project( openCVDemo )

set (CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" "D:/repos/opencv/build/install/x64/vc16/lib/")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

add_executable( ShapeDetector ShapeDetector.cpp )
target_link_libraries( ShapeDetector ${OpenCV_LIBS} )

add_executable( LiveVideoParser LiveVideoParser.cpp )
target_link_libraries( LiveVideoParser ${OpenCV_LIBS} )

