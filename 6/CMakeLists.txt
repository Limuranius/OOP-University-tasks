cmake_minimum_required(VERSION 3.20)

project(Base64Project)

add_library(coder SHARED coder.cpp)

add_subdirectory(tests)

add_executable(main main.cpp)

target_link_libraries(main coder)