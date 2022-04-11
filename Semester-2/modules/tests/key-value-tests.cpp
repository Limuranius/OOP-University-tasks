#include "gtest/gtest.h"
#include "key-value.h"
#include "big-integer.h"

TEST(KEY_VALUE_TESTS, INT) {
    DefaultDict<int> d(0);
    d["a"] = 123;
    d["b"] = 456;
    d["a+b"] = d["a"] + d["b"];

    EXPECT_EQ(d["a"], 123);
    EXPECT_EQ(d["b"], 456);
    EXPECT_EQ(d["a+b"], 579);
    EXPECT_EQ(d["sdjanlasdjfsadf"], 0);
}

TEST(KEY_VALUE_TESTS, BIG_INT) {
    DefaultDict<BigInt> d(BigInt("0"));
    d["a"] = BigInt("89458091540781435780140819045120");
    d["b"] = BigInt("349054302523498503240");
    d["a*b"] = d["a"] * d["b"];

    EXPECT_EQ(d["a"].toString(), "89458091540781435780140819045120");
    EXPECT_EQ(d["b"].toString(), "349054302523498503240");
    EXPECT_EQ(d["a*b"].toString(), "31225731747850745625100866104384568592788006026188800");
    EXPECT_EQ(d["sdjanlasdjfsadf"].toString(), "0");
}
