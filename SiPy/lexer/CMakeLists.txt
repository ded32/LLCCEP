cmake_minimum_required(VERSION 2.6)
project(SiPyLexer)

add_library(lexer lexer.cpp)
add_library(errors ../errors/errors.cpp)

add_executable(SiPyLexer test.cpp)
target_link_libraries(lexer errors)
target_link_libraries(SiPyLexer lexer errors)
