#include "big-integer.h"
#include "gtest/gtest.h"
#include "stack.h"

TEST(STACK_TESTS, EMPTY_STACK) {
    Stack<int> stack;
    EXPECT_ANY_THROW(stack.pop());
}

TEST(STACK_TESTS, INT) {
    Stack<int> stack;
    stack.push(552352);
    stack.push(124124);
    stack.push(23499450);
    stack.push(421480);
    EXPECT_EQ(stack.pop(), 421480);
    EXPECT_EQ(stack.pop(), 23499450);

    stack.push(123);
    EXPECT_EQ(stack.pop(), 123);

    EXPECT_EQ(stack.pop(), 124124);
    EXPECT_EQ(stack.pop(), 552352);
    EXPECT_ANY_THROW(stack.pop());
}

TEST(STACK_TESTS, BIG_INT) {
    Stack<BigInt> stack;
    stack.push(BigInt("1024012471249812740912"));
    stack.push(BigInt("8902130478312879403127840"));
    stack.push(BigInt("2135870213580132805"));
    stack.push(BigInt("851890580932501320902323412123243"));

    EXPECT_EQ(stack.pop().toString(), "851890580932501320902323412123243");
    EXPECT_EQ(stack.pop().toString(), "2135870213580132805");
    EXPECT_EQ(stack.pop().toString(), "8902130478312879403127840");
    EXPECT_EQ(stack.pop().toString(), "1024012471249812740912");
    EXPECT_ANY_THROW(stack.pop());
}


