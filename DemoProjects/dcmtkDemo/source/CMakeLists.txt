cmake_minimum_required (VERSION 3.9)
project (Dicomtest VERSION 1.1.0 LANGUAGES CXX)

find_package (DCMTK REQUIRED)

include_directories(${DCMTK_INCLUDE_DIR} )

add_executable(main main.cpp)
target_link_libraries(main ${DCMTK_LIBRARIES})

include_directories(${CMAKE_SOURCE_DIR} )

add_executable(ReadDicom ReadDicom.cpp lodepng.cpp)
target_link_libraries(ReadDicom ${DCMTK_LIBRARIES})
