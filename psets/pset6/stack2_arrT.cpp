// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <string>
#include <stack>


template<typename T>
struct Stack {
    T *item;
    int N;
    int capacity;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(int capacity) {
    stack<T> s = new Stack<T>;
    s -> item = new T[capacity];
    s -> N = 0;
    s -> capacity = capacity;
    return s;
}

template<typename T>
int size(stack<T> s) { return s->N; }

template<typename T>
bool empty(stack<T> s) { return s -> N ==0; }

template<typename T>
void pop (stack<T> s) { s -> N--; }

template<typename T>
T top(stack<T> s) {
    return s -> item[s -> N - 1];
}

template<typename T>
void push(stack<T> s, T item) {
    s -> item[s -> N++] = item;
}

template<typename T>
void printStack_fromBottom(stack<T> s) {
    if (empty(s)) return;
    T elem = top(s);
    pop(s);
    printStack_fromBottom(s);
    std::cout << elem << ' ';
    push(s, elem);
}

template<typename T>
void printStack(stack<T> s) {
    if (empty(s)) return;
    T elem = top(s);
    std::cout << elem << ' ';
    pop(s);
    printStack(s);
    push(s, elem);
}

int main() {
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    std::string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

      stack <std::string> s = newStack <std::string> (1);

    for (auto item : list) {
        if (item != "-"){
            push(s, item);
        }
        else {
            std::cout << top(s) << ' ';
            pop(s);
        }
    }
    
    std::cout << "\nsize(): " << s->N;
    std::cout << "\ntop(): " << s -> item[s -> N - 1];
    //std::cout << "\nstack T: "; printStack(s);
    //std::cout << "\nstack B: "; printStack_fromBottom(s);
    std::cout << "\nThe stack is: "; printStack(s);
    std::cout << "\nHapy Coding";
    
    delete s;
}
