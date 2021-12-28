// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <string>

using namespace std;

map<char, int> dialnum { pair<char,int>('A', 2), pair<char,int>('C', 2), make_pair('B', 2), make_pair('D', 3), pair<char,int>('E', 3), pair<char,int>('F', 3), pair<char,int>('G', 4), pair<char,int>('H', 4), pair<char,int>('I', 4), pair<char,int>('J', 5), pair<char,int>('K', 5), pair<char,int>('L', 5), pair<char,int>('M', 6), pair<char,int>('N', 6), pair<char,int>('O', 6), pair<char,int>('P', 7), pair<char,int>('Q', 7), pair<char,int>('R', 7), pair<char,int>('S', 7), pair<char,int>('T', 8), pair<char,int>('U', 8), pair<char,int>('V', 8), pair<char,int>('W', 9), pair<char,int>('Y', 9), pair<char,int>('X', 9), pair<char,int>('Z', 9) };

int dialtime(string x){
    int val = 0;
    for(int i = 0; i < x.size(); i++){
        x[i] = toupper(x[i]);
        if( dialnum.find(x[i]) == dialnum.end() ) {
            continue;
        }
        val += ( dialnum[x[i]] + 1 );
    }
    return val;
}
    
int main() {
    int count = 1;
    vector<string> list = { "COLLECT", "FLOWERS", "POPCORN","1-800-GO-FED-EX" };
    for (auto x: list) {
        if(count == list.size()){
            cout << x << ": " << dialtime(x) << endl;
        }
        else{
            cout << x << ": " << dialtime(x) << ", ";
        }
        count += 1;
    }
    while(1) {
        string str;
        cout << "Enter a word[upto 15 chars] or q to quit: ";
        getline(cin, str);
        if (str.front() == 'q') return 0;
        cout << dialtime(str) << endl;
        
    }

    
}
