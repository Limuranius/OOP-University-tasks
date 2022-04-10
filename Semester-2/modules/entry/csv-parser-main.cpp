#include "csv-parser.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ParserInterface* parser = new Parser("   |   ", true);
    parser = new ParserLoggerDecorator(parser);

    cout << "Enter path to csv file:\n";
    string filename;
    getline(cin, filename);

    vector<vector<string>> parsed_data;

    parsed_data = parser->parse(filename);
    parser->print(parsed_data);
}
