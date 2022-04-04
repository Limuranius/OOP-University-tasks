#include <iostream>
#include "big-integer.h"

int main() {
    BigInt a("5109512895084");
    BigInt b("81220598123098508");
    BigInt c = a * b;
    std::cout << c << std::endl;
}


