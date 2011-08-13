cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "-Wall -g3 -pedantic -Wno-long-long")

include_directories(source)

file(GLOB epicCoreSources "source/epic.core/*.cpp")
add_library(epic.core SHARED ${epicCoreSources})

file(GLOB epicImageSources "source/epic.image/*.cpp")
add_library(epic.image SHARED ${epicImageSources})

file(GLOB epicOpenCLSources "source/epic.bindings.opencl/*.cpp")
add_library(epic.opencl SHARED ${epicOpenCLSources})

add_executable(vector2Test test/epic.math/vector2Test.cpp)
add_executable(stringTest source/epic.core/tests/StringTest.cpp)
target_link_libraries(stringTest epic.core)

add_executable(arrayTest source/epic.core/tests/ArrayTest.cpp)

add_executable(openclTest source/epic.bindings.opencl/tests/openclTest.cpp)
target_link_libraries(openclTest epic.core epic.opencl OpenCL)