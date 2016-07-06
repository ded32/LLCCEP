cmake_minimum_required(VERSION 2.8)
project(display_driver_test)

include(FindPkgConfig)

pkg_search_module(SDL2 required sdl2)

set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -O0")

add_library(display_driver "${CMAKE_SOURCE_DIR}/display.cpp")
target_link_libraries(display_driver ${SDL2_LIBRARIES})

add_executable(display_driver_test "${CMAKE_SOURCE_DIR}/test.cpp")
target_link_libraries(display_driver_test display_driver)
