cmake_minimum_required(VERSION 2.6)
project(asm_analysis)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

include_directories("${CMAKE_SOURCE_DIR}/../../include/")
add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(analysis "${CMAKE_SOURCE_DIR}/analysis.cpp")

add_executable(asm_analysis "${CMAKE_SOURCE_DIR}/test.cpp")
target_link_libraries(asm_analysis lexer analysis)
