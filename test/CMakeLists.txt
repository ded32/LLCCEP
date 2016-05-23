cmake_minimum_required(VERSION 2.6)
project(STDExt_test)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

include_directories("${CMAKE_SOURCE_DIR}/../include/")
add_library(STDExt "${CMAKE_SOURCE_DIR}/../lib/STDExtras.cpp")

add_executable(STDExt_test "${CMAKE_SOURCE_DIR}/STD_ext.cpp")
target_link_libraries(STDExt_test STDExt)
