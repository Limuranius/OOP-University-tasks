#pragma once

#include <string>


// ----------------------------------------Логгеры---------------------------------------------------
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
    void log_error(const std::string &text) override;

    void log_warning(const std::string &text) override;

    void log_info(const std::string &text) override;
};


// ----------------------------------------Фабрики логгеров---------------------------------------------------
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

class CombinedLoggerFactory : public LoggerFactoryInterface {
public:
    LoggerInterface *createLogger() override;
};


// ----------------------------------------Декораторы логгеров---------------------------------------------------
class LoggerDecorator : public LoggerInterface {
protected:
    LoggerInterface *wrappee;
public:
    LoggerDecorator(LoggerInterface *source);

    void log_error(const std::string &text) override;

    void log_warning(const std::string &text) override;

    void log_info(const std::string &text) override;
};

class FileLoggerDecorator : public LoggerDecorator {
protected:
    FileLogger* fileLogger;

public:
    FileLoggerDecorator(LoggerInterface *source, const std::string& filename);

    void log_error(const std::string &text) override;

    void log_warning(const std::string &text) override;

    void log_info(const std::string &text) override;
};

class ConsoleLoggerDecorator : public LoggerDecorator {
protected:
    ConsoleLogger* consoleLogger;

public:
    ConsoleLoggerDecorator(LoggerInterface *source);

    void log_error(const std::string &text) override;

    void log_warning(const std::string &text) override;

    void log_info(const std::string &text) override;
};


void log(LoggerFactoryInterface *factory, const std::string &text);