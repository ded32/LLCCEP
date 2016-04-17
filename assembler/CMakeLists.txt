cmake_minimum_required(VERSION 2.6)
project(assembler)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11")

add_library(lexer lexer/lexer.cpp)
add_library(analysis analysis/analysis.cpp)
add_library(codegen codegen/codegen.cpp)

add_executable(assembler main.cpp)
target_link_libraries(codegen lexer analysis)
target_link_libraries(assembler lexer analysis codegen)
