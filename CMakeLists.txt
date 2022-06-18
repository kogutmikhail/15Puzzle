cmake_minimum_required(VERSION 3.10.0)

project(15Puzzle)

find_package(SFML REQUIRED network audio graphics window system)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(cmake/StandardProjectSettings.cmake)
# Link this 'library' to set the c++ standard / compile-time options requested
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_20)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(default)
add_subdirectory(external/doctest)
add_subdirectory(game)
enable_testing()
set(DEB_DIR "../build/game/Debug")
set(REL_DIR "../build/game/Release")
file(COPY resources DESTINATION ${DEB_DIR})
file(COPY resources DESTINATION ${REL_DIR})
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})