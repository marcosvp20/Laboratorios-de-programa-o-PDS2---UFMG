#include "pizza.hpp"
#include <iostream>
using namespace std;

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos e sem borda recheada.
   */
  std::string aux = to_string(m_qtd) + "X Pizza " + sabor_ + ", " + to_string(pedacos_) + " pedacos e ";
  if(borda_recheada_){
    aux += "borda recheada.\n";
    return aux;
  }
  aux += "sem borda recheada.\n";
  return aux;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  // TODO: Implemente este metodo.
  sabor_ = sabor;
  pedacos_ = pedacos;
  borda_recheada_ = borda_recheada;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;

}