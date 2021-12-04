#include "gtest/gtest.h"
#include "matrix.h"

TEST(matrixTest, CorrectMatrixCreation) {
    Matrix matrix(2);
    matrix.setValuesWithVector({1, 2, 3, 4});

    EXPECT_EQ(1, matrix.matr[0][0]);
    EXPECT_EQ(2, matrix.matr[0][1]);
    EXPECT_EQ(3, matrix.matr[1][0]);
    EXPECT_EQ(4, matrix.matr[1][1]);
}

TEST(matrixTest, belowZeroMatrixSize) {
    EXPECT_ANY_THROW(Matrix matrix(0));
    EXPECT_ANY_THROW(Matrix matrix(-10));
}

TEST(matrixTest, notEnoughInputElements) {
    Matrix matrix(3);
    EXPECT_ANY_THROW(matrix.setValuesWithVector({1, 2, 3, 4}));
}

TEST(matrixTest, sumEqualSizes) {
    Matrix A(2);
    Matrix B(2);
    A.setValuesWithVector({1, 2, 3, 4});
    B.setValuesWithVector({5, 6, 7, 8});

    Matrix C = A + B;
    EXPECT_EQ(6, C.matr[0][0]);
    EXPECT_EQ(8, C.matr[0][1]);
    EXPECT_EQ(10, C.matr[1][0]);
    EXPECT_EQ(12, C.matr[1][1]);
}

TEST(matrixTest, sumDifferSizes) {
    Matrix A(2);
    Matrix B(3);
    A.setValuesWithVector({1, 2, 3, 4});
    B.setValuesWithVector({1, 1, 1, 2, 2, 2, 3, 3, 3});

    EXPECT_ANY_THROW(A + B);
}

TEST(matrixTest, subEqualSizes) {
    Matrix A(2);
    Matrix B(2);
    A.setValuesWithVector({1, 2, 3, 4});
    B.setValuesWithVector({5, 6, 7, 8});

    Matrix C = A - B;
    EXPECT_EQ(-4, C.matr[0][0]);
    EXPECT_EQ(-4, C.matr[0][1]);
    EXPECT_EQ(-4, C.matr[1][0]);
    EXPECT_EQ(-4, C.matr[1][1]);
}

TEST(matrixTest, subDifferSizes) {
    Matrix A(2);
    Matrix B(3);
    A.setValuesWithVector({1, 2, 3, 4});
    B.setValuesWithVector({1, 1, 1, 2, 2, 2, 3, 3, 3});

    EXPECT_ANY_THROW(A - B);
}

TEST(matrixTest, mulEqualSizes) {
    Matrix A(2);
    Matrix B(2);
    A.setValuesWithVector({4, 3, 2, 1});
    B.setValuesWithVector({5, 6, 7, 8});

    Matrix C = A * B;
    EXPECT_EQ(41, C.matr[0][0]);
    EXPECT_EQ(48, C.matr[0][1]);
    EXPECT_EQ(17, C.matr[1][0]);
    EXPECT_EQ(20, C.matr[1][1]);
}

TEST(matrixTest, mulDifferSizes) {
    Matrix A(2);
    Matrix B(3);
    A.setValuesWithVector({1, 2, 3, 4});
    B.setValuesWithVector({1, 1, 1, 2, 2, 2, 3, 3, 3});

    EXPECT_ANY_THROW(A * B);
}

TEST(matrixTest, additionalMethods) {
    Matrix A(2);
    A.setValuesWithVector({3, 10, 12, 2});

    EXPECT_EQ(2, A.min());
    EXPECT_EQ(3, A.countEvenValues());
    EXPECT_EQ(27, A.sumOfPositiveValues());

    Matrix B(2);
    A.setValuesWithVector({1, -3, 11, -5});
    EXPECT_EQ(12, B.sumOfPositiveValues());
}

TEST(matrixTest, transposition) {
    Matrix A(2);
    A.setValuesWithVector({5, 3, 7, 9});

    Matrix B = A.transpose();
    EXPECT_EQ(5, B.matr[0][0]);
    EXPECT_EQ(7, B.matr[0][1]);
    EXPECT_EQ(3, B.matr[1][0]);
    EXPECT_EQ(9, B.matr[1][1]);
}