qsort: quick.o comparator.o printlist.o
	g++ -std=c++11 quick.o comparator.o printlist.o -o qsort
quick.o: quick.cpp
	g++ -std=c++11 -c quick.cpp -I../include
comparator.o: comparator.cpp
	g++ -std=c++11 -c comparator.cpp 
printlist.o: printlist.cpp
	g++ -std=c++11 -c printlist.cpp
clean:
	rm –f *.o qsort.exe qsort               