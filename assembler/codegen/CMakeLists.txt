cmake_minimum_required(VERSION 2.6)
project(codeGeneratorUnitTest)

set(CMAKE_CXX_FLAGS "-g -O0 -std=gnu++11")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(analyzer "${CMAKE_SOURCE_DIR}/../analyzer/analyzer.cpp")
add_library(codegen "${CMAKE_SOURCE_DIR}/codegen.cpp")
add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
target_link_libraries(lexer STDExtras)
target_link_libraries(analyzer STDExtras lexer)
target_link_libraries(codegen lexer analyzer STDExtras)

add_executable(codeGeneratorUnitTest "${CMAKE_SOURCE_DIR}/codegenUnitTest.cpp")
target_link_libraries(codeGeneratorUnitTest lexer analyzer codegen STDExtras)
