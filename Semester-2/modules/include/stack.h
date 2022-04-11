#pragma once

#include <iostream>

template<typename T>
class Node {
public:
    T value;
    Node<T> *next;

    Node(T value, Node<T> *next);
};


template<typename T>
class Stack {
private:
    Node<T> *top;
public:
    Stack();

    void push(T value);

    T pop();

    Node<T> *getTop() const;
};

template<typename T>
Node<T>::Node(T value, Node<T> *next) {
    this->value = value;
    this->next = next;
}


template<typename T>
Stack<T>::Stack() {
    this->top = nullptr;
}

template<typename T>
void Stack<T>::push(T value) {
    Node<T> *newNode = new Node<T>(value, this->top);
    this->top = newNode;
}

template<typename T>
T Stack<T>::pop() {
    if (this->top == nullptr)
        throw std::runtime_error("Stack is empty");
    Node<T> *resultNode = this->top;
    this->top = this->top->next;
    T result = resultNode->value;
    delete resultNode;
    return result;
}

template<typename T>
Node<T> *Stack<T>::getTop() const {
    return this->top;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Stack<T>& stack) {
    Node<T> *curr = stack.getTop();
    while (curr != nullptr) {
        out << curr->value << " ";
        curr = curr->next;
    }
    return out;
}