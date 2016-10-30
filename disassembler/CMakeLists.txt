cmake_minimum_required(VERSION 2.6)
project(LLCCEP_disassembler)

set(BUILD_MODE "Debug" CACHE STRING "Do you want build disassembler for debug")
set(CMAKE_CXX_FLAGS "-std=gnu++11")

if(BUILD_MODE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Debug/lib")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Debug/lib")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Debug/bin")
elseif(BUILD_MODE STREQUAL "Release")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -flto -funroll-loops -march=native")
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Release/lib")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Release/lib")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Release/bin")
else()	
	message(SEND_ERROR "BUILD_MODE is not 'Debug' or 'Release'.")
endif()

include_directories("${CMAKE_SOURCE_DIR}/../include/")

add_library(disassembler "${CMAKE_SOURCE_DIR}/disassembler/disassembler.cpp")
add_library(codeReader "${CMAKE_SOURCE_DIR}/../lib/codeReader.cpp")
add_library(commandLine "${CMAKE_SOURCE_DIR}/../lib/command-line.cpp")
add_library(defInst "${CMAKE_SOURCE_DIR}/../common/def/def_inst.cpp")
add_library(defCond "${CMAKE_SOURCE_DIR}/../common/def/def_cond.cpp")
add_library(STDExtras "${CMAKE_SOURCE_DIR}/../lib/STDExtras.cpp")

add_executable(LLCCEP_disassembler "${CMAKE_SOURCE_DIR}/main.cpp")
target_link_libraries(LLCCEP_disassembler disassembler commandLine defInst
                      defCond STDExtras codeReader)
