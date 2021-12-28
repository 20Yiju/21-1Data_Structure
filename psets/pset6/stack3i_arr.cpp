#include <iostream>
#include <string>
#include <stack>

#ifdef DEBUG
#define DPRINT(func);
#else
#define DPRINT(func) func;
#endif
struct Stack {
    int *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity = 1) {
    stack s = new Stack;
    s -> item = new int[capacity];
    s -> N = 0;
    s -> capacity = capacity;
    return s;
}

void resize(stack s, int new_capacity) {
    int *copied = new int[new_capacity];
    for (int i = 0; i < s->N; i++)
        copied[i] = s->item[i];
    delete[] s->item;
    s->item = copied;
    s->capacity = new_capacity;
}

void free(stack s) {
    delete[] s->item;
    delete s;
}

//int size(stack s) { return s->N; }

bool empty(stack s) { return s -> N == 0; }

void pop (stack s) { 
    s -> N--;
    if (s->N > 0 && s->N == (s->capacity)/4) { 
        resize(s, (s->capacity)/2);
    }
}

int top(stack s) {
    return s -> item[s -> N - 1];
}

void push(stack s, int item) {
    if(s->capacity == s->N){
        resize(s, 2 * s->capacity);
    }
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

    stack s = newStack();

    for (auto item : list) {
        if (item != 0){
            push(s, item);
            DPRINT(std::cout << "size:" << s -> N << " capa:" << s->capacity << std::endl);
        }
        else {
            std::cout << top(s) << ' ';
            pop(s);
        }
    }
    
    std::cout << "\nsize:" << s -> N;
    std::cout << "\ntop:" << s -> item[s -> N - 1];
    //std::cout << "\nstack T: "; printStack(s);
    std::cout << "\nThe stack is: "; printStack_fromBottom(s);
    std::cout << "\nHapy Coding";
    
    free(s);
}
