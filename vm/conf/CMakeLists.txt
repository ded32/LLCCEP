cmake_minimum_required(VERSION 3.0)
project(vm_config_reader_test)

find_package(FLEX)
find_package(BISON)

bison_target(vm_config_parser "${CMAKE_SOURCE_DIR}/vm_conf.y" "${CMAKE_SOURCE_DIR}/parser.c")
flex_target(vm_config_lexer "${CMAKE_SOURCE_DIR}/vm_conf.l" "${CMAKE_SOURCE_DIR}/lexer.c")
add_flex_bison_dependency(vm_config_lexer vm_config_parser)

include_directories("${CMAKE_SOURCE_DIR}/../../include/")
add_library(undirected_list "${CMAKE_SOURCE_DIR}/../../lib/list.c")
add_library(section "${CMAKE_SOURCE_DIR}/section.c")

add_executable(vm_config_reader_test "${BISON_vm_config_parser_OUTPUTS}" "${FLEX_vm_config_lexer_OUTPUTS}")
target_link_libraries(vm_config_reader_test section undirected_list)
