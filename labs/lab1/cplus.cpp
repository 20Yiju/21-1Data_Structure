//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. Signed: 정이주[이름] Student Number: 정이주 [학번] 22000690

#if 0
#include <stdio.h>
#define N 40

void sum(int d[], int n, int* p) {
    *p = 0;
    for(int i = 0; i < n; ++i)
        *p = *p + d[i];
}

int main(int argc, char *argv[]) {
    int total = 0;
    int data[N];
    

    for(int i = 0; i < N; ++i)
        data[i] = i;
    
    sum(data, N, &total);  // total - pass-by-pointer
    printf("Total is %d\n", total);
    return 0;
}
#else
#include <iostream>


const int N = 40;

void sum(int d[], int n, int &p){
    p = 0;
    for(int i = 0; i < N; i++)
        p = p + d[i];
    
}

int main(int argc, char *argv[]) {
    int total = 0;
    
    int *data;
    data = new int[N];
    
    for(int i = 0; i < N; ++i)
        data[i] = i;
    
    sum(data, N, total);
    

    std::cout << "Total is " << total << std::endl;
    delete[]data;

    return 0;
}
#endif