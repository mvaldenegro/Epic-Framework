cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "-Wall -g3")

project(epic.core)

add_library(epic.core source/epic.core/String.cpp)

add_executable(pointerTest source/epic.core/tests/PointerTest.cpp)
target_link_libraries(pointerTest epic.core)
include_directories(pointerTest source)
