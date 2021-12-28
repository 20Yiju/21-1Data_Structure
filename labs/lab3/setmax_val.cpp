//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. Signed: 정이주[이름] Student Number: 정이주 [학번] 22000690

#include<iostream>
#include<vector>
#include<cassert>

// gets the max value in the list and returns its index
int getmax(std::vector<int> vec) {
    assert(vec.size() > 0);
    auto max = vec[0];
    size_t idx = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if(max < vec[i]){
            max = vec[i];
            idx = i;
        }
    }
    return idx;
}

// sets the max value in the list to 99
void setmax(std::vector<int> vec) {
    size_t idx = getmax(vec);
    vec[idx] = 99;
}

// With a given list, find the max value, then set it to 99 in setmax()
// In main(), we do not see the max value change that was made in setmax(), 
// since functions are using pass-by-value on purpose.
// With a given list, find the max value, then set it to 99 in setmax()
// In main(), we do not see the max value change that was made in setmax(), 
// since functions are using pass-by-value on purpose.
int main(int argc, char *argv[]) {
    std::vector<int> list1 = {43, 10, 20, 75, 22, 33};
    std::vector<int> list2 = {33, 13, 45, 19, 39, 22};

    std::cout << ">list1: "; 
    for (auto x: list1) std::cout << x << " "; 
    std::cout << std::endl; 
    setmax(list1); 
    std::cout << "<list1: "; 
    for (auto x: list1) std::cout << x << " "; 
    std::cout << std::endl << std::endl;

    std::cout << ">list2: "; 
    for (auto x: list2) std::cout << x << " "; 
    std::cout << std::endl; 
    setmax(list2);
    std::cout << "<list2: "; 
    for (auto x: list2) std::cout << x << " "; 
    std::cout << std::endl; 

    return 0;
}

