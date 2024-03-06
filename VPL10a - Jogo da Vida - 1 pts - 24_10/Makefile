main: main.o jogo_da_vida.o
	g++ -g main.o jogo_da_vida.o -o main

jogo_da_vida.o: jogo_da_vida.cpp jogo_da_vida.h
	g++ -c -g jogo_da_vida.cpp -o jogo_da_vida.o

main.o: main.cpp jogo_da_vida.h
	g++ -c -g main.cpp -o main.o
teste:
	./main < teste.txt > saida.txt