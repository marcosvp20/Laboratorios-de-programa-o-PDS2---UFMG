main: main.o Estoque.o
	c++ -std=c++20 -g main.o Estoque.o -o main
Estoque.o: Estoque.cpp Estoque.hpp
	c++ -std=c++20  -c -g Estoque.cpp -o Estoque.o
main.o: Estoque.hpp main.cpp
	c++ -std=c++20 -c -g main.cpp -o main.o