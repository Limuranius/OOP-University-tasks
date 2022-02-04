#include "gtest/gtest.h"
#include "polska.h"
#include <string>

TEST(RPN_TESTS, SUM) {
    std::string expr;

    expr = "5 5 +";
    EXPECT_EQ(10, calculateRPN(expr));

    expr = "7 -2 +";
    EXPECT_EQ(5, calculateRPN(expr));

    expr = "-5 5 +";
    EXPECT_EQ(0, calculateRPN(expr));

    expr = "-100 37 +";
    EXPECT_EQ(-63, calculateRPN(expr));

    expr = "-2.5 10.11 +";
    EXPECT_EQ(7.61, calculateRPN(expr));
}

TEST(RPN_TESTS, SUB) {
    std::string expr;

    expr = "5 5 -";
    EXPECT_EQ(0, calculateRPN(expr));

    expr = "7 -2 -";
    EXPECT_EQ(9, calculateRPN(expr));

    expr = "-5 5 -";
    EXPECT_EQ(-10, calculateRPN(expr));

    expr = "-100 37 -";
    EXPECT_EQ(-137, calculateRPN(expr));

    expr = "-2.5 10.11 -";
    EXPECT_EQ(-12.61, calculateRPN(expr));
}

TEST(RPN_TESTS, MUL) {
    std::string expr;

    expr = "5 5 *";
    EXPECT_EQ(25, calculateRPN(expr));

    expr = "7 -2 *";
    EXPECT_EQ(-14, calculateRPN(expr));

    expr = "-5 5 *";
    EXPECT_EQ(-25, calculateRPN(expr));

    expr = "-100 37 *";
    EXPECT_EQ(-3700, calculateRPN(expr));

    expr = "-2.5 10.11 *";
    EXPECT_EQ(-25.275, calculateRPN(expr));
}

TEST(RPN_TESTS, DIV) {
    std::string expr;

    expr = "5 5 /";
    EXPECT_EQ(1, calculateRPN(expr));

    expr = "7 -2 /";
    EXPECT_EQ(-3.5, calculateRPN(expr));

    expr = "-5 5 /";
    EXPECT_EQ(-1, calculateRPN(expr));

    expr = "-100 37 /";
    EXPECT_EQ(-100 / 37, calculateRPN(expr));

    expr = "-2.5 10.11 /";
    EXPECT_EQ(-2.5 / 10.11, calculateRPN(expr));
}

