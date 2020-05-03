cmake_minimum_required (VERSION 3.9)
project (FactProject VERSION 1.1.0 LANGUAGES CXX)

if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  MESSAGE(
    FATAL_ERROR
    "A non-64-bit compiler was detected.\n
     Girish projects should target a 64-bit architecture.")
endif ()

  set(FACTLIB_INSTALL_PREFIX "C:/")
  set(FACTLIB_INSTALL_SUFFIX "Girish")
  set(FACTLIB_INSTALL_RUNTIME_DIR_INTERNAL "${FACTLIB_INSTALL_SUFFIX}")
  set(FACTLIB_INSTALL_INCLUDE_DIR_INTERNAL
    "${FACTLIB_INSTALL_SUFFIX}-dev/include/${PROJECT_NAME}")
  set(FACTLIB_INSTALL_LIBRARY_DIR_INTERNAL
    "${FACTLIB_INSTALL_SUFFIX}-dev/lib/${PROJECT_NAME}")
  set(FACTLIB_INSTALL_CMAKE_DIR_INTERNAL
    "${FACTLIB_INSTALL_SUFFIX}-dev/cmake")

set (CMAKE_INSTALL_PREFIX ${FACTLIB_INSTALL_PREFIX})

## configure the install paths
set (FACTLIB_INSTALL_RUNTIME_DIR ${FACTLIB_INSTALL_RUNTIME_DIR_INTERNAL}
  CACHE PATH "Installation directory name for executables")
set (FACTLIB_INSTALL_INCLUDE_DIR ${FACTLIB_INSTALL_INCLUDE_DIR_INTERNAL}
  CACHE PATH "Installation directory name for development headers")
set (FACTLIB_INSTALL_LIBRARY_DIR ${FACTLIB_INSTALL_LIBRARY_DIR_INTERNAL}
  CACHE PATH "Installation directory name for libraries")
set (FACTLIB_INSTALL_CMAKE_DIR ${FACTLIB_INSTALL_CMAKE_DIR_INTERNAL}
  CACHE PATH "Installation directory name for cmake config files")

# provide the version file
configure_file ("src/version.h.in" "version.h")
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory (src)

# Export for the build tree
export(TARGETS FACTLIB FILE ${PROJECT_BINARY_DIR}/FACTLIBTargets.cmake)

# include the cmake package config helper
include (CMakePackageConfigHelpers)

set (INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR})

# make config version file
write_basic_package_version_file (
  "${PROJECT_BINARY_DIR}/FACTLIBConfigVersion.cmake"
  COMPATIBILITY AnyNewerVersion )

# set name for directories so that we can pass them to the configure command
set (INSTALL_INCLUDE_DIR "${FACTLIB_INSTALL_INCLUDE_DIR}")
set (INSTALL_LIBRARY_DIR "${FACTLIB_INSTALL_LIBRARY_DIR}")
set (INSTALL_RUNTIME_DIR "${FACTLIB_INSTALL_RUNTIME_DIR}")

# configure the package *Config.cmake file
configure_package_config_file (
  FACTLIBConfig.cmake.in
  "${PROJECT_BINARY_DIR}/FACTLIBConfig.cmake"
  INSTALL_DESTINATION
    ${FACTLIB_INSTALL_CMAKE_DIR}
  PATH_VARS
    INSTALL_INCLUDE_DIR
    INSTALL_LIBRARY_DIR
    INSTALL_RUNTIME_DIR
  )

# install the configs
install (
  FILES
    "${PROJECT_BINARY_DIR}/FACTLIBConfig.cmake"
    "${PROJECT_BINARY_DIR}/FACTLIBConfigVersion.cmake"
  DESTINATION
    "${FACTLIB_INSTALL_CMAKE_DIR}" COMPONENT dev)

# install the exported target file
install (
  EXPORT
    FACTLIBTargets
  DESTINATION
    "${FACTLIB_INSTALL_CMAKE_DIR}" COMPONENT dev
  )
