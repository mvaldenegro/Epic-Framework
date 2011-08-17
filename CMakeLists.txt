cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "-Wall -g3 -pedantic -Wno-long-long -std=c++0x")

include_directories(source)

file(GLOB epicCoreSources "source/epic.core/*.cpp")
add_library(epic.core SHARED ${epicCoreSources})

add_executable(stringTest source/epic.core/tests/StringTest.cpp)
target_link_libraries(stringTest epic.core)

add_executable(arrayTest source/epic.core/tests/ArrayTest.cpp)

file(GLOB epicImageSources "source/epic.image/*.cpp")
add_library(epic.image SHARED ${epicImageSources})

add_executable(imageTest source/epic.image/tests/imageTest.cpp)
target_link_libraries(imageTest epic.image)


file(GLOB epicOpenCLSources "source/epic.bindings.opencl/*.cpp")
add_library(epic.opencl SHARED ${epicOpenCLSources})

add_executable(openclTest source/epic.bindings.opencl/tests/openclTest.cpp)
target_link_libraries(openclTest epic.core epic.opencl OpenCL)

file(GLOB epicOpenGLSources "source/epic.bindings.opengl/*.cpp")
add_library(epic.opengl SHARED ${epicOpenGLSources})


add_executable(vector2Test test/epic.math/vector2Test.cpp)

