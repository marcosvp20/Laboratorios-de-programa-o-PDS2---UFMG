#include "vetor.h"
#include <iostream>


using namespace std;


Vetor::Vetor(int inicio, int fim)
{
    if(fim < inicio)
    {
        throw IntervaloVazio {inicio, fim};
    }
    elementos_ = new string[(fim - inicio)+1];
    inicializado_ = new bool[(fim - inicio)+1];
    inicio_ = inicio;
    fim_ = fim;
}

void Vetor::atribuir(int i, string valor)
{
    if(i < inicio_ || i > fim_)
    {
        throw IndiceInvalido {inicio_, fim_, i};
    }
    int tamanho = (inicio_ - i);
    if(tamanho < 0)
    {
        tamanho *= -1;
    }
    elementos_[tamanho] = valor;
    inicializado_[tamanho] = true;
}
string Vetor::valor(int i) const
{
    if(i < inicio_ || i > fim_)
    {
        throw IndiceInvalido {inicio_, fim_, i};
    }

    int tamanho = (inicio_ - i);
    if(tamanho < 0)
    {
        tamanho *= -1;
    }
    if(!inicializado_[tamanho])
    {
        throw IndiceNaoInicializado{i};
    }
    return elementos_[tamanho];
}

Vetor::~Vetor()
{
    delete []elementos_;
}

