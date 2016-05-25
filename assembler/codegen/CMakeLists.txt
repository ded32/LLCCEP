cmake_minimum_required(VERSION 2.6)
project(codegen_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

include_directories("${CMAKE_SOURCE_DIR}/../../include/")
add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(analysis "${CMAKE_SOURCE_DIR}/../analysis/analysis.cpp")
add_library(codegen "${CMAKE_SOURCE_DIR}/codegen.cpp")
add_library(STD_EXT "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")

add_executable(codegen_test "${CMAKE_SOURCE_DIR}/test.cpp")
target_link_libraries(lexer STD_EXT)
target_link_libraries(analysis STD_EXT)
target_link_libraries(codegen analysis STD_EXT)
target_link_libraries(codegen_test lexer analysis codegen STD_EXT)
