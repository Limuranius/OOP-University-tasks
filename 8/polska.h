#ifndef POL
#define POL

#include <string>
#include <vector>

std::string checkAndCalculateRPN(std::string expression);

float calculateRPN(std::string expression);

std::vector<std::string> split(std::string str, const std::string& key);

bool isNumber(const std::string& line);

bool isSign(const std::string& line);

#endif
