#include "print_ostream.h"
#include "matrix.h"
#include <iostream>

void printMatrix(const Matrix &matrix) {
    printMatrix(std::cout, matrix);
}