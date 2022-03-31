project(Matrix)

# Режимы вывода:
#   console - консоль
#   file - файл
set(outputMode console)

add_library(matrix SHARED matrix.cpp)

add_library(print SHARED
        print_ostream.cpp
        print_${outputMode}.cpp)

add_executable(finalResult main.cpp)

target_link_libraries(finalResult
        matrix
        print)



