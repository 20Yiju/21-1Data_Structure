// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <string>
#include <stack>



struct Stack {
    std::string *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity) {
    stack s = new Stack;
    s -> item = new std::string[capacity];
    s -> N = 0;
    s -> capacity = capacity;
    return s;
}


int size(stack s) { return s->N; }

bool empty(stack s) { return s -> N ==0; }

void pop (stack s) { s -> N--; }

std::string top(stack s) {
    return s -> item[s -> N - 1];
}

void push(stack s, std::string item) {
    s -> item[s -> N++] = item;
}

void printStack(stack s) {
    if (empty(s)) return;
    std::string elem = top(s);
    pop(s);
    printStack(s);
    std::cout << elem << ' ';
    push(s, elem);
}

void printStack_fromBottom(stack s) {
    if (empty(s)) return;
    std::string elem = top(s);
    std::cout << elem << ' ';
    pop(s);
    printStack_fromBottom(s);
    push(s, elem);
}

int main() {
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    std::string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack s = newStack(1);

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
    std::cout << "\nstack T: "; printStack(s);
    std::cout << "\nstack B: "; printStack_fromBottom(s);
    std::cout << "\nHapy Coding";
    
    delete s;
}
