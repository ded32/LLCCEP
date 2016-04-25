cmake_minimum_required(VERSION 2.6)
project(inst_test)

add_library(instruction ./instruction.cpp)
add_executable(inst_test test.cpp)
target_link_libraries(inst_test instruction)
