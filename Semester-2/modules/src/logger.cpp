#include <logger-main.h>
#include <fstream>
#include <iostream>

FileLogger::FileLogger(const std::string &filename) {
    this->filename = filename;
}

void FileLogger::log_error(const std::string &text) {
    std::ofstream out(this->filename, std::ios_base::app);
    out << "Error: " << text << std::endl;
    out.close();
}

void FileLogger::log_warning(const std::string &text) {
    std::ofstream out(this->filename, std::ios_base::app);
    out << "Warning: " << text << std::endl;
    out.close();
}

void FileLogger::log_info(const std::string &text) {
    std::ofstream out(this->filename, std::ios_base::app);
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

LoggerDecorator::LoggerDecorator(LoggerInterface *source) {
    this->wrappee = source;
}

void LoggerDecorator::log_error(const std::string &text) {
    this->wrappee->log_error(text);
}

void LoggerDecorator::log_warning(const std::string &text) {
    this->wrappee->log_warning(text);
}

void LoggerDecorator::log_info(const std::string &text) {
    this->wrappee->log_info(text);
}

FileLoggerDecorator::FileLoggerDecorator(LoggerInterface *source, const std::string &filename)
        : LoggerDecorator(source) {
    this->fileLogger = new FileLogger(filename);
}

void FileLoggerDecorator::log_error(const std::string &text) {
    LoggerDecorator::log_error(text);
    this->fileLogger->log_error(text);
}

void FileLoggerDecorator::log_warning(const std::string &text) {
    LoggerDecorator::log_warning(text);
    this->fileLogger->log_warning(text);
}

void FileLoggerDecorator::log_info(const std::string &text) {
    LoggerDecorator::log_info(text);
    this->fileLogger->log_info(text);
}

ConsoleLoggerDecorator::ConsoleLoggerDecorator(LoggerInterface *source)
        : LoggerDecorator(source) {
    this->consoleLogger = new ConsoleLogger();
}

void ConsoleLoggerDecorator::log_error(const std::string &text) {
    LoggerDecorator::log_error(text);
    this->consoleLogger->log_error(text);
}

void ConsoleLoggerDecorator::log_warning(const std::string &text) {
    LoggerDecorator::log_warning(text);
    this->consoleLogger->log_warning(text);
}

void ConsoleLoggerDecorator::log_info(const std::string &text) {
    LoggerDecorator::log_info(text);
    this->consoleLogger->log_info(text);
}
