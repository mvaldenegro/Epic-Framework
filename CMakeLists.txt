cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "-Wall -g3 -pedantic -Wno-long-long")

include_directories(source)

file(GLOB epicImageSources "source/epic.image/*.cpp")
add_library(epic.image SHARED ${epicImageSources})

file(GLOB epicCoreSources "source/epic.core/*.cpp")
add_library(epic.core SHARED ${epicCoreSources})

add_executable(vector2Test test/epic.math/vector2Test.cpp)
add_executable(arrayTest source/epic.core/tests/ArrayTest.cpp)