#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Declaração de variáveis linha e coluna
    int linhaHorizontal = 4, linhaVertical = 3;
    int colunaHorizontal = 1, colunaVertical = 6;
    int tamanho = 3;

    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Declaração da vetor e matriz 
    char cabecalho_horizontal[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int cabecalho_vertical[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tabuleiro[10][10] = {0};

    // Validações de erros
    if ((linhaHorizontal == linhaVertical) && (colunaHorizontal == colunaVertical))
    {   
        // validação de colisão
        // linhas e colunas não podem se sobrepor umas as outras
        printf("Houve uma colisão! Tente novamente.");
    } else if ((linhaHorizontal + tamanho >= 10) || (linhaVertical + tamanho >= 10) || (colunaHorizontal + tamanho >= 10) || (colunaVertical + tamanho >= 10))
    {   
        // validação de tamanho do tabuleiro
        // As variáveis linhas e colunas não podem ultrapassar 10 que é o tamanho limite do tabuleiro
        printf("O navio não cabe no tabuleiro! Tente novamente.");
    } else {
        // banner indicando a exibição das coordenadas
        printf("=====================================\n");
        printf("------------ COORDENADAS ------------\n");
        printf("=====================================\n");
        printf("\n"); // separa banner e coordenadas para melhor visualização e organização no terminal

        // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
        // Exibição das coordenadas dos navios
        // Exemplo: 3, B, 3,C 3,D
        printf("Coordenadas do navio horizontal: ");
        for (int i = 0; i < tamanho; i++)
        {
            printf("(%d, %c) ", cabecalho_vertical[linhaHorizontal], cabecalho_horizontal[colunaHorizontal + i]);
        }
        printf("\n"); // separa as coordenadas para melhor visualização e organização no terminal

        printf("Coordenadas do navio vertical: ");
        for (int i = 0; i < tamanho; i++)
        {
            printf("(%d, %c) ", cabecalho_vertical[linhaVertical + i], cabecalho_horizontal[colunaVertical]);
        }
        printf("\n"); // separa as coordenadas e banner para melhor visualização e organização no terminal
        
        // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
        // posicionamento dos navios
        for (int i = 0; i < 3; i++)
        {   
            //define a posição e armazena o número 3 para demarcar a localização dos navios
            /* Exemplo:

                Digitar:
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3; 

                É o mesmo que digitar:
                tabuleiro[1][5 + i] = 3; 
            */
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3; 
            tabuleiro[linhaVertical + i][colunaVertical] = 3; 
        }

        // banner indicando a exibição do tabuleiro
        printf("===================================\n");
        printf("------------ TABULEIRO ------------\n");
        printf("===================================\n");
        printf("\n"); // separa banner e cabeçalho para melhor visualização e organização no terminal

        // exibição do cabeçalho das colunas com caracteres na horizontal
        printf("   "); // espaçamento para organizar a exibição do cabeçalho no terminal
        for (int x = 0; x < 10; x++)
        {
            // imprime o cabeçalho horizontal da seguinte maneira = |A| |B| |C|...
            printf("|%c|", cabecalho_horizontal[x]); 
        }
        printf("\n"); // evita que o cabeçalho e a primeira linha fiquem no mesmo espaço 

        // exibição do tabuleiro com a posição dos navios
        for (int i = 0; i < 10; i++)
        {
            // exibição do cabeçalho das linhas com números na vertical
            printf("|%d| ", cabecalho_vertical[i]); 
            /* imprime o cabeçalho vertical da seguinte maneira: 
                |0| 
                |1| 
                |2|
                ...
            */
            for (int j = 0; j < 10; j++)
            {
                printf("%d  ", tabuleiro[i][j]); // imprime o número 0 que representa a água
            }
            printf("\n"); // separa as linhas para melhor visualização e organização do tabuleiro
        }
    }
    printf("\n");
    
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
