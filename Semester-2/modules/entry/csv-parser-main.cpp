#include "csv-parser.h"
#include <vector>
#include <string>

using namespace std;

int main() {
    Parser parser("   |   ", true);
    vector<vector<string>> parsed_data = parser.parse(
            "C:/Users/Gleb/Desktop/Git Projects/OOP-University-tasks/Semester-2/modules/input-files/csv1.csv"
    );
    parser.print(parsed_data);
}
