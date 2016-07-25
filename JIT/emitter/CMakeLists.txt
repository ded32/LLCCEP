cmake_minimum_required(VERSION 2.6)
project(emitter_test)

include_directories(../../include/)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_library(emitter ./emitter.cpp)
add_executable(emitter_test ./test.cpp)

target_link_libraries(emitter_test emitter)
