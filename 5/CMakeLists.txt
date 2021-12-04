cmake_minimum_required(VERSION 3.20)
project(Matrix)

# Режимы вывода:
#   console - консоль
#   file - файл
set(outputMode console)
set(MATRIX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/matrix)
set(MATRIX_INCLUDE_DIR ${MATRIX_DIR}/include)

add_subdirectory(matrix)
add_subdirectory(tests)

include_directories(matrix/include)
add_executable(finalResult main.cpp)

target_link_libraries(finalResult
        matrix
        print)



