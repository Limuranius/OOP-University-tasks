#include "print_ostream.h"

void printMatrix(std::ostream &out, const Matrix &matrix) {
    for (int i = 0; i < matrix.size; i++) {
        for (int j = 0; j < matrix.size; j++) {
            out << matrix.matr[i][j] << " ";
        }
        out << std::endl;
    }
}