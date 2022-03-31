#include <logger.h>
#include <fstream>
#include <iostream>

FileLogger::FileLogger(const std::string &filename) {
    this->filename = filename;
}

void FileLogger::log_error(const std::string &text) {
    std::ofstream out(this->filename);
    out << "Error: " << text << std::endl;
    out.close();
}

void FileLogger::log_warning(const std::string &text) {
    std::ofstream out(this->filename);
    out << "Warning: " << text << std::endl;
    out.close();
}

void FileLogger::log_info(const std::string &text) {
    std::ofstream out(this->filename);
    out << "Info: " << text << std::endl;
    out.close();
}

void ConsoleLogger::log_error(const std::string &text) {
    std::cout << "Error: " << text << std::endl;
}

void ConsoleLogger::log_warning(const std::string &text) {
    std::cout << "Warning: " << text << std::endl;
}

void ConsoleLogger::log_info(const std::string &text) {
    std::cout << "Info: " << text << std::endl;
}

LoggerInterface *FileLoggerFactory::createLogger() {
    return new FileLogger("log.txt");
}

LoggerInterface *ConsoleLoggerFactory::createLogger() {
    return new ConsoleLogger();
}

void log(LoggerFactoryInterface *factory, const std::string &text) {
    LoggerInterface *logger = factory->createLogger();
    logger->log_info(text);
}