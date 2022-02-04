#ifndef POL
#define POL

#include <string>
#include <vector>

float calculateRPN(std::string expression);

std::vector<std::string> split(std::string str, std::string key);

bool isNumber(const std::string& line);

#endif
