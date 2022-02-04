#include <iostream>
#include "polska.h"
#include "mylib.h"
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
//    std::string s = "aboba boba abo ba";
//    std::vector<std::string> spl = split(s, " ");
//    for (std::string sub: spl) {
//        std::cout << sub << std::endl;
//    }
//    std::cout << calculateRPN("3 5 + 7 / 10 *");
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i];
    }
}
