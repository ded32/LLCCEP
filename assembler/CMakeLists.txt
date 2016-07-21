cmake_minimum_required(VERSION 2.6)
project(assembler)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11")

include_directories("${CMAKE_SOURCE_DIR}/../include/")

add_library(lexer "${CMAKE_SOURCE_DIR}/lexer/lexer.cpp")
add_library(analysis "${CMAKE_SOURCE_DIR}/analysis/analysis.cpp")
add_library(codegen "${CMAKE_SOURCE_DIR}/codegen/codegen.cpp")
add_library(compiler "${CMAKE_SOURCE_DIR}/compiler/compiler.cpp")
add_library(linker "${CMAKE_SOURCE_DIR}/linker/linker.cpp")
add_library(STD_EXT "${CMAKE_SOURCE_DIR}/../lib/STDExtras.cpp")

target_link_libraries(lexer STD_EXT)
target_link_libraries(analysis STD_EXT)
target_link_libraries(linker STD_EXT)
target_link_libraries(codegen STD_EXT linker lexer analysis)
target_link_libraries(compiler lexer analysis codegen linker)

add_executable(assembler "${CMAKE_SOURCE_DIR}/main.cpp")
target_link_libraries(assembler lexer analysis linker codegen compiler STD_EXT)
