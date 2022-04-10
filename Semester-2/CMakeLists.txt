cmake_minimum_required(VERSION 3.20)
project(Sem2)
set(CMAKE_CXX_STANDARD 14)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)
set(MODULES_INCLUDE ${MODULES_DIR}/include)
set(MODULES_SRC ${MODULES_DIR}/src)
set(MODULES_ENTRIES ${MODULES_DIR}/entry)
set(TESTS_DIR ${MODULES_DIR}/tests)
set(GOOGLE_TEST_DIR ${TESTS_DIR}/googletest)

include_directories(${MODULES_INCLUDE})

# Logger
add_library(loggerLib ${MODULES_SRC}/logger.cpp)
add_executable(logger ${MODULES_ENTRIES}/logger-main.cpp)
target_link_libraries(logger loggerLib)

# Big Integer
add_library(bigIntLib ${MODULES_SRC}/big-integer.cpp)
target_link_libraries(bigIntLib loggerLib)
add_executable(bigInt ${MODULES_ENTRIES}/big-integer-main.cpp)
target_link_libraries(bigInt bigIntLib)

# CSV Parser
add_library(CSVParserLib ${MODULES_SRC}/csv-parser.cpp)
target_link_libraries(CSVParserLib loggerLib)
add_executable(CSVParser ${MODULES_ENTRIES}/csv-parser-main.cpp)
target_link_libraries(CSVParser CSVParserLib)

# Tests
add_subdirectory(${GOOGLE_TEST_DIR})
add_executable(bigIntTest ${TESTS_DIR}/big-integer-tests.cpp)
target_link_libraries(bigIntTest bigIntLib gtest gtest_main)
add_executable(CSVParserTest ${TESTS_DIR}/csv-parser-tests.cpp)
target_link_libraries(CSVParserTest CSVParserLib gtest gtest_main)