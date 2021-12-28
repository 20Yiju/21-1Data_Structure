// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <stack>
#include <cassert>
#include <cctype>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom. 
template<typename T>
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


// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens) {
	stack<string> st;

	for (char token : tokens) {
		
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);
		
		// current token is a value(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			assert (st.size() >= 2);
			string value1 = st.top();
			st.pop();
			string value2 = st.top();
			st.pop();
			string result = ("(" + value2 + " " + token + " " + value1 + ")" );
			st.push(result);
			
		}

		
		else {  // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack
			string stoken(1, token);
			st.push(stoken);
			
		}
	}

	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	assert (st.size() == 1);
	DPRINT(cout << "stack size() should be 1.\n";);


	DPRINT(cout << "<evaluate() returns " << st.top() << endl;);
	return st.top();
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and 
// digits (0 ~ 9), false otherwise.
bool is_numeric(string tokens) {
	
	if(isdigit(tokens[0])){
		return true;
	}
	return false;
	
	
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens) {
	stack<double> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			// checking the stack top() for right operand 
			// checking the stack top() for left oprand 
			// compute the expression and push the result
			assert (st.size() >= 2);
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			double result;
			if (token == '+'){
				result = a + b;
			}
			else if (token == '-') {
				result = b - a;
			}
			else if (token == '*') {
				result = a * b;
			}
			else if (token == '/') {
				result = b / a;
			}
			st.push(result);

			
		}
		else { // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack
			double a = atof(&token);
			st.push(a);


	
		}
	}
	assert (st.size() == 1);

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
	DPRINT(printStack(st););

	
	double expr = st.top();

	DPRINT(cout << "<evaluate() returns " << expr << endl;);
	return expr;
}
