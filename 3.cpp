// 6 вариант

#include <iostream>

class Matrix {
public:
    int size;
    int **matr;

    explicit Matrix(int size) {
        this->size = size;
        this->matr = new int *[size];
        for (int i = 0; i < size; i++) {
            this->matr[i] = new int[size];
        }
    }

    void setValuesWithConsole() {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                std::cin >> this->matr[i][j];
            }
        }
    }

    int min() {
        int min = this->matr[0][0];
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                min = (this->matr[i][j] < min) ? this->matr[i][j] : min;
            }
        }
        return min;
    }

    int countEvenValues() {
        int count = 0;
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                count += this->matr[i][j] % 2 == 0;
            }
        }
        return count;
    }

    int sumOfPositiveValues() {
        int sum = 0;
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                sum += (this->matr[i][j] >= 0) * this->matr[i][j];
            }
        }
        return sum;
    }

    Matrix operator*(const Matrix &other) {
        if (this->size != other.size) {
            throw std::runtime_error("Matrices' sizes differ!");
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

    Matrix operator-(const Matrix &other) {
        if (this->size != other.size) {
            throw std::runtime_error("Matrices' sizes differ!");
        }
        Matrix res(this->size);
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                res.matr[i][j] = this->matr[i][j] - other.matr[i][j];
            }
        }
        return res;
    }

    Matrix transpose() {
        Matrix res(this->size);
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                res.matr[j][i] = this->matr[i][j];
            }
        }
        return res;
    }

    void print() {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                std::cout << this->matr[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
};

int test() {
    int n;
    std::cout << "Enter size of square matrix A:\n";
    std::cin >> n;
    Matrix A(n);

    std::cout << "Enter " << n * n << " values of matrix A:\n";
    A.setValuesWithConsole();


    std::cout << "Enter size of square matrix C:\n";
    std::cin >> n;
    Matrix C(n);

    std::cout << "Enter " << n * n << " values of matrix C:\n";
    C.setValuesWithConsole();


    std::cout << "Min of A: " << A.min() << '\n';
    std::cout << "Number of even values in A: " << A.countEvenValues() << '\n';
    std::cout << "Sum of positive values in A: " << A.sumOfPositiveValues() << "\n\n";

    std::cout << "A^2:" << '\n';
    (A * A).print();

    std::cout << "C^T:" << '\n';
    C.transpose().print();

    std::cout << "Calculating B = A^2 - C^T..." << std::endl;
    Matrix B = A * A - C.transpose();
    B.print();
}

int main() {
    test();
}