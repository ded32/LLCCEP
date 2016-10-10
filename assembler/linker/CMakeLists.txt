cmake_minimum_required(VERSION 2.6)
project(linkerUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")

include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(linker "${CMAKE_SOURCE_DIR}/linker.cpp")
add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")

target_link_libraries(lexer STDExtras)
target_link_libraries(linker STDExtras)

add_executable(linkerUnitTest "${CMAKE_SOURCE_DIR}/linkerUnitTest.cpp")
target_link_libraries(linkerUnitTest lexer linker STDExtras)
