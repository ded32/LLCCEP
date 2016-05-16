cmake_minimum_required(VERSION 2.6)
project(ast_unit_test)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -O0")
set(DotViz "${CMAKE_SOURCE_DIR}/../../third-party/DotViz/libDotViz++.a")

include_directories("${CMAKE_SOURCE_DIR}/../../third-party/")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(ast "${CMAKE_SOURCE_DIR}/ast.cpp")
add_library(dump "${CMAKE_SOURCE_DIR}/dump.cpp")

add_executable(ast_unit_test "${CMAKE_SOURCE_DIR}/test.cpp")
target_link_libraries(dump "${DotViz}")
target_link_libraries(ast_unit_test ast dump "${DotViz}")
