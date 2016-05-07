cmake_minimum_required(VERSION 2.6)
project(program_unit_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")
include_directories(../../include/)

add_library(emitter ../emitter/emitter.cpp)
add_library(startup ../startup/startup.cpp)
add_library(program program.cpp)

add_executable(program_unit_test test.cpp)

target_link_libraries(program emitter)
target_link_libraries(program_unit_test emitter startup program)
