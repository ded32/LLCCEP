cmake_minimum_required(VERSION 2.8)
project(VM)

include(FindPkgConfig)

pkg_search_module(SDL2 required sdl2)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")

include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")
add_library(conf "${CMAKE_SOURCE_DIR}/../conf/conf.cpp")
add_library(setup "${CMAKE_SOURCE_DIR}/../setup/setup.cpp")
add_library(softcore "${CMAKE_SOURCE_DIR}/../softcore/softcore.cpp")
add_library(prog "${CMAKE_SOURCE_DIR}/../program/program.cpp")
add_library(display_driver "${CMAKE_SOURCE_DIR}/../drivers/display/display.cpp")
add_library(hdd_driver "${CMAKE_SOURCE_DIR}/../drivers/hdd/hdd.cpp")
add_library(kb_driver "${CMAKE_SOURCE_DIR}/../drivers/kb/kb.cpp")
add_library(mouse_driver "${CMAKE_SOURCE_DIR}/../drivers/mouse/mouse.cpp")
add_library(ram_driver "${CMAKE_SOURCE_DIR}/../drivers/ram/ram.cpp")
add_library(window "${CMAKE_SOURCE_DIR}/../window/window.cpp")

target_link_libraries(display_driver ${SDL2_LIBRARIES})

add_executable(VM "${CMAKE_SOURCE_DIR}/main.cpp")
target_link_libraries(VM STDExtras conf setup softcore prog
                         display_driver hdd_driver kb_driver
                         mouse_driver ram_driver window)
