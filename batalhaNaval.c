#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10] = {0};

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Navio na horizontal
    int linha = 2;
    int coluna = 3;

    // Navio na vertical
    int linha2 = 5;
    int coluna2 = 7;

    int tamanho = 3;
    
    // validação de colisão dos navios
    if (linha == linha2 && coluna == coluna2)
    {
        printf("Erro! Houve uma colisão");
    } else {
        
        // validação de posição no tabuleiro do navio horizontal
        if (coluna + tamanho <= 10)
        {   
            // Mostra a coordenada do navio na horizontal
            printf("Cordenada navio na horizontal: %d, %d\n", linha, coluna);
            // definição da posição do navio horizontal
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha][coluna + i] = 1;
            }
        } else { 
            printf("O navio não cabe no tabuleiro! Tente novamente.\n");
            exit(0);
        } 

        // validação de posição no tabuleiro do navio vertical
        if (linha2 + tamanho <= 10)
        {
            // Mostra a coordenada do navio na vertical
            printf("Cordenada navio na vertical: %d, %d\n", linha2, coluna2);
            // definição da posição do navio na vertical
            for (int j = 0; j < 3; j++) 
            {
                tabuleiro[linha2 + j][coluna2] = 1;
            }
        } else { 
            printf("O navio não cabe no tabuleiro! Tente novamente.\n");
            exit(0);
        }
        
        // Exibição do tabuleiro
        for (int i = 0; i < 10; i++) 
        {
            for (int j = 0; j < 10; j++)
            {
                printf("[%d]", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
