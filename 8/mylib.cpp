#include "mylib.h"
#include <string>
#include <iostream>

CommandManager::CommandManager() {

}

void CommandManager::addCommand(const std::string& name, func_ptr function) {
    this->func_map[name] = function;
}

float CommandManager::runCommand(const std::string& name, std::string arg) {
    return func_map[name](arg);
}

bool CommandManager::isFuncValid(const std::string &name) {
    if (func_map[name] == 0) {  // If not found
        return false;
    }
    return true;
}
