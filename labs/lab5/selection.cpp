// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
// 
// selection sort 
// The selection sort improves on the bubble sort by making only one exchange 
// for every pass through the list. In order to do this, a selection sort 
// looks for the largest value as it makes a pass and, after completing the 
// pass, places it in the proper location. As with a bubble sort, after the 
// first pass, the largest item is in the correct place. After the second pass, 
// the next largest is in place. This process continues and requires n−1 passes 
// to sort n items, since the final item must be in place after the (n−1)st pass.
// Its time complexity is O(n^2).
//
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 selection.cpp -o selection
// > ./selection
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG selection.cpp -o selection
// > ./selection
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c selection.cpp      # produce selection.o
// > ar r libsort.a selection.o           # insert or update selection.o in libsort.a
// > ar t libsort.a                       # show objects in libsort.a 
//
/******************************************************************************
  Lab05 - Understanding a better coding in C/C++
  - NMN(No magic number)
  - DRY(Don't repeat yourself)
  - Use new and delete instead of malloc(), free()
  - Use assert() after new to check the memory allocation status
  - rand() and mod operator % 
  - Learn about a better coding after all.
*******************************************************************************/
//On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//Signed: ___Jung Yiju____ Student Number: __22000690____
#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert> 


using namespace std;



void printlist(int *list, int n, int show_n = 20, int per_line = 10);

#if 1
// two comparator functions 
// The value returned indicates whether the element passed as first argument
// is considered to go before the second in the specific ordering.
// more() and less() are equivalent to greater<int>() and less<int>() in STL. 
bool more(int x, int y) { return x > y; }   // for descending order
bool less(int x, int y) { return x < y; }   // for ascending order 

void selectionsort(int *list, int n, bool (*comp)(int x, int y) = ::less) {
  for (int i = 0; i < n; i++) {   
    int min = i;
    for (int j = i + 1; j < n; j++)
      if ((*comp)(list[j], list[min])) min = j;
    int temp = list[i];
    list[i] = list[min];
    list[min] = temp;
  }
}


int main(int argc, char *argv[]) {
  //int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8 };
  //int n = sizeof(list) / sizeof(list[0]);
  int n = 0;
  while (n <= 1) {
    cout << "Enter a number of samples to sort(q to quit): ";
    char str[100];
    cin.getline(str, 100);
    if((strcmp(str, "q")) == 0){
      break;
    }    
    else if(atoi(str) <= 0){
      
      cout << "Retry -\n";
    } 

    else if(atoi(str) > 0){
      int i = atoi(str);
      int *list = new int[i];
      assert(list != nullptr);

      for(int j = 0; j < i; j++){
        list[j] = (rand() % i);
      }
      // use printlist() to show the list initialized
      cout << "UNSORTED(" << i <<"):\n";
      printlist(list, i);

      // ascending order 
      selectionsort(list, i);
      cout << "SORTED(" << i << "):\n";
      printlist(list, i);

      // descending order using more() fp.
      selectionsort(list, i, more);
      cout << "SORTED(" << i << "): descending using fp\n";
      printlist(list, i);

      // deallocate *list

      cout << "Happy Coding~~\n";
      delete[] list;
      break;
    }
  
    else{
      cout << "Retry -\n";
    }
  }
  return 0;
}
  

#endif 
