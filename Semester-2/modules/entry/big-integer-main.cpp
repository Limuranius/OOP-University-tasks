#include <iostream>
#include "big-integer.h"

int main() {
    auto factory = BigIntFactory();
    BigInt a = factory.create("5654643543533");
    BigInt b = factory.create("095125780218503208");
    std::cout << a * b;
}


