cmake_minimum_required(VERSION 3.20)
project(Matrix)

# Режимы вывода:
#   console - консоль
#   file - файл
set(outputMode console)

add_subdirectory(matrix)
add_subdirectory(tests)

include_directories(matrix/include)
add_executable(finalResult main.cpp)

target_link_libraries(finalResult
        matrix
        print)



