#ifndef MY_LIB
#define MY_LIB
#include <map>
typedef float (*func_ptr)(std::string);

class CommandManager {
private:
    std::map<std::string, func_ptr> func_map;
//    int (*functions[])(int);
public:
    CommandManager();

    void addCommand(const std::string& name, func_ptr function);

    float runCommand(const std::string& name, std::string arg);
};

#endif
