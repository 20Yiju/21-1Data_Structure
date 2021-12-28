#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <string>

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

int dialtime(string str){
    int result = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '-') {
            continue;
        }
        else if(str[i] < 'A'){
            str[i] = '-';
        }
    }
    dialnum(str);
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '-') {
            continue;
        }
        else{
            int a = 0;
            a = str[i] - '0';
            result += (a + 1);
        }
    }
    return result;
}
    
    
int main() {
    int val;
    
    map<string, int> dial;
    vector<string> list = { "COLLECT", "FLOWERS", "POPCORN", "1-800-GO-FED-EX"};
    for (auto x: list) {
        string b = x;
        val = dialtime(x);
        dial.insert(make_pair(b, val));
    }
    for (map<string, int>::iterator it = dial.begin(); it != dial.end(); ++it)
        cout << (*it).first << ": " << (*it).second << endl;
    
    while(1) {
        int va;
        string str;
        string c;
        cout << "\nEnter 1-800-XXXXXXX to convert or q to quit: ";
        getline(cin, str);
        c = str;
        if (str.front() == 'q') return 0;
        
        va = dialtime(str);
        dial.insert(make_pair(c, va));
        cout << va << endl;
    }
}
