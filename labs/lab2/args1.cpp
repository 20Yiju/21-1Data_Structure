//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. Signed: 정이주[이름] Student Number: 정이주 [학번] 22000690

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//    1. Using vector class in c++
//    2. ranged-for loop
//    3. function overloading
//    4. include file
//  5. not using `using namespace std;`

#include<iostream>
#include<vector>
#include<string>


void printfunc(int n, char *names[]);
void printfunc(std::vector<std::string> &names);


int main(int argc, char *argv[]) {
    
    std::cout << "Print **argv using printfunc(**argv) except 1st one\n";
    printfunc(argc, argv);

    std::vector<std::string> names;
    for(int i = 1; i < argc; i++){
        names.push_back(argv[i]);
    }
    
    
    // copy **argv to a `vector<string> names;` except 1st one.
    // use push_back() method in the vector class
    std::cout << "Copy **argv using vector<string>\n";
    std::cout << "Print using indexing, but not ranged-for\n";

    for(int i = 0; i < names.size(); i++){
        std::cout << "Hello " << names[i] << "!" << std::endl;
    }

    // print names only using for-loop and names
    // do not use argc/argv and ranged-for loop
    std::cout << "Print names using printfunc(vector<string>)\n";
    printfunc(names);



    // print names using printfunc(vector<string>)
    // use ranged-for loop in printfunc(vector<string>)
    // do not use `using namespace std;` in printfunc.cpp
    // cout << "Print names using printfunc(vector<string>)\n";
    // printfunc(names);

    return 0;
}
