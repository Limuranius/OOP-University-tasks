# Названия библиотек:
# loggerLib
# bigIntLib
# CSVParserLib
# keyValLib
# stackLib
# gtest gtest_main
# converterLib

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

# Key-Value Container
add_library(keyValLib ${MODULES_SRC}/key-value.cpp)
add_executable(keyVal ${MODULES_ENTRIES}/key-value-main.cpp)
target_link_libraries(keyVal keyValLib bigIntLib)

# Stack
add_library(stackLib ${MODULES_SRC}/stack.cpp)
target_link_libraries(stackLib loggerLib)
add_executable(stack ${MODULES_ENTRIES}/stack-main.cpp)
target_link_libraries(stack stackLib bigIntLib)

# CSV-KevVal converter
add_library(converterLib ${MODULES_SRC}/csv-keyval-converter.cpp)
target_link_libraries(converterLib keyValLib)

# Tests
add_subdirectory(${GOOGLE_TEST_DIR})

add_executable(bigIntTest ${TESTS_DIR}/big-integer-tests.cpp)
target_link_libraries(bigIntTest bigIntLib gtest gtest_main)

add_executable(CSVParserTest ${TESTS_DIR}/csv-parser-tests.cpp)
target_link_libraries(CSVParserTest CSVParserLib gtest gtest_main)

add_executable(keyValTest ${TESTS_DIR}/key-value-tests.cpp)
target_link_libraries(keyValTest keyValLib bigIntLib gtest gtest_main)

add_executable(stackTest ${TESTS_DIR}/stack-tests.cpp)
target_link_libraries(stackTest stackLib bigIntLib gtest gtest_main)