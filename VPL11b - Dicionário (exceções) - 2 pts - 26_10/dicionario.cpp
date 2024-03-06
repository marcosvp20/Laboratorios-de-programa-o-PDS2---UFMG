#include "dicionario.h"
#include "dicionario.h"
using namespace std;

Dicionario::Dicionario()
{
}

int Dicionario::tamanho()
{
    return elementos_.size();
}

bool Dicionario::pertence(string chave)
{

    for (auto it = elementos_.begin(); it != elementos_.end(); it++)
    {
        if (chave == (*it).chave)
        {
            return true;
        }
    }
    return false;
}

string Dicionario::menor()
{
    if(tamanho() == 0)
    {
        throw DicionarioVazio();
    }
        auto it = elementos_.begin();
        string menor = (*it).chave;
        for (it; it != elementos_.end(); it++)
        {
            if ((*it).chave < menor)
            {
                menor = (*it).chave;
            }
        }
        return menor;
    
}

string Dicionario::valor(string chave)
{
        if(!pertence(chave))
        {
            throw ChaveInexistente{chave};
        }
        string aux;
        for (auto it = elementos_.begin(); it != elementos_.end(); it++)
        {
            if (chave == (*it).chave)
            {
                aux = (*it).valor;
            }
        }
        return aux;
    
}

void Dicionario::Inserir(string chave, string valor)
{
    if (pertence(chave))
    {
        throw ChaveRepetida{chave};
    }
        Elemento elemento;
        elemento.chave = chave;
        elemento.valor = valor;

        elementos_.push_back(elemento);
}

void Dicionario::Remover(string chave)
{
    if(!pertence(chave))
    {
        throw ChaveInexistente{chave};
    }
        for (auto it = elementos_.begin(); it != elementos_.end(); it++)
        {
            if (chave == (*it).chave)
            {
                elementos_.erase(it);
                return;
            }
        }
    
}

void Dicionario::Alterar(string chave, string valor)
{
    if(!pertence(chave))
    {
        throw ChaveInexistente{chave};
    }
        for (auto it = elementos_.begin(); it != elementos_.end(); it++)
        {
            if (chave == (*it).chave)
            {
                (*it).valor = valor;
                return;
            }
        }
        
    
}
Dicionario::~Dicionario() {}
