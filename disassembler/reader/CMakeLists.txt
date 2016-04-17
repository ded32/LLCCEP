cmake_minimum_required(VERSION 2.6)
project(reader_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")
add_library(reader reader.cpp)

add_executable(reader_test test.cpp)
target_link_libraries(reader_test reader)
