#include "calc-machine.h"
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    BasicCalculatorFactory factory;
    auto calculator = factory.create();

    calculator->input_starting_value();

    std::string filename;
    std::cout << "Enter path of file with commands" << std::endl;
    std::getline(std::cin, filename);
    calculator->read_commands_from_file(filename);

    calculator->run();
}
