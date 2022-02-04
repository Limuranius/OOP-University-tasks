cmake_minimum_required(VERSION 3.20)
project(PolishNotation)

add_library(cmdController mylib.cpp)
add_library(polska polska.cpp)

add_executable(main main.cpp)

target_link_libraries(main cmdController polska)