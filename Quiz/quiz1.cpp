//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. 
//Signed: JungYiju[이름] Student Number: 2000690 [학번]

//Type of error: a logic error

#include <iostream>
using namespace std;

int main(){
    int *pi;
    pi = new int;
    *pi = 17;
    cout << "i = " << *pi <<endl;
    delete pi;
    return 0;
}