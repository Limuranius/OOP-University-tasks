#include "polska.h"
#include <iostream>
#include <stack>
#include <string>
#include <vector>

float calculateRPN(std::string expression) {
    std::stack<std::string> stack;
    std::vector<std::string> split_expr = split(expression, " ");
    for (std::string val: split_expr) {
        if (isNumber(val)) {  // is number
            stack.push(val);
        } else {  // is +, -, *, /
            float v2 = std::stof(stack.top());
            stack.pop();
            float v1 = std::stof(stack.top());
            stack.pop();
            float v3;
            switch (val[0]) {
                case '+':
                    v3 = v1 + v2;
                    break;
                case '-':
                    v3 = v1 - v2;
                    break;
                case '*':
                    v3 = v1 * v2;
                    break;
                case '/':
                    v3 = v1 / v2;
                    break;
            }
            stack.push(std::to_string(v3));
        }
    }
    float result = std::stof(stack.top());
    return result;
}

std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> res;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        res.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    res.push_back(s);
    return res;
}

bool isNumber(const std::string& line) {
    int dotCount = 0;
    for (char ch : line) {
        if (ch == '.') {
            dotCount += 1;
            if (dotCount > 1) {
                return false;
            }
        } else if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}