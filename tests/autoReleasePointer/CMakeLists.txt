cmake_minimum_required(VERSION 2.6)
project(autoReleasePointerUnitTest)

set(CMAKE_CXX_FLAGS "-std=gnu++11")
include_directories("${CMAKE_SOURCE_DIR}/../../include/")

add_library(STDExtras "${CMAKE_SOURCE_DIR}/../../lib/STDExtras.cpp")

add_executable(autoReleasePointerUnitTest 
               "${CMAKE_SOURCE_DIR}/autoReleasePointerUnitTest.cpp")
target_link_libraries(autoReleasePointerUnitTest STDExtras)
