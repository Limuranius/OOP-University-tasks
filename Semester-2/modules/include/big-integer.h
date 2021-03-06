#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "logger.h"

class BigInt {
private:
    std::vector<int> digits;
    bool negative;

    BigInt(const std::vector<int> &digits, bool negative);

public:

    BigInt();

    BigInt(const std::string &value);

    int length() const;

    std::string toString() const;

    BigInt operator+(const BigInt &other) const;

    BigInt operator-() const;

    BigInt operator-(const BigInt &other) const;

    BigInt operator*(const BigInt &other) const;

    bool operator>(const BigInt &other) const;

    bool operator<(const BigInt &other) const;

    void removeLeadingZeros();
};

std::ostream &operator<<(std::ostream &out, const BigInt &number);

class BigIntFactory {
private:
    LoggerInterface *logger;
public:
    BigIntFactory();

    BigInt create(const std::string &value);
};