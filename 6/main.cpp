#include <iostream>
#include <string>
#include "coder.h"

int main() {
    std::cout << "Enter string to encode: " << std::endl;
    std::string str;
    std::cin >> str;
    str = encode(str);
    std::cout << "Your encoded string: " << str << std::endl;

    str = decode(str);
    std::cout << "Decoded: " << str << std::endl;
}
