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

template<typename T>
struct Stack {
    std::vector<T> item;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack() {
    stack<T> s = new Stack<T>;
    return s;
}

template<typename T>
void free(stack<T> s) {
    delete s;
}

template<typename T>
int size(stack<T> s) { return s -> item.size(); }

template<typename T>
void pop(stack<T> s) {
    s->item.pop_back();
}

template<typename T>
bool empty(stack<T> s) { return s -> item.empty(); }

template<typename T>
void push(stack<T> s, T it) {
    /*if(s -> item.capacity() == s -> item.size()){
        s -> item.resize( 2 * (s->item.capacity()));
    }*/
    s -> item.push_back(it);
}

template<typename T>
T top(stack<T> s) {
    return s ->item.back();
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

    stack <std::string> s = newStack<std::string> ();


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


