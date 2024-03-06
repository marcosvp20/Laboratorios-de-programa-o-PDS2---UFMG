#include "vetor.h"
#include <iostream>

using namespace std;

Vetor::Vetor(int inicio, int fim)
{
    elementos_ = new string[(fim - inicio)+1];
    inicio_ = inicio;
}

void Vetor::atribuir(int i, string valor)
{
    int tamanho = (inicio_ - i);
    if(tamanho < 0)
    {
        tamanho *= -1;
    }
    elementos_[tamanho] = valor;
}

string Vetor::valor(int i) const
{
    int tamanho = (inicio_ - i);
    if(tamanho < 0)
    {
        tamanho *= -1;
    }
    return elementos_[tamanho];
}

Vetor::~Vetor()
{
    delete []elementos_;
}