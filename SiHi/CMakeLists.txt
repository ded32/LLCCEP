cmake_minimum_required(VERSION 2.6)
project(SiHiCompiler)

set(CMAKE_CXX_FLAGS "-std=gnu++11")
set(DEBUG true CACHE BOOL "Do you want to build project for debug?")
include_directories("${CMAKE_SOURCE_DIR}/../include/")

if(DEBUG)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -funroll-loops -flto -march=native")
endif()

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../lib/STDExtras.cpp")

find_package(bison)
find_package(flex)

bison_target(SiHiParser "${CMAKE_SOURCE_DIR}/SiHi.ypp" "${CMAKE_SOURCE_DIR}/SiHiParser.cpp")
flex_target(SiHiLexer "${CMAKE_SOURCE_DIR}/SiHi.lpp" "${CMAKE_SOURCE_DIR}/SiHiLexer.cpp")
add_flex_bison_dependency(SiHiLexer SiHiParser)

add_library(SiHiParserLib "${BISON_SiHiParser_OUTPUT_SOURCE}")
target_link_libraries(SiHiParserLib STDExtras)

add_executable(SiHiCompiler "${FLEX_SiHiLexer_OUTPUTS}")
target_link_libraries(SiHiCompiler SiHiParserLib STDExtras)
