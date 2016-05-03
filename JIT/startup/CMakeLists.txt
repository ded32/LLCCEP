cmake_minimum_required(VERSION 2.6)
project(startup_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

add_library(startup startup.cpp)
add_library(emitter ../emitter/emitter.cpp)

include_directories(../../include/)

add_executable(startup_test test.cpp)
target_link_libraries(startup_test startup emitter)
