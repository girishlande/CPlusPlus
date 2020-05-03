cmake_minimum_required(VERSION 3.0)

project(factlib)

# configure the flags and paths
set(FACTLIB_RT_ROOT  "C:/Girish/")
set(FACTLIB_DEV_ROOT "C:/Girish-dev/")
set(FACTLIB_INSTALL_INC "${FACTLIB_DEV_ROOT}/include/factlib/")
set(FACTLIB_INSTALL_LIB "${FACTLIB_DEV_ROOT}/lib/factlib/")

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_library(factlib SHARED src/fact/fact.cpp)
target_compile_definitions(factlib PRIVATE FACT_LIB_EXPORT=1)

add_executable(main src/main.cpp)
target_link_libraries(main factlib)


# add the install targets
SET(FACTLIB_PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/inc/fact.h
	${CMAKE_SOURCE_DIR}/inc/fact_defines.h
    )

set_target_properties(factlib
            PROPERTIES PUBLIC_HEADER "${FACTLIB_PUBLIC_HEADERS}")

install(TARGETS factlib
        ARCHIVE DESTINATION ${FACTLIB_INSTALL_LIB}
        LIBRARY DESTINATION ${FACTLIB_INSTALL_LIB}
        RUNTIME DESTINATION ${FACTLIB_RT_ROOT}
        PUBLIC_HEADER DESTINATION ${FACTLIB_INSTALL_INC}
        )