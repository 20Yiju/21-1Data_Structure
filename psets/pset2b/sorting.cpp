//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//Signed: ___Jung Yiju___ Student Number: ___22000690______

#include <ctime>
#include <cassert>
#include <iostream>
#include <sstream>
#include <map>
#include "nowic.h"
#include "sort.h"
#include "rand.h"
using namespace std;

// shuffles the sequence randomly. 
// For every sample, starting from the first element in the list, it is swapped with 
// the element randomly selected by the index generated by a 'real' (not pseudo) 
// random number out of from 0 to N - 1.
// Hint: Refer to rand() and srand() function document, random.pdf provided.
void randomize_bruteforce(int list[], int n) {
	for (int i = 0; i < n; i++){
		list[i] = i;
		int r = rand() % n;
		swap(list[i], list[r]);
	}
        
}

void show_timeit(int begin) { 	// display elapsed time
	cout << "\tcpu: " << ((double)clock() - begin) / CLOCKS_PER_SEC << " sec\n";
}
void printlist(int *list, int N, int show_n, int per_line);

// sort driver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	char choice;
	int keyin;
	clock_t begin;
	int show_n = 20;					// the total number of samples to show
	int per_line = 10;					// the number of samples per line to show

	int N = 50;							// a magic number - initial number of samples
	int *list = new (nothrow) int[N];   // create a list 
	assert(list != nullptr);
	for (int i = 0; i < N; i++) list[i] = i;

	// Declare a comparator function pointer 'comp_fp' variable and initialize 
	// it with an ascending order comparator function, '::less'.
    bool (*comp_fp)(int, int) = ::less;       	// declare comp_fp

	// Declare a sort function pointer variable 'sort_fp' and initialize it 
	// with a sort function, 'bubblesort': 
    void (*sort_fp)(int *list, int n, bool (*comp_fp)(int, int)) = bubblesort ;		// declare sort_fp

	///////////////////////////////////////////////////////////////////////////////
	// Two STL maps are used for showing the current status of user's selections.
	// comp_map[xxx_fp] contains one of sorting-orders, "Ascending" or "Descending".
	// sort_map[xxx_fp] contains one of sorting algorithms. 
	///////////////////////////////////////////////////////////////////////////////
	
	// Define a STL map variable 'comp_map' to associate the comparator 
	// function pointer with a description such as "Ascending" and "Descending", 
	// respectively.
    map<bool(*)(int, int), string> comp_map;
    comp_map.insert(make_pair(::less, "Ascending"));
    comp_map.insert(make_pair(more, "Descending"));

	// Define a STL map variable 'sort_map' to associate <key_type, value_type> pair,  
	// where key_type is sort fp and value_type is a description of the sort name.
    map<void(*)(int *, int, bool (*)(int, int)), string> sort_map;
    sort_map.insert(make_pair(bubblesort, "Bubble"));
    sort_map.insert(make_pair(insertionsort, "Insertion"));
	sort_map[mergesort] = "Merge";
    sort_map.insert(make_pair(quicksort, "Quick"));
    sort_map.insert(make_pair(selectionsort, "Selectionsort"));
	///////////////////////////////////////////////////////////////////////////////

	setvbuf(stdout, NULL, _IONBF, 0);  	// prevent output from buffered on console

	do {
		printlist(list, N, show_n, per_line);
		stringstream ss;
        ss << "\tMENU[ sort=" << sort_map[ sort_fp ] << " order=" << comp_map[ comp_fp ] ;
		ss << " N=" << N << " show_n=" << show_n << " per_line=" << per_line << " ]";
		cout << ss.str() << endl;
		cout << "\tB - Bubblesort\t" 		<< "\tn - set N samples and initialize\n"; 
		cout << "\tI - Insertionsort"	 	<< "\tr - randomize(shuffle) samples\n";
		cout << "\tM - Mergesort\t"			<< "\tm - max samples to show: show_n\n";
		cout << "\tQ - Quicksort\t" 		<< "\tl - max samples to show: per_line\n";
		cout << "\tS - Selectionsort"		<< "\to - order[Ascending/Descending]\n";	
		cout << "\t\t\t"					<< "\ts - sort()\n";
		choice = GetChar("\tCommand(q to quit): ");


		switch (choice) {
		case 'B':
            sort_fp = bubblesort;
			break;
		case 'I':
            sort_fp = insertionsort;
			break;
		case 'M':
            sort_fp = mergesort;
			break;
		case 'Q':
            sort_fp = quicksort;
			break;
		case 'S':
            sort_fp = selectionsort;
			break;

		case 'n': {
			keyin = GetInt("\tEnter sample size N: ");
			if (keyin <= 1) {
				cout << "\tExpecting a number greater than 1\n";
				break;
			}
			delete[] list;
            N = keyin;
            list = new (nothrow) int[N];
            assert(list != nullptr);
            for (int i = 0; i < N; i++) {
				list[i] = i;
            }
            
			// set N with the new keyin value
			// before allocating the new list, free the old list if not NULL
			// allocate memory for new data samples
			// Fill the list with numbers from 0 to n - 1.
	
			break;
		}


		case 'r': 
			#if 1
			randomize_bruteforce(list, N);
			#else
			randomize(list, N);
			#endif
			break;

		case 'm': {
			keyin = GetInt("\tEnter max samples to show: ");
            show_n = keyin;
			break;
		}


		case 'l': {
			keyin = GetInt("\tEnter max samples per line: ");
            per_line = keyin;
			break;
		}

		
		case 'o': {
            comp_fp = (comp_fp == ::less) ? more : ::less;		
			break;
		}


		case 's': {
			begin = clock();
            (sort_fp)(list, N, comp_fp);
			show_timeit(begin); 
			break;			
		}


		default:
			break;
		}
	} while (choice != 'q');
	
	

//    printlist(list, N, show_n, per_line);
	

	cout << "\tHappy Coding~~";
	return EXIT_SUCCESS;
}