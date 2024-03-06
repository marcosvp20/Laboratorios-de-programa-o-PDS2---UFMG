main: main.o jogo_da_vida.o
	c++ -g main.o jogo_da_vida.o -o main
main.o: main.cpp jogo_da_vida.cpp
	c++ -c -g main.cpp -o main.o
jogo_da_vida.o: jogo_da_vida.h
	c++ -c -g jogo_da_vida.cpp -o jogo_da_vida.o

teste:
	./main < teste.txt > saida.txt
