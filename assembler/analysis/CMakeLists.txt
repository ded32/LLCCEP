cmake_minimum_required(VERSION 2.6)
project(asm_analysis)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

add_library(lexer ../lexer/lexer.cpp)
add_library(analysis analysis.cpp)

add_executable(asm_analysis test.cpp)
target_link_libraries(asm_analysis lexer analysis)
