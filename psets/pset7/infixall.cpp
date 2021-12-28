// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0    //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack {
    vector<T> item;

    bool empty() const {
        return item.empty();
    }
    auto size() const {
        return item.size();
    }
    void push(T const& data) {
        item.push_back(data);
    }
    void pop() {
        if (item.empty())
            throw out_of_range("stack<>::pop(): pop stack");
        item.pop_back();
    }
    T top() const {
        if (item.empty())
            throw out_of_range("stack<>::top(): top stack");
        return item.back();
    }
};
#else  /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
void printStack(stack<T> orig) {
    stack <T> temp;
    if (orig.empty() == 0){
        T elem;
        elem = orig.top();
        orig.pop();
        printStack(orig);
        temp.push(elem);
    }
    
    if (temp.empty() == 0){
        T elem2;
        elem2 = temp.top();
        temp.pop();
        printStack(temp);
        cout << elem2 << ' ';
        orig.push(elem2);
    }
    return ;
}

// performs arithmetic operations.
double apply_op(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    }
    cout << "Unsupported operator encountered: " << op << endl;
    return 0;
}

// there is a bug...
double compute(stack<double>& va_stack, stack<char>& op_stack) {
    double right = va_stack.top(); va_stack.pop();
    double left  = va_stack.top(); va_stack.pop();
    char op = op_stack.top(); op_stack.pop();
    double value = apply_op(left, right, op);

    DPRINT(cout << " va/op_stack.pop: " << value << endl;);
    return value;
}
int intprecedence(char op){
    switch (op){
    case '(':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
            return 0;
    
    }
}

bool precedence(char op1, char op2){
    return intprecedence(op1) >= intprecedence(op2);
}


// returns value of expression after evaluation.
double evaluate(string tokens) {
    DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
    stack<double>  va_stack;              // stack to store operands or values
    stack<char> op_stack;                 // stack to store operators.
    double value = 0;

    for (size_t i = 0; i < tokens.length(); i++) {
        // token is a whitespace or an opening brace, skip it.
        if (isspace(tokens[i])) continue;
        DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);
        
        
        // current token is a value(or operand), push it to va_stack.
        if (isdigit(tokens[i])) {
            
            double ivalue = 0;
            int ind = i;
            
            do{
                ivalue = (ivalue * 10) + (tokens[ind] - '0');
                ind++;
                
            }
            while (tokens[ind] >='0' && tokens[ind] <= '9' );
            i = --ind;
            va_stack.push(ivalue);
            
        }
    
            

        else if (tokens[i] == ')') { // compute it, push the result to va_stack
            while(op_stack.top() != '('){
                double result = compute(va_stack, op_stack);
                va_stack.push(result);
            }
            if(op_stack.top() == '('){
                op_stack.pop();
            }

        }
        else if (tokens[i] == '(') {
            op_stack.push(tokens[i]);
        }
        
        else { // token is an operator; push it to op_stack.
            while( !op_stack.empty() && precedence(op_stack.top(), tokens[i])) {
                assert (va_stack.size() >= 2);
                double result = compute(va_stack, op_stack);
                va_stack.push(result);
                            
            }
            op_stack.push(tokens[i]);
        }
    }

    DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
    DPRINT(printStack(va_stack);  cout << endl;);
    DPRINT(printStack(op_stack);  cout << endl;);

    while (!op_stack.empty()) {
        double result = compute(va_stack, op_stack);
        va_stack.push(result);
    }
    

    //cout <<  post-conditions\n";
    /*if(va_stack.size() != 1 && op_stack.size() != 0){
        cout << "Error" << endl;
        return -1;
    }*/
    assert (va_stack.size() == 1);

    

    //cout << "your code here: return & clean-up\n";
    value = va_stack.top();

    return value;
}