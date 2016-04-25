cmake_minimum_required(VERSION 2.6)
project(instruction_test)

add_library(instruction ./instruction.cpp)
add_executable(instruction_test ./test.cpp)

target_link_libraries(instruction_test instruction)
