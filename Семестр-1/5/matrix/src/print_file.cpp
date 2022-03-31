#include "print_ostream.h"
#include "matrix.h"
#include <fstream>

void printMatrix(const Matrix &matrix) {
    std::ofstream file("matrix.txt");
    printMatrix(file, matrix);
    file.close();
}