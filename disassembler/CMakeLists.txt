cmake_minimum_required(VERSION 2.6)
project(disassembler)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11")

add_library(reader reader/reader.cpp)
add_executable(disassembler main.cpp)
target_link_libraries(disassembler reader)
