#include <iostream>
#include "key-value.h"
#include "big-integer.h"

int main() {
    DefaultDict<BigInt> d(BigInt("0"));
    d["a"] = BigInt("12415873597839");
    d["b"] = BigInt("87458159780140985");
    d["c"] = BigInt("40120493290401");
    d["d"];
    d.print();
    std::cout << d["a"] * d["b"] << std::endl;
}

