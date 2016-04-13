cmake_minimum_required(VERSION 2.6)
project(lexer_test)

add_library(lexer lexer.cpp)
add_executable(lexer_test test.cpp)
target_link_libraries(lexer_test lexer)
