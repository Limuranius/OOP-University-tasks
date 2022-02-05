#include "gtest/gtest.h"
#include "polska.h"
#include <string>

TEST(RPN_TESTS, IS_NUMBER) {
    EXPECT_TRUE(isNumber("13"));
    EXPECT_TRUE(isNumber("-13"));
    EXPECT_TRUE(isNumber("1.3"));
    EXPECT_TRUE(isNumber("-1.3"));
    EXPECT_FALSE(isNumber("+"));
    EXPECT_FALSE(isNumber("-"));
    EXPECT_FALSE(isNumber("*"));
    EXPECT_FALSE(isNumber("/"));
    EXPECT_FALSE(isNumber("asdgfasgasb"));
    EXPECT_FALSE(isNumber(" "));
    EXPECT_FALSE(isNumber(""));
}

TEST(RPN_TESTS, IS_SIGN) {
    EXPECT_TRUE(isSign("+"));
    EXPECT_TRUE(isSign("-"));
    EXPECT_TRUE(isSign("*"));
    EXPECT_TRUE(isSign("/"));
    EXPECT_FALSE(isSign("+ "));
    EXPECT_FALSE(isSign(" * "));
    EXPECT_FALSE(isSign("-35"));
    EXPECT_FALSE(isSign("79"));
    EXPECT_FALSE(isSign("sdgasgab"));
    EXPECT_FALSE(isSign(" "));
    EXPECT_FALSE(isSign(""));

}

TEST(RPN_TESTS, SPLIT) {
    std::vector<std::string> v = split("37 5 - 500 * 7.52 /", " ");
    EXPECT_EQ("37", v[0]);
    EXPECT_EQ("5", v[1]);
    EXPECT_EQ("-", v[2]);
    EXPECT_EQ("500", v[3]);
    EXPECT_EQ("*", v[4]);
    EXPECT_EQ("7.52", v[5]);
    EXPECT_EQ("/", v[6]);
}

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
    EXPECT_NEAR(7.61, calculateRPN(expr), 0.000001);
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
    EXPECT_NEAR(-12.61, calculateRPN(expr), 0.000001);
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
    EXPECT_NEAR(-25.275, calculateRPN(expr), 0.000001);
}

TEST(RPN_TESTS, DIV) {
    std::string expr;

    expr = "5 5 /";
    EXPECT_EQ(1, calculateRPN(expr));

    expr = "7 -2 /";
    EXPECT_NEAR(-3.5, calculateRPN(expr), 0.000001);

    expr = "-5 5 /";
    EXPECT_EQ(-1, calculateRPN(expr));

    expr = "-100 37 /";
    EXPECT_NEAR(-100.0 / 37.0, calculateRPN(expr), 0.000001);

    expr = "-2.5 10.11 /";
    EXPECT_NEAR(-2.5 / 10.11, calculateRPN(expr), 0.000001);
}

TEST(RPN_TESTS, COMPLEX_EXPRESSIONS) {
    std::string expr;

    expr = "5 3 - 10 + 5 * 2 /";
    EXPECT_NEAR(30, calculateRPN(expr), 0.000001);

    expr = "5 4 - 3 - 2 - 1 -";
    EXPECT_NEAR(-5, calculateRPN(expr), 0.000001);

    expr = "1 2 * 3 * 4 * 5 *";
    EXPECT_NEAR(120, calculateRPN(expr), 0.000001);

    expr = "64 2 / 2 / 4 /";
    EXPECT_NEAR(4, calculateRPN(expr), 0.000001);
}

TEST(RPN_TESTS, INCORRECT_DATA) {
    std::string expr;

    expr = "5 3 - 10      + 5 * 2 /";
    EXPECT_EQ("Error: Expression is incorrect", checkAndCalculateRPN(expr));

    expr = "aboba";
    EXPECT_EQ("Error: Expression is incorrect", checkAndCalculateRPN(expr));

    expr = "";
    EXPECT_EQ("Error: Expression is incorrect", checkAndCalculateRPN(expr));

    expr = " ";
    EXPECT_EQ("Error: Expression is incorrect", checkAndCalculateRPN(expr));
}
