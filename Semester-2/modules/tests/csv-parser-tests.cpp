#include "gtest/gtest.h"
#include "csv-parser.h"

TEST(PARSER_TESTS, FILE_NOT_EXIST) {
    Parser parser(" ", false);
    EXPECT_ANY_THROW(parser.parse("sagasgasdgklkafglash.txt"));
}

TEST(PARSER_TESTS, FILE_1) {
    Parser parser(" ", false);
    auto result = parser.parse("csv1.csv");

    EXPECT_EQ(result[0][0], "1997");
    EXPECT_EQ(result[0][1], "Ford");
    EXPECT_EQ(result[0][2], "E350");
    EXPECT_EQ(result[0][3], "ac, abs, moon");
    EXPECT_EQ(result[0][4], "3000.00");

    EXPECT_EQ(result[1][0], "1999");
    EXPECT_EQ(result[1][1], "Chevy");
    EXPECT_EQ(result[1][2], "Venture Extended Edition");
    EXPECT_EQ(result[1][3], "");
    EXPECT_EQ(result[1][4], "4900.00");

    EXPECT_EQ(result[2][0], "1996");
    EXPECT_EQ(result[2][1], "Jeep");
    EXPECT_EQ(result[2][2], "Grand Cherokee");
    EXPECT_EQ(result[2][3], "MUST SELL! air, moon roof, loaded");
    EXPECT_EQ(result[2][4], "4799.00");
}

TEST(STRIP_TESTS, STRIP_TEST) {
    EXPECT_EQ(strip("\"Big Floppa", '"'), "Big Floppa");
    EXPECT_EQ(strip("Big Floppa\"", '"'), "Big Floppa");
    EXPECT_EQ(strip("\"Big Floppa\"", '"'), "Big Floppa");

    EXPECT_EQ(strip("\"Big\" Floppa\"", '"'), "Big\" Floppa");
    EXPECT_EQ(strip("Big Floppa", '"'), "Big Floppa");

    EXPECT_EQ(strip("", '"'), "");
    EXPECT_EQ(strip("\"", '"'), "");
    EXPECT_EQ(strip("\"\"", '"'), "");
}