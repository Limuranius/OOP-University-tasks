#include "gtest/gtest.h"
#include "csv-parser.h"

TEST(PARSER_TESTS, FILE_NOT_EXIST) {
    Parser parser(" ", false);
    EXPECT_ANY_THROW(parser.parse("sagasgasdgklkafglash.txt"));
}