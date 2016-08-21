cmake_minimum_required(VERSION 2.6)
project(lexerUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
add_library(lexer "${CMAKE_SOURCE_DIR}/lexer.cpp")
target_link_libraries(lexer STDExtras)

add_executable(lexerUnitTest "${CMAKE_SOURCE_DIR}/lexerUnitTest.cpp")
target_link_libraries(lexerUnitTest lexer)
