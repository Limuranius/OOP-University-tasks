#pragma once

#include <string>
#include <vector>
#include <ostream>
#include "logger.h"

using namespace std;

class ParserInterface {
public:
    virtual vector<vector<string>> parse(const string &filename) = 0;

    virtual void print(const vector<vector<string>> &parsed_data) = 0;

    virtual void write_to_file(const vector<vector<string>> &parsed_data, const string& filename) = 0;
};

class Parser : public ParserInterface {
private:
    string join_str;
    bool table_mode;
public:
    explicit Parser(const string &join_str, bool table_mode);

    Parser();

    vector<vector<string>> parse(const string &filename) override;

    void print(const vector<vector<string>> &parsed_data) override;

    void write_to_file(const vector<vector<string>> &parsed_data, const string& filename) override;
};

class ParserLoggerDecorator : public ParserInterface {
private:
    ParserInterface *wrappee;
    LoggerInterface *logger;

public:
    explicit ParserLoggerDecorator(ParserInterface *parser);

    vector<vector<string>> parse(const string &filename) override;

    void print(const vector<vector<string>> &parsed_data) override;

    void write_to_file(const vector<vector<string>> &parsed_data, const string& filename) override;
};

string strip(const string& str, char ch);
