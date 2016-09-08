cmake_minimum_required(VERSION 2.6)
project(reinterpretValueUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")

add_executable(reinterpretValueUnitTest
               "${CMAKE_SOURCE_DIR}/reinterpretValueUnitTest.cpp")
target_link_libraries(reinterpretValueUnitTest STDExtras)
