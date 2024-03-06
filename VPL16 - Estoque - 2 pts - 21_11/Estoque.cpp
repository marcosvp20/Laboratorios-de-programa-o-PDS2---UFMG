#include <string>
#include "Estoque.hpp"
#include <iostream>
using namespace std;

bool Estoque::contem(string a) const{
for(auto it = estoque_.begin(); it != estoque_.end(); it++){
  if(it->first == a){
    return true;
  }
}
return false;
}
void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  estoque_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  int aux = estoque_[mercadoria];
  aux -= qtd;
  estoque_[mercadoria] = aux;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  if(contem(mercadoria)){
    return estoque_.at(mercadoria);
  }
  return 0;
}

void Estoque::imprime_estoque() const {
  for(auto it = estoque_.begin(); it != estoque_.end(); it++){
    cout << it->first <<", " << it->second << endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
for(auto it = rhs.estoque_.begin(); it != rhs.estoque_.end(); it++){
    estoque_[it->first] += it->second;
}
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(auto it = rhs.estoque_.begin(); it != rhs.estoque_.end(); it++){
      estoque_[it->first] -= it->second;
  }
  
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  int contador = 0;
  int quantidade = 0;
  
  for(auto it = lhs.estoque_.begin(); it != lhs.estoque_.end(); it++){
    if(!rhs.contem(it->first)){
      contador++;
    }
  }

  if(contador > 0){
    return false;
  }

    for(auto it = lhs.estoque_.begin(); it != lhs.estoque_.end(); it++){
    if(!(rhs.estoque_.at(it->first) > it->second)){
      quantidade++;
    }
  }
  if(quantidade > 0){
  
  return false;
  }
  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
    int contador = 0;
  int quantidade = 0;

  for(auto it = rhs.estoque_.begin(); it != rhs.estoque_.end(); it++){
    if(!lhs.contem(it->first)){
      contador++;
    }
  }
  if(contador > 0){
    return false;
  }

    for(auto it = rhs.estoque_.begin(); it != rhs.estoque_.end(); it++){
    if(!(lhs.estoque_.at(it->first) > it->second)){
      quantidade++;
    }
  }

  if(quantidade > 0){
  return false;
  }
  return true;
}