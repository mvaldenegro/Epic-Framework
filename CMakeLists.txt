cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "-Wall -g3")

include_directories(source)

add_library(epic.core source/epic.core/String.cpp)
add_executable(vector2Test test/epic.math/vector2Test.cpp)