cmake_minimum_required(VERSION 2.6)
project(instruction_manager_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

add_library(instruction_manager_lib ./instruction_manager.cpp)
add_executable(instruction_manager_test ./test.cpp)

target_link_libraries(instruction_manager_test instruction_manager_lib)
