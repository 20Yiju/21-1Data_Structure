// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <vector>
#include <stack>

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func);
#endif

struct Stack {
    std::vector<std::string> item;
};
using stack = Stack *;

stack newStack() {
    stack s = new Stack;
    return s;
}

void free(stack s) {
    delete s;
}

int size(stack s) { return s -> item.size(); }

void pop(stack s) {
    s->item.pop_back();
}
bool empty(stack s) { return s -> item.empty(); }

void push(stack s, std::string it) {
    /*if(s -> item.capacity() == s -> item.size()){
        s -> item.resize( 2 * (s->item.capacity()));
    }*/
    s -> item.push_back(it);
}

std::string top(stack s) {
    return s ->item.back();
}


void printStack_fromBottom(stack s) {
    if (empty(s)) return;
    std::string elem = top(s);
    pop(s);
    printStack_fromBottom(s);
    std::cout << elem << ' ';
    push(s, elem);
}

void printStack(stack s) {
    if (empty(s)) return;
    std::string elem = top(s);
    std::cout << elem << ' ';
    pop(s);
    printStack(s);
    push(s, elem);
}

int main() {
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    std::string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack s = newStack();



    for (auto item : list) {
        if (item != "-"){
            push(s, item);
            DPRINT(std::cout << "size:" << s -> item.size() << " capa:" << s->item.capacity() << std::endl);
        }
        else {
            std::cout << top(s) << ' ';
            pop(s);
        }
    }
    
    std::cout << "\ns.size: " << size(s);
    std::cout << "\ns.top: " << top(s);
    std::cout << "\nThe stack is: "; printStack(s);
    std::cout << "\nHappy Coding";
    
    free(s);
}

