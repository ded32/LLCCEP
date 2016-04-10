cmake_minimum_required(VERSION 2.6)
project(executor)

include(FindPkgConfig)
pkg_search_module(SDL2 required sdl2)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")
include_directories(${SDL2_INCLUDE_DIRS})

add_library(loader loader/loader.cpp)
add_library(window window/window.cpp)
add_library(emulation emulation/emulation.cpp)

add_executable(executor main.cpp)
target_link_libraries(window ${SDL2_LIBRARIES})
target_link_libraries(emulation window)
target_link_libraries(executor loader window emulation)
