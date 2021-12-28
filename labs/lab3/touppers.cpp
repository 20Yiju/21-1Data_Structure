//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. Signed: 정이주[이름] Student Number: 정이주 [학번] 22000690

// Topic: Using a reference varaible
// 
// The C/C++ language do offer a function, `toupper()` to convert a character
// to an uppercase, but not for a word or a string. Write a function called 
// `touppers()` that converts a string to all uppercases in place where it 
// does not require extra memory. 
//  - Use a skeleton file, `touppers.cpp`, provided. 
//  - Use a reference variable and `toupper()`, but not functions in <algorithm>.
// 
// 2021/02/10   created by idebtor@gmail.com
// 

// Sample Run:
//  > g++ touppers.cpp -o touppers
//  > ./touppers
//  > Enter words: Hello Mr. Kim
//  > HELLO MR. KIM
//
#include <iostream>

//////////////////////////////////////////////////////////////////////////////
// Define touppers() here that converts an input arguments into all uppercases
void touppers(std::string & str){
    char ch[50];
    strcpy(ch, str.c_str());

    for(int i = 0; i < strlen(ch); i++){
        if ((ch[i] >= 'a') && (ch[i] <= 'z')){
            ch[i] = toupper(ch[i]);
        }
    }
    std::string str1(ch);
    str = str1;
}


///////////////////// your code above ////////////////////////////////////////
int main() {
    std::string str;
    std::cout << "Enter words: ";
    std::getline(std::cin, str);

    touppers(str);

    std::cout << str << std::endl;
}
