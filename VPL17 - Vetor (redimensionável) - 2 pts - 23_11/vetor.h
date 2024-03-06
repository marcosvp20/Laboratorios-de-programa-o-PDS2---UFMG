#ifndef VETOR_H_
#define VETOR_H_

#include <iostream>
using namespace std;

#include <string>

using std::string;
template <typename Tipo>

// Define um vetor cujos índices variam em
// qualquer intervalo, inclusive negativos.
class Vetor
{
public:
  // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
  // O valor associado aos índices é indefinido.
  // PRECONDIÇÃO: fim >= inicio.
  Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim)
  {
    elementos_ = new Tipo[fim - inicio + 1];
  }

  // Redimensiona o vetor de forma que os índices passam a variar
  // de 'inicio2' até 'fim2'.
  // O valor associado aos índices que estão na interseção de
  // [inicio_, fim_] e [inicio2, fim2], não se alteram.
  // Já o valor dos demais índices é indefinido.
  // PRECONDIÇÃO: fim2 >= inicio2.
  void Redimensionar(int inicio2, int fim2)
  {
    int novoTamanho = fim2 - inicio2 + 1;
    Tipo *novoElemento = new Tipo[novoTamanho];

    for (int i = max(inicio_, inicio2); i <= min(fim_, fim2); ++i)
    {
      novoElemento[i - inicio2] = elementos_[i - inicio_];
    }

    delete[] elementos_;

    inicio_ = inicio2;
    fim_ = fim2;
    elementos_ = novoElemento;
  }

  // Retorna uma referência a variável correspondente ao índice i.
  // Pode ser utilizado tanto para atribuir quanto para acessar valores.
  // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
  Tipo &operator[](int indice)
  {

    int indiceNovo = indice - inicio_;

    if (indiceNovo >= 0 && indiceNovo <= fim_ - inicio_)
    {
      return elementos_[indiceNovo];
    }
  }

  // Desaloca a memória reservada para os elementos do vetor.
  ~Vetor()
  {
    delete[] elementos_;
  }

private:
  int inicio_;      // Primeiro índice válido do vetor.
  int fim_;         // Último índice válido do vetor.
  Tipo *elementos_; // Elementos do vetor.
};

#endif