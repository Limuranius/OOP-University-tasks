#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "logger.h"
#include "csv-parser.h"
#include "csv-keyval-converter.h"
#include "key-value.h"

using namespace std;

class Authorizer {
private:
    DefaultDict<string> users_DB;
    string DB_path;
    LoggerInterface *logger;
    Parser parser;
    CSV_KeyVal_Converter converter;

    bool name_exist(const string &username);

    bool is_password_correct(const string &username, const string &password);

    void register_user(const string &username, const string &password);

    string to_hash(const string& str);

    void update_DB_file();

public:

    Authorizer(LoggerInterface *logger, const string &DB_path);

    void register_user();

    void log_in_user();
};

class BasicAuthorizerFactory {
public:
    Authorizer create(const string &DB_path);
};

long long hashFunction(const string& key);