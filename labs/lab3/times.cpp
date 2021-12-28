//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. Signed: 정이주[이름] Student Number: 정이주 [학번] 22000690

#include<iostream>
#include<vector>


#if 1
// mulitply even number elements in the list by 10
// without using reference variable.
int main(int argc, char *argv[]) {
    std::vector<int> list = { 0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10 };

    for (size_t i = 1; i < list.size(); i++) {
        if(list[i] % 2 ==0){
            list[i] = list[i] * 10;
        }
       
    }

    for (auto x: list) std::cout << x << " ";
    return 0;
}
#else
// mulitply even number elements in the list by 10
// using reference variable.
int main(int argc, char *argv[]) {
    std::vector<int> list = { 0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10 };
    std::vector<int>& ref = list; //자료형& 참조 변수명 = 변수명;

    for (size_t i = 1; i < list.size(); i++){
        if(ref[i] % 2 ==0){
            ref[i] *= 10;
        }
    } 
    

    for (auto x: list) std::cout << x << " ";
    return 0;
}
#endif
