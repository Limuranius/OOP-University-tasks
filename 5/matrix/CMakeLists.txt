add_library(matrix SHARED src/matrix.cpp)

include_directories(include)

add_library(print SHARED
        src/print_ostream.cpp
        src/print_${outputMode}.cpp)