#include "coder.h"
#include <map>
#include <iostream>

std::string encode(const std::string & str)  {
    std::string base64characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string result;
    unsigned int charsMissing = bool(str.size() % 3) * (3 - str.size() % 3);  // Сколько не хватает символов в конце, чтобы было кратно 3
    for (int i = 0; i < str.size() / 3; i++) {  // Проходимся по группам по 3 байта, кроме последней
        unsigned int threeByteBuffer = 0;

        for (int j = 0; j < 3; j++) {
            threeByteBuffer += str[i*3 + j];
            threeByteBuffer <<= 8;
        }

        for (int j = 0; j < 4; j++) {
            unsigned int index = threeByteBuffer >> 26;
            result += base64characters[index];
            threeByteBuffer <<= 6;
        }
    }

    // Разбираемся с последней частью
    if (charsMissing != 0) {
        // 2 случая: До кратности 3 не хватает 2 символа - добавляются 2 символа и 2 "=", 1 символ - 3 символа и 1 "="
        unsigned int lastPartIndex = str.size() / 3 * 3;
        unsigned int threeByteBuffer = 0;
        int cycleCount = 0;
        if (charsMissing == 1) {
            threeByteBuffer += (str[lastPartIndex] << 8 * 3) + (str[lastPartIndex + 1] << 8 * 2);
            cycleCount = 3;
        }
        else if (charsMissing == 2) {
            threeByteBuffer += str[lastPartIndex] << 8 * 3;
            cycleCount = 2;
        }
        for (int j = 0; j < cycleCount; j++) {
            unsigned int index = threeByteBuffer >> 26;
            result += base64characters[index];
            threeByteBuffer <<= 6;
        }
        for (int j = 0; j < charsMissing; j++) {result += "=";}
    }

    return result;
}


std::string decode(const std::string & str) {
    // Предварительная проверка строки на правильность
    if (str.size() % 4 != 0) {
        throw std::runtime_error("Error: Invalid input!");
    }
    for (char ch: str) {
        if (!(ch == '/' ||
              ch == '+' ||
              ch == '=' ||
              (ch >= '0' && ch <= '9') ||
              (ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z'))) {
            throw std::runtime_error("Error: Invalid input!");
        }
    }
    if (str.empty()) {
        return "";
    }

    std::string base64characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::map<char, int> base64indexes;
    // Создаём словарь "символ - индекс"
    for (int i = 0; i < base64characters.size(); i++) {
        base64indexes[base64characters[i]] = i;
    }

    std::string result;
    for (int i = 0; i < str.size() / 4 - 1; i++) {  // Проходимся по группам по 3 байта, кроме последней
        unsigned int threeByteBuffer = 0;

        for (int j = 0; j < 4; j++) {
            threeByteBuffer += base64indexes[str[i*4 + j]];
            threeByteBuffer <<= 6;
        }
        threeByteBuffer <<= 2;  // Сдвигаем к левой границе

        for (int j = 0; j < 3; j++) {
            char character = char(threeByteBuffer >> 24);
            result += character;
            threeByteBuffer <<= 8;
        }
    }

    // Разбираемся с последней частью
    unsigned int charsMissing = (str[str.size() - 1] == '=') + (str[str.size() - 2] == '=');
    unsigned int lastPartIndex = str.size() - 4;
    unsigned int threeByteBuffer = 0;

    for (int j = 0; j < 4 - charsMissing; j++) {
        threeByteBuffer += base64indexes[str[lastPartIndex + j]] << (26 - 6 * j);
    }

    int cycleCount = 3 - charsMissing;

    for (int j = 0; j < cycleCount; j++) {
        char character = char(threeByteBuffer >> 24);
        result += character;
        threeByteBuffer <<= 8;
    }

    return result;
}