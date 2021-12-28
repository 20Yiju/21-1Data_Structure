// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <vector>
using namespace std;

void dialnum(string& str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '-') {
            continue;
        }
        else if(str[i] < 'A'){
            continue;
        }
        else{
            str[i] = toupper(str[i]);
            int a = 0;
            a = int(str[i]);
            if(64 < a && a < 68){
                str[i] = '2';
            }
            else if(67 < a && a < 71){
                str[i] = '3';
            }
            else if(70 < a && a < 74){
                str[i] = '4';
            }
            else if(73 < a && a < 77){
                str[i] = '5';
            }
            else if(76 < a && a < 80){
                str[i] = '6';
            }
            else if(79 < a && a < 84){
                str[i] = '7';
            }
            else if(83 < a && a < 87){
                str[i] = '8';
            }
            else if(86 < a && a < 91){
                str[i] = '9';
            }
        }
    }
    
}
int main() {
    vector<string> list = { "1-800-COLLECT", "1-800-FLOWERS", "1-800-taxicab", "1-800-POPCORN",
        "1-800-red-ross", "1-800-new-cars", "1-800-JET-BLUE", "1-800-GO-FED-EX" };
    for (auto x: list) {
        cout << x;
        dialnum(x);
        cout << ": " << x << endl;
    }

    while(1) {
        string str;
        cout << "Enter 1-800-XXXXXXX to convert or q to quit: ";
        getline(cin, str);
        if (str.front() == 'q') return 0;
        std::cout << str;
        dialnum(str);
        cout << ": " << str << endl;
    }
}
