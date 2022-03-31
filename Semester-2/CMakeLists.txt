cmake_minimum_required(VERSION 3.20)
project(_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(modules/include)

add_executable(_2
        modules/include/logger.h
        modules/src/logger.cpp
        modules/main.cpp)
