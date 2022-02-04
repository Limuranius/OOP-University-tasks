#include "mylib.h"

CommandManager::CommandManager() {

}

void CommandManager::addCommand(const std::string& name, func_ptr function) {
    this->func_map[name] = function;
}

float CommandManager::runCommand(const std::string& name, std::string arg) {
    return func_map[name](arg);
}
