main: hamburguer.o japonesa.o pizza.o produto.o pedido.o venda.o main.o util.o
	c++ -g hamburguer.o japonesa.o pizza.o produto.o pedido.o venda.o util.o main.o -o teste1
hamburguer.o: hamburguer.cpp hamburguer.hpp produto.hpp
	c++ -c -g hamburguer.cpp -o hamburguer.o
japonesa.o: japonesa.cpp japonesa.hpp produto.hpp
	c++ -c -g japonesa.cpp -o japonesa.o
pizza.o: pizza.cpp pizza.hpp produto.hpp
	c++ -c -g pizza.cpp -o pizza.o
produto.o: produto.cpp produto.hpp
	c++ -c -g produto.cpp -o produto.o
pedido.o: pedido.cpp pedido.hpp
	c++ -c -g pedido.cpp -o pedido.o
venda.o: venda.cpp venda.hpp
	c++ -c -g venda.cpp -o venda.o
main.o: venda.hpp util.hpp
	c++ -c -g main.cpp -o main.o
util.o: pedido.hpp 
	c++ -c -g util.cpp -o util.o	