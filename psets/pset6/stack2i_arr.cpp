#include <iostream>
#include <string>
#include <stack>



struct Stack {
    int *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity) {
    stack s = new Stack;
    s -> item = new int[capacity];
    s -> N = 0;
    s -> capacity = capacity;
    return s;
}


int size(stack s) { return s->N; }

bool empty(stack s) { return s -> N ==0; }

void pop (stack s) { s -> N--; }

int top(stack s) {
    return s -> item[s -> N - 1];
}

void push(stack s, int item) {
    s -> item[s -> N++] = item;
}

void printStack(stack s) {
    if (empty(s)) return;
    int elem = top(s);
    pop(s);
    printStack(s);
    std::cout << elem << ' ';
    push(s, elem);
}

void printStack_fromBottom(stack s) {
    if (empty(s)) return;
    int elem = top(s);
    std::cout << elem << ' ';
    pop(s);
    printStack(s);
    push(s, elem);
}

int main() {
    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    //std::string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack s = newStack(20);

    for (auto item : list) {
        if (item != 0){
            push(s, item);
        }
        else {
            std::cout << top(s) << ' ';
            pop(s);
        }
    }
    
    std::cout << "\nsize(): " ; size(s);
    std::cout << "\ntop(): " ; top(s);
    std::cout << "\nstack T: "; printStack(s);
    std::cout << "\nstack B: "; printStack_fromBottom(s);
    std::cout << "\nHapy Coding";
    
    delete s;
}
