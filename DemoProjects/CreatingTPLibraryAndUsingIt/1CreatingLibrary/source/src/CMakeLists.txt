set (
  SOURCE_FILES
  fact/fact.cpp
  )

add_library (
  FACTLIB SHARED
  ${SOURCE_FILES}
  )
  
target_compile_features (
  FACTLIB
  PRIVATE
    cxx_std_11
  )

target_compile_definitions (
  FACTLIB
  PRIVATE
    # make sure we export
    FACTLIB_LIB_EXPORT=1
)

# configure the directories
target_include_directories(
  FACTLIB
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:${FACTLIB_INSTALL_INCLUDE_DIR}>
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

SET(FACTLIB_PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/inc/fact.h
    ${CMAKE_SOURCE_DIR}/inc/fact_defines.h
    )

set_target_properties( FACTLIB
  PROPERTIES PUBLIC_HEADER "${FACTLIB_PUBLIC_HEADERS}")
  

install (TARGETS FACTLIB 
         EXPORT  FACTLIBTargets
         ARCHIVE
           DESTINATION ${FACTLIB_INSTALL_LIBRARY_DIR}
         LIBRARY
           DESTINATION ${FACTLIB_INSTALL_LIBRARY_DIR}
         RUNTIME
           DESTINATION ${FACTLIB_INSTALL_RUNTIME_DIR}
         PUBLIC_HEADER
           DESTINATION ${FACTLIB_INSTALL_INCLUDE_DIR}
        )
