cmake_minimum_required(VERSION 2.6)
project(compilerUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
add_library(lexer "${CMAKE_SOURCE_DIR}/../lexer/lexer.cpp")
add_library(analyzer "${CMAKE_SOURCE_DIR}/../analyzer/analyzer.cpp")
add_library(linker "${CMAKE_SOURCE_DIR}/../linker/linker.cpp")
add_library(codegen "${CMAKE_SOURCE_DIR}/../codegen/codegen.cpp")
add_library(compiler "${CMAKE_SOURCE_DIR}/compiler.cpp")
target_link_libraries(lexer STDExtras)
target_link_libraries(analyzer lexer STDExtras)
target_link_libraries(linker STDExtras)
target_link_libraries(codegen lexer STDExtras)
target_link_libraries(compiler lexer linker codegen STDExtras)

add_executable(compilerUnitTest "${CMAKE_SOURCE_DIR}/compilerUnitTest.cpp")
target_link_libraries(compilerUnitTest lexer analyzer linker 
                      codegen compiler STDExtras)
