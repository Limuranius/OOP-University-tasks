#pragma once

#include <vector>
#include <string>
#include <iostream>

template <typename T>
class DefaultDict {
private:
    std::vector<std::string> keys;
    std::vector<T> values;
    T default_value;

    int find(const std::string& key);
public:
    DefaultDict(T default_value);

    T& operator[](std::string key);

    void print();
};

template <typename T>
DefaultDict<T>::DefaultDict(T default_value) {
    this->keys = {};
    this->values = {};
    this->default_value = default_value;
}

template <typename T>
int DefaultDict<T>::find(const std::string& key) {
    for (int i = 0; i < this->keys.size(); i++) {
        if (this->keys[i] == key)
            return i;
    }
    return -1;
}

template <typename T>
T& DefaultDict<T>::operator[](std::string key) {
    int key_index = this->find(key);
    if (key_index == -1) { // Если значение ещё не было добавлено
        this->keys.push_back(key);
        this->values.push_back(this->default_value);
        key_index = this->keys.size() - 1;
    }
    return this->values[key_index];
}

template <typename T>
void DefaultDict<T>::print() {
    std::cout << "{";
    if (this->keys.size() != 0) {
        std::cout << '\"' << this->keys[0] << "\": " << this->values[0];
        for (int i = 1; i < this->keys.size(); i++)
            std::cout << ", " << '\"' << this->keys[i] << "\": " << this->values[i];
    }
    std::cout << "}" << std::endl;
}