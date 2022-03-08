add_library(matrix STATIC src/matrix.cpp)

include_directories(${MATRIX_INCLUDE_DIR})

add_library(print STATIC
        src/print_ostream.cpp
        src/print_${outputMode}.cpp)