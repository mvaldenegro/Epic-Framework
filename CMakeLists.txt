cmake_minimum_required (VERSION 2.6)

macro(compile_tests sources libraries)
	file(GLOB srcs ${sources})
	foreach(test ${srcs})
		get_filename_component(testName ${test} NAME_WE)
		add_executable(${testName} ${test})
		target_link_libraries(${testName} ${libraries})		
	endforeach(test)
endmacro(compile_tests sources)

set(CMAKE_CXX_FLAGS "-Wall -g3 -pedantic -Wno-long-long -std=c++0x")

include_directories(source)

file(GLOB epicCoreSources "source/epic.core/*.cpp")
add_library(epic.core SHARED ${epicCoreSources})

file(GLOB epicImageSources "source/epic.image/*.cpp")
add_library(epic.image SHARED ${epicImageSources})

file(GLOB epicOpenCLSources "source/epic.opencl/*.cpp")
add_library(epic.opencl SHARED ${epicOpenCLSources})

file(GLOB epicOpenGLSources "source/epic.opengl/*.cpp")
add_library(epic.opengl SHARED ${epicOpenGLSources})

compile_tests("source/epic.math/tests/*.cpp" epic.core)
compile_tests("source/epic.core/tests/*.cpp" epic.core)
compile_tests("source/epic.image/tests/*.cpp" "epic.core;epic.image")
compile_tests("source/epic.opencl/tests/*.cpp" "epic.core;epic.opencl;OpenCL")