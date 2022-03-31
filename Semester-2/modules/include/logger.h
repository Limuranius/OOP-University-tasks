#pragma once

#include <string>

class LoggerInterface {
public:
    virtual void log_error(const std::string &text) = 0;

    virtual void log_warning(const std::string &text) = 0;

    virtual void log_info(const std::string &text) = 0;
};

class FileLogger : public LoggerInterface {
private:
    std::string filename;
public:
    explicit FileLogger(const std::string &filename);

    void log_error(const std::string &text) override;

    void log_warning(const std::string &text) override;

    void log_info(const std::string &text) override;
};

class ConsoleLogger : public LoggerInterface {
public:
//    ConsoleLogger(const std::string& filename);
    void log_error(const std::string &text) override;

    void log_warning(const std::string &text) override;

    void log_info(const std::string &text) override;
};

class LoggerFactoryInterface {
public:
    virtual LoggerInterface *createLogger() = 0;
};

class FileLoggerFactory : public LoggerFactoryInterface {
public:
    LoggerInterface *createLogger() override;
};

class ConsoleLoggerFactory : public LoggerFactoryInterface {
public:
    LoggerInterface *createLogger() override;
};

void log(LoggerFactoryInterface* factory, std::string text);