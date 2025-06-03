#include "bits/stdc++.h"
using namespace std;

//Uso de programação dinamica

int main()
{
    int L, C, M, N;
    cin >> L >> C >> M >> N; // Entrada do tamanho da matriz original (L x C) e da submatriz desejada (M x N)

    // Verifica se os valores de entrada estão dentro dos limites válidos
    if (L >= 1 && L <= 1000 && C >= 1 && C <= 1000 && M >= 1 && M <= L && N >= 1 && N <= C)
    {
        int todosCajus[L][C]; // Matriz original contendo o número de cajus por árvore
        int todosCajusSoma[L + 1][C + 1]; // Não entendi como funciona, só entendi que vai fazer o a busca da melhor area de colheira mais rapido, caso tenha muitos dados

        // Inicializa a matriz de soma acumulada com zeros para evitar lixo de memória
        for (int i = 0; i <= L; i++)
        {
            for (int j = 0; j <= C; j++)
            {
                todosCajusSoma[i][j] = 0;
            }
        }

        // Leitura dos valores da matriz original e construção da matriz de soma acumulada
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> todosCajus[i][j];

                // Construindo a soma acumulada diretamente
                // Fórmula:
                // soma(i+1,j+1) = valor atual +
                // soma acima (linha anterior) +
                // soma à esquerda (coluna anterior) -
                // interseção (diagonal superior esquerda) para evitar contagem duplicada
                todosCajusSoma[i + 1][j + 1] = todosCajus[i][j] 
                                            + todosCajusSoma[i][j + 1] 
                                            + todosCajusSoma[i + 1][j] 
                                            - todosCajusSoma[i][j];
            }
        }

        int maxSoma = 0;

        // Varre todas as posições possíveis da submatriz MxN
        // Começa em (M, N) porque precisamos garantir que o retângulo de tamanho MxN "caiba" dentro da matriz acumulada
        for (int i = M; i <= L; i++)
        {
            for (int j = N; j <= C; j++)
            {
                // Calcula a soma da submatriz que termina em (i-1, j-1)
                // Usamos a matriz de soma acumulada para obter o valor da submatriz MxN em O(1)
                // Fórmula da soma de submatriz usando matriz acumulada:
                // total = todosCajusSoma[i][j]
                //       - todosCajusSoma[i - M][j]         (remove a parte de cima)
                //       - todosCajusSoma[i][j - N]         (remove a parte da esquerda)
                //       + todosCajusSoma[i - M][j - N];    (adiciona a interseção removida duas vezes)
                int somaAtual = todosCajusSoma[i][j] 
                              - todosCajusSoma[i - M][j] 
                              - todosCajusSoma[i][j - N] 
                              + todosCajusSoma[i - M][j - N];

                // Atualiza a maior soma encontrada até o momento
                maxSoma = max(maxSoma, somaAtual);
            }
        }

        // Exibe a maior soma encontrada, ou seja, a melhor área de colheita de MxN cajueiros
        cout << maxSoma << endl;
    }
}
