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

TEST(matrixTest, notEnoughInputElements) {
    Matrix matrix(3);
    matrix.setValuesWithVector({1, 2, 3, 4});

    EXPECT_ANY_THROW()
}

TEST(matrixTest, sumEqualSizes) {

}

TEST(matrixTest, sumDifferSizes) {

}

TEST(matrixTest, subEqualSizes) {

}

TEST(matrixTest, subDifferSizes) {

}