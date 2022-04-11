#include "stack.h"
#include "big-integer.h"
#include "logger.h"

int main() {
    CombinedLoggerFactory factory;
    auto logger = factory.createLogger();
    try {
        Stack<BigInt> stack;
        stack.push(BigInt("28342879280350981"));
        stack.push(BigInt("2345243523"));
        stack.push(BigInt("43542534534513456"));
        stack.push(BigInt("13471383157234"));
        stack.push(BigInt("0000008208550524534"));
        std::cout << "Stack: " << stack << std::endl;
        std::cout << "Popped: " << stack.pop() << std::endl;
        std::cout << "Stack: " << stack << std::endl;
//        stack.pop();
//        stack.pop();
//        stack.pop();
//        stack.pop();
//        stack.pop();
    } catch (std::runtime_error& e) {
        logger->log_error(e.what());
        throw e;
    }
}

