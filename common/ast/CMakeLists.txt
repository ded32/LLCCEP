cmake_minimum_required(VERSION 2.6)
project(astUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")
include_directories("${CMAKE_SOURCE_DIR}/../../third-party/")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
add_library(DotViz "${CMAKE_SOURCE_DIR}/../../third-party/DotViz/DotViz++.cpp")

add_executable(astUnitTest "${CMAKE_SOURCE_DIR}/astUnitTest.cpp")
target_link_libraries(astUnitTest DotViz STDExtras)
