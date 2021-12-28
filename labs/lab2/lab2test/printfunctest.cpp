// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include<vector>
using namespace std;

void printfunc(int n, char *names[]) {
	for (int i = 1; i < n; i++)
		cout << "Hello " << names[i] << "!" << endl;
}

void printfunc(vector<string> &n) {
    for (int i = 0; i < n.size(); i++)
        cout << "Hello " << n[i] << "!" << endl;
}
