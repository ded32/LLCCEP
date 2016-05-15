cmake_minimum_required(VERSION 2.6)
project(ast_unit_test)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -O0")

include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(ast ast.cpp)

add_executable(ast_unit_test test.cpp)
target_link_libraries(ast "${CMAKE_SOURCE_DIR}/../../third-party/libDotViz++.a")
target_link_libraries(ast_unit_test ast "${CMAKE_SOURCE_DIR}/../../third-party/libDotViz++.a")
