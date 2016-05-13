cmake_minimum_required(VERSION 2.6)
project(SiHi_parser_unit_test)

find_package(BISON)
find_package(FLEX)

bison_target(SiHi_parser SiHi.l ${CMAKE_CURRENT_BINARY_DIR}/SiHi_parser.h)
flex_target(SiHi_lexer SiHi.l ${CMAKE_CURRENT_BINARY_DIR}/SiHi_lexer.c)

add_flex_bison_dependency(SiHi_lexer SiHi_parser)

add_executable(SiHi_parser_unit_test ./CMakeFiles/SiHi_parser_unit_test/SiHi.lex.c)
