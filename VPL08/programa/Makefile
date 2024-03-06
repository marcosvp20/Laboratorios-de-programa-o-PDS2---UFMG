vpl_execution: build/Pessoa.o build/Funcionario.o build/Professor.o build/main.o
	c++ build/main.o build/Pessoa.o build/Funcionario.o build/Professor.o -o vpl_execution

build/Pessoa.o: src/entidades/Pessoa.cpp include/Pessoa.hpp
	c++ -c src/entidades/Pessoa.cpp -I include/ -o build/Pessoa.o

build/Funcionario.o: src/entidades/Funcionario.cpp include/Funcionario.hpp
	c++ -c src/entidades/Funcionario.cpp -I include/ -o build/Funcionario.o

build/Professor.o: src/entidades/Professor.cpp include/Professor.hpp
	c++ -c src/entidades/Professor.cpp -I include/ -o build/Professor.o

build/main.o: src/main.cpp include/Pessoa.hpp include/Funcionario.hpp include/Professor.hpp
	c++ -c src/main.cpp -I include/ -o build/main.o
