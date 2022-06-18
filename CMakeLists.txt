cmake_minimum_required(VERSION 3.10.0)

project(15Puzzle)
set(SFML_STATIC_LIBRARIES TRUE)
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
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})