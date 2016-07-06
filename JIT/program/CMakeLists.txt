cmake_minimum_required(VERSION 2.6)
project(program_unit_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(emitter "${CMAKE_SOURCE_DIR}/../emitter/emitter.cpp")
add_library(startup "${CMAKE_SOURCE_DIR}/../startup/startup.cpp")
add_library(program "${CMAKE_SOURCE_DIR}/program.cpp")
add_library(stack_protector "${CMAKE_SOURCE_DIR}/../stack-protector/stack-protector.c")

add_executable(program_unit_test "${CMAKE_SOURCE_DIR}/test.cpp")

target_link_libraries(program emitter)
target_link_libraries(program_unit_test emitter startup program stack_protector)
