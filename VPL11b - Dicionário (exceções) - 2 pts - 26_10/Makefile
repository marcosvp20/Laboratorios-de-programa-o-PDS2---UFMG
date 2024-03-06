main: main.o dicionario.o
	c++ -g main.o dicionario.o -o main

main.o: dicionario.h
	c++ -c -g main.cpp -o main.o

dicionario.o: dicionario.h dicionario.cpp
	c++ -c -g dicionario.cpp -o dicionario.o

teste:
	./main < teste.txt > saida.txt