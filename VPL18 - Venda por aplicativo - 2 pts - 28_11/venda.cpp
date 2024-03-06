#include "venda.hpp"
#include <iomanip>
using namespace std;
Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  float total = 0.00;
  int qnt = 0;
  int pedido = 1;
  for(auto it = m_pedidos.begin(); it != m_pedidos.end(); it++){
    std::cout << "Pedido " << pedido << endl << (*it)->resumo() << std::endl;
    total += (*it)->calculaTotal();
    qnt++;
    pedido++;
  }
  std::cout << "Relatorio de vendas" << endl;
  std::cout << std::fixed << std::setprecision(2) << "Total de vendas: R$" << total << endl;
  std::cout<< "Total de pedidos: " << qnt << endl;
}