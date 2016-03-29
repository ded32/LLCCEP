cmake_minimum_required(VERSION 2.6)
project(asm_lexer)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

add_library(lexer lexer.cpp)
add_executable(asm_lexer test.cpp)
target_link_libraries(asm_lexer lexer)
