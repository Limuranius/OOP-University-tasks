#include "big-integer.h"
#include "gtest/gtest.h"

TEST(BIG_INT_TESTS, INCORRECT_CREATION) {
    EXPECT_ANY_THROW(BigInt(""));
    EXPECT_ANY_THROW(BigInt("fdglksjdflkgjk45445klkj4pw09dif3434"));
    EXPECT_ANY_THROW(BigInt("8008S"));
    EXPECT_ANY_THROW(BigInt("--1823"));
    EXPECT_ANY_THROW(BigInt("1234-5678"));
    EXPECT_ANY_THROW(BigInt("12345678-"));
}

TEST(BIG_INT_TESTS, TO_STRING) {
    EXPECT_EQ(BigInt("0000000000").toString(), "0");
    EXPECT_EQ(BigInt("000255").toString(), "255");
    EXPECT_EQ(BigInt("1337").toString(), "1337");
    EXPECT_EQ(BigInt("-859").toString(), "-859");
    EXPECT_EQ(BigInt("-0000004564").toString(), "-4564");
    EXPECT_EQ(BigInt("7821457821459023980508349809").toString(), "7821457821459023980508349809");
}

TEST(BIG_INT_TESTS, SUM) {
    BigInt a("100");
    BigInt b("1000");
    BigInt c = a + b;
    EXPECT_EQ(c.toString(), "1100");

    a = BigInt("100");
    b = BigInt("-100");
    c = a + b;
    EXPECT_EQ(c.toString(), "0");

    a = BigInt("-1040");
    b = BigInt("-50");
    c = a + b;
    EXPECT_EQ(c.toString(), "-1090");

    a = BigInt("-55");
    b = BigInt("5");
    c = a + b;
    EXPECT_EQ(c.toString(), "-50");

    a = BigInt("8128350812501238902578013258700357820828135823597803105");
    b = BigInt("870123780325780312578152781597235763275735932597297597");
    c = a + b;
    EXPECT_EQ(c.toString(), "8998474592827019215156166040297593584103871756195100702");
}

TEST(BIG_INT_TESTS, SUB) {
    BigInt a("100");
    BigInt b("1000");
    BigInt c = a - b;
    EXPECT_EQ(c.toString(), "-900");

    a = BigInt("100");
    b = BigInt("-50");
    c = a - b;
    EXPECT_EQ(c.toString(), "150");

    a = BigInt("-139");
    b = BigInt("11");
    c = a - b;
    EXPECT_EQ(c.toString(), "-150");

    a = BigInt("-930");
    b = BigInt("-25");
    c = a - b;
    EXPECT_EQ(c.toString(), "-905");

    a = BigInt("125780950713280753829050982319050132059800158");
    b = BigInt("01723508912350912387109529352845025812082352135");
    c = a - b;
    EXPECT_EQ(c.toString(), "-1597727961637631633280478370525975680022551977");
}

TEST(BIG_INT_TESTS, MUL) {
    BigInt a("100");
    BigInt b("1000");
    BigInt c = a * b;
    EXPECT_EQ(c.toString(), "100000");

    a = BigInt("532");
    b = BigInt("-10");
    c = a * b;
    EXPECT_EQ(c.toString(), "-5320");

    a = BigInt("-12");
    b = BigInt("-20");
    c = a * b;
    EXPECT_EQ(c.toString(), "240");

    a = BigInt("-153");
    b = BigInt("275");
    c = a * b;
    EXPECT_EQ(c.toString(), "-42075");

    a = BigInt("780109835087132587901359780092109509");
    b = BigInt("000000012358012308573120858872587935980");
    c = a * b;
    EXPECT_EQ(c.toString(), "9640606944045731992412986416688629630772361343173999252742441233820");

    a = BigInt("870445870105810895089");
    b = BigInt("0");
    c = a * b;
    EXPECT_EQ(c.toString(), "0");

    a = BigInt("0");
    b = BigInt("2149124");
    c = a * b;
    EXPECT_EQ(c.toString(), "0");

    a = BigInt("0");
    b = BigInt("-2149124");
    c = a * b;
    EXPECT_EQ(c.toString(), "-0");
}

TEST(BIG_INT_TESTS, UNARY_MINUS) {
    EXPECT_EQ((-BigInt("25235")).toString(), "-25235");
    EXPECT_EQ((-BigInt("-325322")).toString(), "325322");
}

TEST(BIG_INT_TESTS, MULTIPLE_CALCULATIONS) {
    BigInt a("363246234");
    BigInt b("-7538992");
    BigInt c("2");
    BigInt d("87507980987");
    BigInt e("-19820491092021");
    BigInt f("-075806003445421321235231");

    BigInt g = a * b * c - d + e - (-f);
    EXPECT_EQ(g.toString(), "-75806008942350224620495");
}
