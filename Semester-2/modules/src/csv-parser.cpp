#include "csv-parser.h"
#include <iostream>
#include <fstream>

using namespace std;

Parser::Parser(const string &join_str, bool table_mode) {
    this->join_str = join_str;
    this->table_mode = table_mode;
}

Parser::Parser() {
    this->join_str = " ";
    this->table_mode = true;
}

vector<vector<string>> Parser::parse(const string &filename) {
    ifstream file(filename);
    if (!file)
        throw runtime_error("File does not exist");
    vector<vector<string>> result;
    string line;
    while (getline(file, line)) {
        vector<string> parsed_line;
        line += ",";
        bool quotes_mode = false;
        int substr_start_index = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '"')  // Если попали на кавычку
                quotes_mode = !quotes_mode;
            else if (line[i] == ',' && !quotes_mode) {  // Если встретили запятую вне кавычек
                parsed_line.push_back(
                        strip(line.substr(substr_start_index, i - substr_start_index), '"')
                );
                substr_start_index = i + 1;
            }
        }
        result.push_back(parsed_line);
    }
    return result;
}

void Parser::print(const vector<vector<string>> &parsed_data) {
    if (this->table_mode) {
        int max_line_count = 0;  // Ширина таблицы в столбцах
        for (const vector<string> &line: parsed_data)
            max_line_count = max_line_count < line.size() ? line.size() : max_line_count;

        vector<int> max_lengths(max_line_count);  // В каждом столбце максимальная ширина ячейки
        for (const vector<string> &line: parsed_data) {
            for (int i = 0; i < line.size(); i++)
                max_lengths[i] = max_lengths[i] < line[i].size() ? line[i].size() : max_lengths[i];
        }

        for (const vector<string> &line: parsed_data) {
            for (int i = 0; i < line.size(); i++) {
                int spaces_left = max_lengths[i] - line[i].size();
                string spaces = string(spaces_left, ' ');
                cout << line[i] << spaces << this->join_str;
            }
            cout << '\n';
        }
    } else {
        for (const vector<string> &line: parsed_data) {
            for (const string &word: line)
                cout << word << this->join_str;
            cout << '\n';
        }
    }
}

void Parser::write_to_file(const vector<vector<string>> &parsed_data, const string &filename) {
    ofstream out(filename);
    for (const vector<string> &line: parsed_data) {
        for (int i = 0; i < line.size() - 1; i++) {
            auto cell_value = line[i];
            bool has_commas = false;
            for (auto ch: cell_value)
                has_commas = (ch == ',') || has_commas;
            if (has_commas)
                out << "\"" << cell_value << "\",";
            else
                out << cell_value << ",";
        }
        out << line[line.size() - 1] << endl;
    }
    out.close();
}


ParserLoggerDecorator::ParserLoggerDecorator(ParserInterface *parser) {
    this->wrappee = parser;
    auto factory = CombinedLoggerFactory();
    this->logger = factory.createLogger();
}

vector<vector<string>> ParserLoggerDecorator::parse(const string &filename) {
    try {
        return this->wrappee->parse(filename);
    } catch (runtime_error &e) {
        this->logger->log_error(e.what());
        throw e;
    }
}

void ParserLoggerDecorator::print(const vector<vector<string>> &parsed_data) {
    try {
        this->wrappee->print(parsed_data);
    } catch (runtime_error &e) {
        this->logger->log_error(e.what());
        throw e;
    }
}

void ParserLoggerDecorator::write_to_file(const vector<vector<string>> &parsed_data, const string &filename) {
    try {
        this->wrappee->write_to_file(parsed_data, filename);
    } catch (runtime_error &e) {
        this->logger->log_error(e.what());
        throw e;
    }
}

string strip(const string& str, char ch) {
    bool remove_left = str[0] == ch;
    bool remove_right = str[str.size() - 1] == ch;
    return str.substr(remove_left, str.size() - remove_left - remove_right);
}
