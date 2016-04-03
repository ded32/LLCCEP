cmake_minimum_required(VERSION 2.6)
project(SiPyParser)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

include_directories(../../include/)

add_library(parser parser.cpp)
add_library(lexer ../lexer/lexer.cpp)
add_library(STLExtras ../../lib/STLExtras.cpp)
add_library(errors ../errors/errors.cpp)
add_library(precedence precedence.cpp)

add_executable(SiPyParser test.cpp)
target_link_libraries(lexer errors)
target_link_libraries(parser STLExtras errors precedence)
target_link_libraries(SiPyParser parser lexer STLExtras errors)
