//On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//Signed: ___Jung Yiju____ Student Number: __22000690____
/*
* file: hellowho.cpp
* * * * * * * * * *
It prints "Hello World!" or "Hello" with a given name.
The completed code should work as shown below. “>” is a prompt of the console.
To run the program without a command line argument: > ./hello
> Enter a name: John Lee
> Hello John Lee!
  > Enter a name: Peter Kim
  > Hello Peter Kim!
  > Enter a name:<Enter>
* > Hello World! *>
*
* To run the program with a command line argument:
* > ./hello John "Dr. Lee" "Handong Global University" peter
*   > Hello John!
* >
* >
* >
* > Hello World! *>
Hello Dr. Lee!
Hello Handong Global University!
Hello peter!
* To run the program through a pipe
* (names.txt contains a list of names as shown below:)
*   > cat names.txt | ./hello
*   > Enter a name: Hello john!
*   > Enter a name: Hello Dr. Lee!
* > Enter a name: Hello Handong Global University!
*   > Enter a name: Hello Peter!
*   > Enter a name: Hello World!
*
* 2020/02/10: Created, idebtor@gmail.com
*   2020/12/15: working in vs code
*/
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv) {
  // Use setvbuf() to prevent the output from buffered on console. 
  // setvbuf(stdout, NULL, _IONBF, 0);
  string name;
  if(argc == 1){
    while(1){
      cout << "Enter a name: ";
      getline(cin, name);
      if(name == ""){
        cout << "Hello World!\n";
        break;
      }
      else{
        cout << "Hello " << name << "!\n";
      }

    }

  }
  else{
    for (int i = 1; i < argc; i++){
      cout << "Hello "<< argv[i] << "!\n";
    }  
    cout << "Hello World!\n";

  }
  

  // Use system("pause") to prevent the terminal from disappearing
  // as soon as the program terminates as in Visual Studio sometimes.
  // system("pause");
  return EXIT_SUCCESS;
}