#include "calc-machine.h"

Calculator::Calculator(LoggerInterface *logger) {
    this->logger = logger;
    this->commands = DefaultDict<func>(nullptr);
    this->comms_stack = Stack<std::pair<std::string, BigInt>>();
    this->curr_value = BigInt("0");
}


void Calculator::input_starting_value() {
    std::cout << "Enter starting value: \n";
    std::string input;
    std::getline(std::cin, input);
    this->curr_value = BigInt(input);
}

void Calculator::add_command(const std::string &name, func function) {
    this->commands[name] = function;
}

void Calculator::read_commands_from_file(const std::string &filename) {
    std::ifstream inp(filename);
    if (!inp)
        throw std::runtime_error("File does not exist");
    std::string command;
    std::string number;
    while (!inp.eof()) {  // Пока не в конце файла
        inp >> command >> number;
        if (this->commands[command] == nullptr)  // Если полученной команды не существует
            throw std::runtime_error("Command not found");
        this->comms_stack.push({command, BigInt(number)});
    }
}

void Calculator::run() {
    std::pair<std::string, BigInt> command;
    this->logger->log_info("Начало работы вычислительной машины. Стартовое значение: " + this->curr_value.toString());
    while (!this->comms_stack.isEmpty()) {
        command = this->comms_stack.pop();
        this->logger->log_info("Применяем операцию " + command.first + " " + command.second.toString());
        this->curr_value = this->commands[command.first](this->curr_value, command.second);
        this->logger->log_info("Результат: " + this->curr_value.toString());
    }
}

BigInt Calculator::get_curr_value() {
    return this->curr_value;
}

CalculatorLoggerDecorator::CalculatorLoggerDecorator(CalculatorInterface *calculator, LoggerInterface *logger) {
    this->wrappee = calculator;
    this->logger = logger;
}

void CalculatorLoggerDecorator::input_starting_value() {
    try {
        this->wrappee->input_starting_value();
    } catch (std::runtime_error &e) {
        this->logger->log_error(e.what());
        throw e;
    }
}

void CalculatorLoggerDecorator::add_command(const std::string &name, func function) {
    try {
        this->wrappee->add_command(name, function);
    } catch (std::runtime_error &e) {
        this->logger->log_error(e.what());
        throw e;
    }
}

void CalculatorLoggerDecorator::read_commands_from_file(const std::string &filename) {
    try {
        this->wrappee->read_commands_from_file(filename);
    } catch (std::runtime_error &e) {
        this->logger->log_error(e.what());
        throw e;
    }
}

void CalculatorLoggerDecorator::run() {
    try {
        this->wrappee->run();
    } catch (std::runtime_error &e) {
        this->logger->log_error(e.what());
        throw e;
    }
}

BigInt CalculatorLoggerDecorator::get_curr_value() {
    return this->wrappee->get_curr_value();
}

CalculatorInterface* BasicCalculatorFactory::create() {
    CombinedLoggerFactory factory;
    auto logger = factory.createLogger();
    CalculatorInterface* calc = new Calculator(logger);
    calc = new CalculatorLoggerDecorator(calc, logger);
    calc->add_command("ADD", sum);
    calc->add_command("SUB", sub);
    calc->add_command("MUL", mul);
    return calc;
}

CalculatorInterface* NoLogCalculatorFactory::create() {
    LoggerInterface* logger = new EmptyLogger();
    CalculatorInterface* calc = new Calculator(logger);
    calc = new CalculatorLoggerDecorator(calc, logger);
    calc->add_command("ADD", sum);
    calc->add_command("SUB", sub);
    calc->add_command("MUL", mul);
    return calc;
}

BigInt sum(BigInt a, BigInt b) {
    return a + b;
}

BigInt sub(BigInt a, BigInt b) {
    return a - b;
}

BigInt mul(BigInt a, BigInt b) {
    return a * b;
}
