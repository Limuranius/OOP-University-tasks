#pragma once

#include <iostream>
#include <string>
#include "key-value.h"

using namespace std;

class CSV_KeyVal_Converter {
public:
    DefaultDict<string> vector_to_dict(const vector<vector<string>> &vect);

    vector<vector<string>> dict_to_vector(const DefaultDict<string> &dict);
};
