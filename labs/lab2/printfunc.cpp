//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. Signed: 정이주[이름] Student Number: 정이주 [학번] 22000690

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include <vector>


void printfunc(int n, char *names[]) {
	for (int i = 1; i < n; i++)
		std::cout << "Hello " << names[i] << "!" << std::endl;
}

void printfunc(std::vector<std::string> &n) {
    for (int i = 0; i < n.size(); i++)
        std::cout << "Hello " << n[i] << "!" << std::endl;
}



 