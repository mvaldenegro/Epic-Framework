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

file(GLOB epicUtilSources "source/epic.util/*/*.cpp")
add_library(epic.util SHARED ${epicUtilSources})

file(GLOB epicImageSources "source/epic.image/*.cpp")
add_library(epic.image SHARED ${epicImageSources})

file(GLOB epicImageProcessingSources "source/epic.image/processing/*.cpp")
add_library(epic.image.processing SHARED ${epicImageProcessingSources})

file(GLOB epicOpenCLSources "source/epic.opencl/*.cpp")
add_library(epic.opencl SHARED ${epicOpenCLSources})

file(GLOB epicOpenGLSources "source/epic.opengl/*.cpp")
add_library(epic.opengl SHARED ${epicOpenGLSources})

compile_tests("test/epic.util.logging/*.cpp" "epic.core;epic.util")
compile_tests("test/epic.math/*.cpp" epic.core)
compile_tests("test/epic.core/*.cpp" epic.core)
compile_tests("test/epic.image/*.cpp" "epic.core;epic.image;epic.image.processing")
compile_tests("test/epic.opencl/*.cpp" "epic.core;epic.opencl;OpenCL")