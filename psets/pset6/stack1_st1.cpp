// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printStack_fromBottom(stack<string> s) {
    if (s.empty()) return;
    string elem = s.top();
    s.pop();
    printStack_fromBottom(s);
    cout << elem << ' ';
    s.push(elem);
}

void printStack(stack<string> s) {
    if (s.empty()) return;
    string elem = s.top();
    cout << elem << ' ';
    s.pop();
    printStack(s);
    s.push(elem);
}

int main() {
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack <string> s;
    for (auto item : list) {
        if (item != "-"){
            s.push(item);
        }
        else {
            cout << s.top() << ' ';
            s.pop();
        }
    }
        
    
    cout << "\nsize(): " << s.size();
    cout << "\ntop(): " << s.top();
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);
    cout << "\nHapy Coding";
}
