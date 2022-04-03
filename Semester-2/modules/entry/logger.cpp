#include <iostream>
#include "logger.h"
#include <string>

int main() {
    std::string log1_filename = "log1.txt";
    std::string log2_filename = "log2.txt";
    std::string log3_filename = "log3.txt";

    auto factory = new ConsoleLoggerFactory();
    auto logger = factory->createLogger();
    logger = new FileLoggerDecorator(logger, log1_filename);
    logger = new FileLoggerDecorator(logger, log2_filename);
    logger = new FileLoggerDecorator(logger, log3_filename);

    logger->log_info("Внимание! Спасибо за внимание!");
    logger->log_warning("Предупреждение! Выпрямите спину!");
    logger->log_error("Ошибка! Ищите её сами!");
}