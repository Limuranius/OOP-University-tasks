cmake_minimum_required(VERSION 3.20)
project(Sem2)
set(CMAKE_CXX_STANDARD 14)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)
set(MODULES_INCLUDE ${MODULES_DIR}/include)
set(MODULES_SRC ${MODULES_DIR}/src)
set(MODULES_ENTRIES ${MODULES_DIR}/entry)

include_directories(${MODULES_INCLUDE})

add_library(logger ${MODULES_SRC}/logger.cpp)

add_executable(log ${MODULES_ENTRIES}/logger.cpp)
target_link_libraries(log logger)


