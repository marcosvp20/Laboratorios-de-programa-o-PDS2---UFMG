main: vetor.o main.o
	c++ vetor.o main.o -o main

vetor.o: vetor.h vetor.cpp
	c++ -c -g vetor.cpp -o vetor.o
main.o: vetor.h main.cpp
	c++ -c -g main.cpp -o main.o