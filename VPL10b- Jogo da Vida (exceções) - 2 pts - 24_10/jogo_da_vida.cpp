#include "jogo_da_vida.h"
#include "jogo_da_vida.h"
using namespace std;
JogoDaVida::JogoDaVida(int l, int c)
{
    vivas_.resize(l);
    for (int i = 0; i < l; i++)
    {
        vivas_[i].resize(c);
    }
}

bool JogoDaVida::viva(int i, int j)
{
    if (i < 0 || i >= linhas() || j < 0 || j >= colunas())
    {
        throw ExcecaoCelulaInvalida{i,j};
    }
    return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j)
{
    if (i < 0 || i >= linhas() || j < 0 || j >= colunas())
    {
        throw ExcecaoCelulaInvalida{i,j};
    }
    vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j)
{
    if (i < 0 || i >= linhas() || j < 0 || j >= colunas())
    {
        throw ExcecaoCelulaInvalida{i,j};
    }
    vivas_[i][j] = true;
}

void JogoDaVida::ExecutarProximaIteracao()
{
    vector<vector<bool>> novo_tabuleiro = vivas_;

    for (int i = 0; i < vivas_.size(); i++)
    {
        for (int j = 0; j < vivas_[0].size(); j++)
        {
            int num = NumeroDeVizinhasVivas(i, j);

            if (vivas_[i][j] && NumeroDeVizinhasVivas(i, j) != 2 && NumeroDeVizinhasVivas(i, j) != 3)
            {
                novo_tabuleiro[i][j] = false;
            }
            else if (!vivas_[i][j] && NumeroDeVizinhasVivas(i, j) == 3)
            {
                novo_tabuleiro[i][j] = true;
            }
        }
    }
    vivas_ = novo_tabuleiro;
}
int JogoDaVida::NumeroDeVizinhasVivas(int x, int y)
{
    if (x >= vivas_.size() || y >= vivas_[0].size())
    {
        throw("células invalidas");
    }
    int vizinhas = 0;
    int colunas_menos = y - 1;
    int colunas = y;
    int colunas_mais = y + 1;
    int linhas_menos = x - 1;
    int linhas = x;
    int linhas_mais = x + 1;
    if (x - 1 < 0)
    {
        linhas_menos = vivas_.size() - 1;
    }
    if (x + 1 == vivas_.size())
    {
        linhas_mais = 0;
    }
    if (y - 1 < 0)
    {
        colunas_menos = vivas_[0].size() - 1;
    }
    if (y + 1 == vivas_[0].size())
    {
        colunas_mais = 0;
    }

    if (vivas_[linhas_menos][colunas_menos]) // diagonal superior esquerda
    {
        vizinhas++;
    }
    if (vivas_[linhas][colunas_menos]) // esquerda
    {
        vizinhas++;
    }
    if (vivas_[linhas_mais][colunas_menos]) // diagonal inferior esquerda
    {
        vizinhas++;
    }
    if (vivas_[linhas_menos][colunas]) // superior
    {
        vizinhas++;
    }
    if (vivas_[linhas_mais][colunas]) // inferior
    {
        vizinhas++;
    }
    if (vivas_[linhas_menos][colunas_mais]) // diagonal superior direita
    {
        vizinhas++;
    }
    if (vivas_[linhas][colunas_mais]) // direita
    {
        vizinhas++;
    }
    if (vivas_[linhas_mais][colunas_mais])
    {
        vizinhas++;
    }
    return vizinhas;
}
