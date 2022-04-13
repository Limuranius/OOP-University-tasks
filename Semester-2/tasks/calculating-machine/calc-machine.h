#pragma once

#include "stack.h"
#include "big-integer.h"
#include "key-value.h"
#include "logger.h"
#include <iostream>
#include <string>
#include <fstream>


typedef BigInt (*func)(BigInt, BigInt);


class CalculatorInterface {
public:
    virtual void input_starting_value() = 0;

    virtual void add_command(const std::string &name, func function) = 0;

    virtual void read_commands_from_file(const std::string &filename) = 0;

    virtual void run() = 0;
};

class Calculator : public CalculatorInterface {
private:
    DefaultDict<func> commands;
    Stack<std::pair<std::string, BigInt>> comms_stack;
    BigInt curr_value;
    LoggerInterface *logger;  // Внутри класса используется только для вывода результатов в info

public:
    Calculator(LoggerInterface *logger);

    void input_starting_value() override;

    void add_command(const std::string &name, func function) override;

    void read_commands_from_file(const std::string &filename) override;

    void run() override;
};

class CalculatorLoggerDecorator : public CalculatorInterface {
private:
    CalculatorInterface *wrappee;
    LoggerInterface *logger;
public:
    CalculatorLoggerDecorator(CalculatorInterface *calculator, LoggerInterface *logger);

    void input_starting_value() override;

    void add_command(const std::string &name, func function) override;

    void read_commands_from_file(const std::string &filename) override;

    void run() override;
};

class BasicCalculatorFactory {
public:
    CalculatorInterface* create();
};

BigInt sum(BigInt a, BigInt b);
BigInt sub(BigInt a, BigInt b);
BigInt mul(BigInt a, BigInt b);