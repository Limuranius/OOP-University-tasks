#include "big-integer.h"
#include <string>

BigInt::BigInt(const std::string &value) {
    if (value.length() == 0)
        throw std::runtime_error("Error: empty string");
    this->digits = std::vector<int>();
    this->negative = false;
    int begin = 0;
    if (value[0] == '-') {
        this->negative = true;
        begin = 1;
    }
    // Идём с конца до начала (с наименьшего разряда до наибольшего)
    for (int i = value.size() - 1; i >= begin; i--) {
        char ch = value[i];
        if (!(ch >= '0' && ch <= '9'))  // Если попалась не цифра
            throw std::runtime_error("Error: Incorrect number");
        int digit = value[i] - '0';
        this->digits.push_back(digit);
    }
    this->removeLeadingZeros();
}

BigInt::BigInt(const std::vector<int> &digits, bool negative) {
    this->digits = std::vector<int>(digits);
    this->negative = negative;
    this->removeLeadingZeros();
}

int BigInt::length() const {
    return this->digits.size();
}

std::string BigInt::toString() const {
    std::string res = "";
    if (this->negative)
        res += '-';
    for (int i = this->length() - 1; i >= 0; i--) {
        res += std::to_string(this->digits[i]);
    }
    return res;
}

BigInt BigInt::operator+(const BigInt &other) const {
    if (this->negative || other.negative) {
        if (this->negative && !other.negative)  // (-a) + b = b - a = b - -(-a)
            return other - (-*this);
        if (!this->negative && other.negative)  // a + (-b) = a - b = a - -(-b)
            return *this - (-other);
        if (this->negative && other.negative)  // (-a) + (-b) = -(a + b) = -(-(-a) + -(-b))
            return -(-*this + -other);
    }

    int min_len = this->length();
    int max_len = other.length();
    const BigInt *biggerInt = &other;
    if (this->length() > other.length()) {
        min_len = other.length();
        max_len = this->length();
        biggerInt = this;
    }
    std::vector<int> result(max_len);

    int curr_sum;
    int digit;
    int carry = 0;
    for (int i = 0; i < max_len; i++) {
        if (i < min_len)
            curr_sum = this->digits[i] + other.digits[i] + carry;
        else
            curr_sum = biggerInt->digits[i] + carry;
        digit = curr_sum % 10;
        carry = curr_sum / 10;
        result[i] = digit;
    }
    if (carry != 0)  // Если появился новый разряд
        result.push_back(carry);

    BigInt res(result, false);
    res.removeLeadingZeros();
    return res;
}

BigInt BigInt::operator-() const {
    return BigInt(this->digits, !this->negative);
}

BigInt BigInt::operator-(const BigInt &other) const {
    if (this->negative || other.negative) {
        if (this->negative && !other.negative)  // (-a) - b = -(a + b) = -(-(-a) + b)
            return -(-*this + other);
        if (!this->negative && other.negative)  // a - (-b) = a + b = a + -(-b)
            return *this + -other;
        if (this->negative && other.negative)  // (-a) - (-b) = b - a = -(-b) - -(-a)
            return -other - -*this;
    }
    if (*this < other)  // Если результат получится отрицательный
        return -(other - *this);  // a - b = -(b - a)


    int min_len = other.length();
    int max_len = this->length();
    const BigInt *biggerInt = this;
    std::vector<int> result(max_len);

    int curr_sub;
    int digit;
    int take = 0;
    for (int i = 0; i < max_len; i++) {
        if (i < min_len)
            curr_sub = this->digits[i] - other.digits[i] - take;
        else
            curr_sub = biggerInt->digits[i] - take;
        digit = (curr_sub + 10) % 10;
        take = int(curr_sub < 0);
        result[i] = digit;
    }

    BigInt res(result, false);
    res.removeLeadingZeros();
    return res;
}

BigInt BigInt::operator*(const BigInt &other) const {
    BigInt res("0");
    for (int i = 0; i < other.length(); i++) {
        int mult_digit = other.digits[i];
        int curr_mul;
        int digit;
        int carry = 0;
        std::vector<int> curr_res(this->length() + i);
        for (int j = 0; j < this->length(); j++) {
            curr_mul = this->digits[j] * mult_digit + carry;
            digit = curr_mul % 10;
            carry = curr_mul / 10;
            curr_res[j + i] = digit;
        }
        if (carry != 0)  // Если появился новый разряд
            curr_res.push_back(carry);
        res = res + BigInt(curr_res, false);
    }
    if (this->negative + other.negative == 1)  // Если одно из чисел отрицательное
        return -res;
    res.removeLeadingZeros();
    return res;
}

bool BigInt::operator>(const BigInt &other) const {
    if (this->length() > other.length())
        return true;
    else if (this->length() < other.length())
        return false;
    else {
        for (int i = this->length() - 1; i >= 0; i--) {  // Идём с конца, самого высокого разряда
            if (this->digits[i] > other.digits[i])
                return true;
        }
        return false;
    }
}

bool BigInt::operator<(const BigInt &other) const {
    if (this->length() > other.length())
        return false;
    else if (this->length() < other.length())
        return true;
    else {
        for (int i = this->length() - 1; i >= 0; i--) {  // Идём с конца, самого высокого разряда
            if (this->digits[i] < other.digits[i])
                return true;
        }
        return false;
    }
}

void BigInt::removeLeadingZeros() {
    int i = this->length() - 1;
    while (i > 0 && this->digits[i] == 0) {
        this->digits.pop_back();
        i--;
    }
}

std::ostream &operator<<(std::ostream &out, const BigInt &number) {
    out << number.toString();
    return out;
}
