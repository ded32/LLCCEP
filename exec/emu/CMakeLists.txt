cmake_minimum_required(VERSION 2.8)
project(emu)

include(FindPkgConfig)

pkg_search_module(SDL2 required sdl2)

file(WRITE "${CMAKE_SOURCE_DIR}/../selection/selection.hpp" 
	"#ifndef SELECTION_HPP\n"
	"#define SELECTION_HPP\n"
	"\n"
	"#define VM 0\n"
	"\n"
	"#endif // SELECTION_HPP\n")

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")
set(CMAKE_C_FLAGS "-std=gnu11 -g -O0")

include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
add_library(setup "${CMAKE_SOURCE_DIR}/../setup/setup.cpp")
add_library(softcore "${CMAKE_SOURCE_DIR}/../softcore/softcore.cpp")
add_library(prog "${CMAKE_SOURCE_DIR}/../program/program.cpp")
add_library(ram_driver "${CMAKE_SOURCE_DIR}/../drivers/ram/ram.cpp")
add_library(window "${CMAKE_SOURCE_DIR}/../window/window.cpp")

target_link_libraries(window ${SDL2_LIBRARIES})

add_executable(emu "${CMAKE_SOURCE_DIR}/main.cpp")
target_link_libraries(emu STDExtras setup softcore prog ram_driver window)

