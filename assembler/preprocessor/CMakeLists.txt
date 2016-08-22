cmake_minimum_required(VERSION 2.6)
project(preprocessorUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(preprocessor "${CMAKE_SOURCE_DIR}/preprocessor.cpp")
target_link_libraries(lexer STDExtras)
target_link_libraries(preprocessor lexer)

add_executable(preprocessorUnitTest "${CMAKE_SOURCE_DIR}/preprocessorUnitTest.cpp")
target_link_libraries(preprocessorUnitTest preprocessor lexer)
