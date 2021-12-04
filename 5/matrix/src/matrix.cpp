#include <iostream>
#include "matrix.h"


Matrix::Matrix(int size) {
    if (size <= 0) {
        throw std::runtime_error("Error: Matrix size <= 0!");
    }
    this->size = size;
    this->matr = new int *[size];
    for (int i = 0; i < size; i++) {
        this->matr[i] = new int[size];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < this->size; i++) {
        delete this->matr[i];
    }
}

void Matrix::setValuesWithConsole() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            std::cin >> this->matr[i][j];
        }
    }
}

void Matrix::setValuesWithVector(const std::vector<int>& vect) const {
    if (vect.size() != this->size * this->size) {
        throw std::runtime_error("Error: Too many / not enough elements!");
    }
    for (int i = 0; i < vect.size(); i++) {
        this->matr[i / this->size][i % this->size] = vect[i];
    }
}

int Matrix::min() {
    int min = this->matr[0][0];
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            min = (this->matr[i][j] < min) ? this->matr[i][j] : min;
        }
    }
    return min;
}

int Matrix::countEvenValues() {
    int count = 0;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            count += this->matr[i][j] % 2 == 0;
        }
    }
    return count;
}

int Matrix::sumOfPositiveValues() const {
    int sum = 0;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            sum += (this->matr[i][j] >= 0) * this->matr[i][j];
        }
    }
    return sum;
}

Matrix Matrix::operator*(const Matrix &other) const {
    if (this->size != other.size) {
        throw std::runtime_error("Error: Matrices' sizes differ!");
    }
    Matrix res(this->size);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            int sum = 0;
            for (int z = 0; z < this->size; z++) {
                sum += this->matr[i][z] * other.matr[z][j];
            }
            res.matr[i][j] = sum;
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (this->size != other.size) {
        throw std::runtime_error("Error: Matrices' sizes differ!");
    }
    Matrix res(this->size);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            res.matr[i][j] = this->matr[i][j] - other.matr[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (this->size != other.size) {
        throw std::runtime_error("Error: Matrices' sizes differ!");
    }
    Matrix res(this->size);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            res.matr[i][j] = this->matr[i][j] + other.matr[i][j];
        }
    }
    return res;
}

Matrix Matrix::transpose() const {
    Matrix res(this->size);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            res.matr[j][i] = this->matr[i][j];
        }
    }
    return res;
}
