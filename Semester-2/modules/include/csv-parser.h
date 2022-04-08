#pragma once

#include <string>
#include <vector>
#include <ostream>

using namespace std;

class Parser {
private:
    string join_str;
    bool table_mode;
public:
    explicit Parser(const string &join_str, bool table_mode);

    vector<vector<string>> parse(const string &filename);

    void print(const vector<vector<string>> &parsed_data);
};
