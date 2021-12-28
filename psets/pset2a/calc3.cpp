//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//Signed: ___Jung Yiju___ Student Number: ___22000690______
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int add(int a, int b) {return a + b;}
int mul(int a, int b) {return a * b;}
int sub(int a, int b) {return a - b;}
int dvd(int a, int b) { if (b != 0) return a / b; else return 0; }

int get_int(){
    int x;
    do{
        cout << "Enter an integer: ";
        string str;
        getline(cin, str);
        try{
            x = stoi(str);
            break;
        }
        catch (invalid_argument& e){
            cerr << e.what() << "error occurred. Retry~" << endl;
        }
    }while(true);
    return x;
}

char get_op(map<char, int(*)(int,int)> fp_map) {
    string opstr;
    char op;
    for (auto x: fp_map) opstr += x.first;

    do {
        cout << "Enter an operator( " << opstr << "): ";
        stringstream ss;
        string str;
        getline(cin, str);
        ss << str;
        ss >> op;
        if (opstr.find(op) != string::npos) break;
    }while (true);
    return op;
}

int main() {
    map<char,int(*)(int,int)> fp_map; 
    fp_map.insert(make_pair('+', add));
    fp_map.insert(make_pair('-', sub));
    fp_map.insert(make_pair('*', mul));
    fp_map.insert(make_pair('/', dvd));

    int a { get_int() };
    char op { get_op(fp_map) };
    int b { get_int() };


    
    cout << a << op << b << '=' << (fp_map[op])(a,b) << endl;
    return 0;
}