cmake_minimum_required(VERSION 2.6)
project(linker_unit_test)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")

include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(linker "${CMAKE_SOURCE_DIR}/../linker/linker.cpp")
add_library(STD_EXT "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")

target_link_libraries(lexer STD_EXT)
target_link_libraries(linker STD_EXT)

add_executable(linker_unit_test "${CMAKE_SOURCE_DIR}/test.cpp")
target_link_libraries(linker_unit_test lexer linker STD_EXT)
