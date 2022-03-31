#include <iostream>
#include "polska.h"
#include "mylib.h"
#include <string>
#include <vector>
#include <map>

int main(int argc, char* argv[]) {
    CommandManager cmd;
    cmd.addCommand("calc", checkAndCalculateRPN);
    if (argc == 1) {
        std::cout << "calc \"expression\" - calculate reverse polish notation expression";
    } else if (cmd.isFuncValid(argv[1])) {
        std::cout << cmd.runCommand(argv[1], argv[2]);
    } else {
        std::cout << "Error: no such function name: " << argv[1] << std::endl;
    }
}
