cmake_minimum_required(VERSION 2.6)
project(opcodes_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

add_library(opcodes opcodes.cpp)
add_executable(opcodes_test test.cpp)

target_link_libraries(opcodes_test opcodes)
