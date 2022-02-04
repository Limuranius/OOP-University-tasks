cmake_minimum_required(VERSION 3.20)
project(PolishNotation)

set(RPN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CONSOLE_MANAGER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_library(cmdController mylib.cpp)
add_library(polska polska.cpp)

add_subdirectory(tests)

add_executable(main main.cpp)

target_link_libraries(main cmdController polska)