cmake_minimum_required(VERSION 2.6)
project(SiHiCompiler)

set(CMAKE_CXX_FLAGS "-std=gnu++11")
set(BUILD_MODE "Debug" CACHE STRING "Do you want to build project for debug?")
include_directories("${CMAKE_SOURCE_DIR}/../include/")
include_directories("${CMAKE_SOURCE_DIR}/../common/")
include_directories("${CMAKE_SOURCE_DIR}/../third-party/")

if(BUILD_MODE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
elseif(BUILD_MODE STREQUAL "Release")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -funroll-loops -flto -march=native")
else()
	message(SEND_ERROR "BUILD_MODE is not \"Debug\" or \"Release\"")
endif()

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../lib/STDExtras.cpp")
add_library(DotViz "${CMAKE_SOURCE_DIR}/../third-party/DotViz/DotViz++.cpp")
add_library(lexem "${CMAKE_SOURCE_DIR}/lexem/lexem.cpp")

find_package(bison)
find_package(flex)

bison_target(SiHiParser "${CMAKE_SOURCE_DIR}/SiHi.y" "${CMAKE_SOURCE_DIR}/SiHiParser.cpp")
flex_target(SiHiScanner "${CMAKE_SOURCE_DIR}/SiHi.l" "${CMAKE_SOURCE_DIR}/SiHiScanner.cpp")
add_flex_bison_dependency(SiHiScanner SiHiParser)

set(BISON_SiHiParser_COMPILE_FLAGS "${BISON_SiHiParser_COMPILE_FLAGS} -v")

add_library(SiHiParserLib "${BISON_SiHiParser_OUTPUT_SOURCE}")
add_library(SiHiScannerLib "${FLEX_SiHiScanner_OUTPUTS}")
target_link_libraries(SiHiParserLib STDExtras DotViz)
target_link_libraries(SiHiScannerLib SiHiParserLib STDExtras DotViz)

add_executable(SiHiCompiler "${CMAKE_SOURCE_DIR}/main.cpp")
target_link_libraries(SiHiCompiler lexem SiHiScannerLib SiHiParserLib STDExtras)
