cmake_minimum_required(VERSION 3.20)
project(Sem2)
set(CMAKE_CXX_STANDARD 14)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)
set(TASKS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tasks)
set(MODULES_INCLUDE ${MODULES_DIR}/include)
set(MODULES_SRC ${MODULES_DIR}/src)
set(MODULES_ENTRIES ${MODULES_DIR}/entry)
set(TESTS_DIR ${MODULES_DIR}/tests)
set(GOOGLE_TEST_DIR ${TESTS_DIR}/googletest)

include_directories(${MODULES_INCLUDE})
add_subdirectory(${MODULES_DIR})
add_subdirectory(${TASKS_DIR})



