#ifndef OOP_MATRIX_H
#define OOP_MATRIX_H

#include <vector>

class Matrix {
public:
    int size;
    int **matr;

    explicit Matrix(int size);

    ~Matrix();

    void setValuesWithConsole();

    void setValuesWithVector(const std::vector<int>& vect) const;

    int min();

    int countEvenValues();

    int sumOfPositiveValues() const;

    Matrix operator*(const Matrix &other) const;

    Matrix operator-(const Matrix &other) const;

    Matrix transpose() const;
};

#endif //OOP_MATRIX_H
