#include "csv-keyval-converter.h"

DefaultDict<string> CSV_KeyVal_Converter::vector_to_dict(const vector<vector<string>> &vect) {
    DefaultDict<string> result("");
    for (const vector<string> &line: vect) {
        if (line.size() != 2)
            throw runtime_error("Invalid data in CSV file");
        result[line[0]] = line[1];
    }
    return result;
}

vector<vector<string>> CSV_KeyVal_Converter::dict_to_vector(const DefaultDict<string> &dict) {
    vector<pair<string, string>> items = dict.items();
    vector<vector<string>> result = {};
    vector<string> line;
    for (const pair<string, string> &item: items) {
        line = {item.first, item.second};
        result.push_back(line);
    }
    return result;
}
