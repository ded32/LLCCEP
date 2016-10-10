cmake_minimum_required(VERSION 2.6)
project(analyzerUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(analyzer "${CMAKE_SOURCE_DIR}/analyzer.cpp")
target_link_libraries(lexer STDExtras)
target_link_libraries(analyzer lexer STDExtras)

add_executable(analyzerUnitTest "${CMAKE_SOURCE_DIR}/analyzerUnitTest.cpp")
target_link_libraries(analyzerUnitTest lexer analyzer STDExtras)
