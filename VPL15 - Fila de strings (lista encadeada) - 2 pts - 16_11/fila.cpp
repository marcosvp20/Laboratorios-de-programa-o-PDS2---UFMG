#include "fila.h"
using namespace std;

Fila::Fila()
{
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}

string Fila::primeiro()
{
    return (*primeiro_).chave;
}
string Fila::ultimo()
{
    return (*ultimo_).chave;
}
bool Fila::vazia()
{
    if(primeiro_ == nullptr)
    {
        return true;
    }
    return false;
}
void Fila::Inserir(string k)
{
   No* novoNo = new No{k, nullptr};
    if (primeiro_ == nullptr) {
        primeiro_ = novoNo;
        ultimo_ = novoNo;
    } else {
        ultimo_->proximo = novoNo;
        ultimo_ = novoNo;
    }
}

void Fila::Remover()
{
    auto aux = primeiro_;
    primeiro_ = primeiro_->proximo;
    delete aux;
}
int Fila::tamanho()
{
int contador = 0;
    No* aux = primeiro_;
    while (aux != nullptr) {
        contador++;
        aux = aux->proximo;
    }
    return contador;
}
Fila::~Fila()
{
while (primeiro_ != nullptr)
{
    auto aux = primeiro_;
    primeiro_ = primeiro_->proximo;
    delete aux;
}

}