//In my honor, I pledge that I have neither received nor provided improper assistance in the completion of this programming assignment. 
//Signed: JungYijuStudent Number: 2000690 
//Quiz1.
//1. 반으로 나누었을 떄, 왼쪽과 오른쪽이 잘 sort되었는지 assert를 통해서 한번 확인할 수 있는 코드를 작성하면 개선할 수 있습니다.
//2-1: 15
//2-1: 3
//3: ES & OR & MP -> 3
//Quiz2.
//1: 최종적으로 하나로 합쳤을 때 맨앞의 값과 맨 마지막의 값을 비교한다. a[lo]와 a[hi] (ex.1과 8)
//2: 넵! 충분합니다. sorting 과정을 통해서 이미 sort과 되었기에 마지막엔 맨앞과 뒤만 확인하여도 sort가 잘되었는지 체크할 수 있기 떄문입니다.
#include <iostream>
#include <cassert>
using namespace std;

int isSorted(char *a, int i, int j) {return a[i] <= a[j];}

void merge(char *a, char *aux, int lo, int mi, int hi) {
    assert(isSorted(a, lo, mi)); 
    assert(isSorted(a, mi+1, hi)); 
    for (int k = lo; k <= hi; k++) aux[k] = a[k];

    int i = lo;
    int j = mi + 1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mi)          a[k] = aux[j++];
        else if (j > hi)          a[k] = aux[i++];
        else if (aux[j] < aux[i]) a[k] = aux[j++];
        else                      a[k] = aux[i++];
    }
    assert(isSorted(a, lo, hi)); 
}

void mergeSort(char *a, char *aux, int N, int lo, int hi) {
    if (hi <= lo) return;
    int mi = lo + (hi - lo) / 2;           // mi=(lo+hi)/2 
    mergeSort (a, aux, N, lo, mi);
    mergeSort (a, aux, N, mi + 1, hi);

    if ((isSorted(a, mi, mi + 1)) == 0){
        merge(a, aux, lo, mi, hi);
    }
    
    
  
    
}

int main() {
    char a[]={'M','E','R','G','E','S','O','R','T','E','X','A','M','P','L','E'}; 
    
    cout << "UNSORTED: "; 
    for (auto x: a) 
        cout << x; 
    cout << endl;

    int N = sizeof(a) / sizeof(a[0]);
    char *aux = new char[N];

    mergeSort(a, aux, N, 0, N - 1);
    cout << "  SORTED: "; 
    for (auto x: a) 
        cout << x << " "; 
    cout << endl;
}

