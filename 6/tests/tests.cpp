#include "gtest/gtest.h"
#include "coder.h"
#include <string>

TEST(EncodingTests, ThreeNChars) {
    EXPECT_EQ("YWJv", encode("abo"));
    EXPECT_EQ("V1RG", encode("WTF"));
    EXPECT_EQ("d2hhdHRoZWRvZ2RvaW5n", encode("whatthedogdoing"));
    EXPECT_EQ("QklHRkxPUFBB", encode("BIGFLOPPA"));
    EXPECT_EQ("MTIzNDU2", encode("123456"));
}

TEST(EncodingTests, ThreeNPlusOneChars) {
    EXPECT_EQ("QnJ1aA==", encode("Bruh"));
    EXPECT_EQ("d2hhdGFyZXlvdWRvaW5nc3RlcGJybw==", encode("whatareyoudoingstepbro"));
    EXPECT_EQ("RkVGVQ==", encode("FEFU"));
    EXPECT_EQ("MDAwMA==", encode("0000"));
    EXPECT_EQ("OTg3NjU0Mw==", encode("9876543"));
}

TEST(EncodingTests, ThreeNPlusTwoChars) {
    EXPECT_EQ("c21hbGxGTE9QUEE=", encode("smallFLOPPA"));
    EXPECT_EQ("bWVtZXM=", encode("memes"));
    EXPECT_EQ("bWlzaGtmcmVkZGU=", encode("mishkfredde"));
    EXPECT_EQ("NTU1NTU=", encode("55555"));
    EXPECT_EQ("YXNmYnNkZmdydng=", encode("asfbsdfgrvx"));
}

TEST(EncodingTests, ShortStrings) {
    EXPECT_EQ("YQ==", encode("a"));
    EXPECT_EQ("aQ==", encode("i"));
    EXPECT_EQ("YWk=", encode("ai"));
    EXPECT_EQ("MQ==", encode("1"));
    EXPECT_EQ("Mg==", encode("2"));
    EXPECT_EQ("MjE=", encode("21"));
    EXPECT_EQ("Wg==", encode("Z"));
}

TEST(DecodingTests, ThreeNChars) {
    EXPECT_EQ("abo", decode("YWJv"));
    EXPECT_EQ("WTF", decode("V1RG"));
    EXPECT_EQ("whatthedogdoing", decode("d2hhdHRoZWRvZ2RvaW5n"));
    EXPECT_EQ("BIGFLOPPA", decode("QklHRkxPUFBB"));
    EXPECT_EQ("123456", decode("MTIzNDU2"));
}

TEST(DecodingTests, ThreeNPlusOneChars) {
    EXPECT_EQ("Bruh", decode("QnJ1aA=="));
    EXPECT_EQ("whatareyoudoingstepbro", decode("d2hhdGFyZXlvdWRvaW5nc3RlcGJybw=="));
    EXPECT_EQ("FEFU", decode("RkVGVQ=="));
    EXPECT_EQ("0000", decode("MDAwMA=="));
    EXPECT_EQ("9876543", decode("OTg3NjU0Mw=="));
}

TEST(DecodingTests, ThreeNPlusTwoChars) {
    EXPECT_EQ("smallFLOPPA", decode("c21hbGxGTE9QUEE="));
    EXPECT_EQ("memes", decode("bWVtZXM="));
    EXPECT_EQ("mishkfredde", decode("bWlzaGtmcmVkZGU="));
    EXPECT_EQ("55555", decode("NTU1NTU="));
    EXPECT_EQ("asfbsdfgrvx", decode("YXNmYnNkZmdydng="));
}

TEST(DecodingTests, ImpossibleCases) {
    EXPECT_ANY_THROW(decode("a"));
    EXPECT_ANY_THROW(decode("1"));
    EXPECT_ANY_THROW(decode("."));
    EXPECT_ANY_THROW(decode("...."));
    EXPECT_ANY_THROW(decode("1234"));
}