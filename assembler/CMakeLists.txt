cmake_minimum_required(VERSION 2.6)
project(LLCCEP_assembler)

set(BUILD_MODE "Debug" CACHE STRING "Do you want to build assembler for debug")
set(CMAKE_CXX_FLAGS "-std=gnu++11")
	
if(BUILD_MODE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
elseif(BUILD_MODE STREQUAL "Release")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -flto -funroll-loops -march=native")
else()	
	message(SEND_ERROR "BUILD_MODE is not 'Debug' or 'Release'.")
endif()

include_directories("${CMAKE_SOURCE_DIR}/../include/")
include_directories("${CMAKE_SOURCE_DIR}/include/")

find_package(bison)
find_package(flex)

bison_target(assemblyParser "${CMAKE_SOURCE_DIR}/assembly.y" "${CMAKE_SOURCE_DIR}/assemblyParser.cpp")
flex_target(assemblyScanner "${CMAKE_SOURCE_DIR}/assembly.l" "${CMAKE_SOURCE_DIR}/assemblyScanner.cpp")
add_flex_bison_dependency(SiHiScanner SiHiParser)

add_library(assemblyParserLib "${BISON_assemblyParser_OUTPUT_SOURCE}")
add_library(assemblyScannerLib "${FLEX_assemblyScanner_OUTPUTS}")
add_library(commandLine "${CMAKE_SOURCE_DIR}/../lib/command-line.cpp")
add_library()

add_executable(LLCCEP_assembler "${CMAKE_SOURCE_DIR}/main.cpp")
target_link_libraries(LLCCEP_assembler lexer analyzer linker codegen 
	              commandLine compiler STDExtras)
