cmake_minimum_required(VERSION 2.6)
project(JIT_TEST)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")
add_library(opcodes opcodes.cpp)

add_executable(JIT_TEST test.cpp)
target_link_libraries(JIT_TEST opcodes)
