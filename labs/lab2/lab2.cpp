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
#include "printfunc.h"
#include<string>

using namespace std;

int main(int argc, char *argv[]) {
    int a;
    string f, s, t;
    
    cin >> f >> s >> t;
    
    cout << "Print **argv using printfunc(**argv) except 1st one\n";
    
    char chf[10], chs[10], cht[10];
    
    strcpy(chf, f.c_str());
    strcpy(chs, s.c_str());
    strcpy(cht, t.c_str());
    
    char n[3];
    
    
    vector<string> names;
    names.push_back(f);
    names.push_back(s);
    names.push_back(t);
    
    a = names.size();

   
    // copy **argv to a `vector<string> names;` except 1st one.
    // use push_back() method in the vector class
    cout << "Copy **argv using vector<string> except 1st one\n";
    cout << "Print using indexing, but not ranged-for\n";

    for(int i = 0; i < a; i++){
        cout << "Hello " << names[i] << "!" << endl;
    }

    // print names only using for-loop and names
    // do not use argc/argv and ranged-for loop
    cout << "Print names using printfunc(vector<string>)\n";
  
    printfunc(names);

    // print names using printfunc(vector<string>)
    // use ranged-for loop in printfunc(vector<string>)
    // do not use `using namespace std;` in printfunc.cpp
    // cout << "Print names using printfunc(vector<string>)\n";
    // printfunc(names);

    return 0;
}
