#include "matrix.h"
#include "print.h"
#include <iostream>

void testManualInput() {
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
    printMatrix(A * A);

    std::cout << "C^T:" << '\n';
    printMatrix(C.transpose());

    std::cout << "Calculating B = A^2 - C^T..." << std::endl;
    Matrix B = A * A - C.transpose();
    printMatrix(B);
}

void testGivenInput() {
    int n = 2;

    Matrix A(n);
    std::cout <<  "A:\n"
                  "1 2\n"
                  "3 4\n\n";
    A.setValuesWithVector({1, 2, 3, 4});

    Matrix C(n);
    std::cout <<  "C:\n"
                  "5 6\n"
                  "7 8\n\n";
    C.setValuesWithVector({5, 6, 7, 8});


    std::cout << "Min of A: " << A.min() << '\n';
    std::cout << "Number of even values in A: " << A.countEvenValues() << '\n';
    std::cout << "Sum of positive values in A: " << A.sumOfPositiveValues() << "\n\n";

    std::cout << "A^2:" << '\n';
    printMatrix(A * A);

    std::cout << "C^T:" << '\n';
    printMatrix(C.transpose());

    std::cout << "Calculating B = A^2 - C^T..." << std::endl;
    Matrix B = A * A - C.transpose();
    printMatrix(B);
}

int main() {
//    testGivenInput();
    std::cout << "aboba" << std::endl;
}