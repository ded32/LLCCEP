cmake_minimum_required(VERSION 2.6)
project(codegen)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

add_library(lexer ../lexer/lexer.cpp)
add_library(analysis ../analysis/analysis.cpp)
add_library(code codegen.cpp)

add_executable(codegen test.cpp)
target_link_libraries(codegen lexer analysis code)
