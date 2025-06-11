// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>
#include <stdlib.h>

#define linha 10
#define coluna 10
#define tamanho 3

int main() {
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    // Declaração de variáveis
    int linhaHorizontal = 8, linhaVertical = 1;
    int colunaHorizontal = 0, colunaVertical = 9;
    int linhaPrincipal = 2, linhaSecundaria = 2;
    int colunaPrincipal = 2, colunaSecundaria = 7;
    int soma;

    // Declaração da matriz
    int tabuleiro[linha][coluna] = {0};

    // Declaração do vetor
    char cabecalhoHorizontal[coluna] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int cabecalhoVertical[linha] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Validação de erros
    if ((linhaHorizontal == colunaPrincipal) || (linhaVertical == colunaSecundaria) || (linhaHorizontal == linhaVertical))
    {  
        // Validação de colisão
        // linhas e colunas não podem se sobrepor umas as outras
        printf("Houve uma colisão! Tente novamente.");
    } else if ((linhaVertical + tamanho > 10) || (linhaHorizontal > 10) || (colunaVertical > 10) || (colunaHorizontal + tamanho > 10))
    { 
        // Validação de limite do tabuleiro horizontal e vertical
        // As variáveis linhas e colunas não podem ultrapassar 10 que é o tamanho limite do tabuleiro
        printf("O navio não cabe no tabuleiro! Tente novamente.");
    } else if((linhaPrincipal + tamanho > 10) || (linhaSecundaria + tamanho > 10) || (colunaPrincipal + tamanho > 10) || (colunaSecundaria < 2))
    { 
        // Validação de limite do tabuleiro diagonal principal e secundária
        // As variáveis linhas e colunas não podem ultrapassar 10 que é o tamanho limite do tabuleiro
        printf("O navio não cabe no tabuleiro! Tente novamente.");
    } else {
        // banner de exibição das coordenadas
        printf("=====================================\n");
        printf("------------ COORDENADAS ------------\n");
        printf("=====================================\n");
        printf("\n"); // separa banner e coordenadas para melhor visualização e organização no terminal

        // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
        // Exibição das coordenadas dos navios
        // Exemplo: (3, B), (3, C) (3, D).

        // exibição das coordenadas horizontal
        printf("Coordenada horizontal: ");
        for (int i = 0; i < tamanho; i++)
        {   
            // exibe a coordenada do navio e adiciona 1 ao valor da coluna
            printf("(%d, %c) ", cabecalhoVertical[linhaHorizontal], cabecalhoHorizontal[colunaHorizontal + i]);
        }
        printf("\n"); // separa as coordenadas para melhor visualização e organização no terminal

        // exibição das coordenadas vertical 
        printf("Coordenada vertical: ");
        for (int i = 0; i < tamanho; i++)
        {   
            // exibe a coordenada do navio e adiciona 1 ao valor da linha
            printf("(%d, %c) ", cabecalhoVertical[linhaVertical + i], cabecalhoHorizontal[colunaVertical]);
        }
        printf("\n"); // separa as coordenadas e banner para melhor visualização e organização no terminal

        // exibição das coordenadas diagonal superios  
        printf("Coordenada diagonal superior: ");
        for (int i = 0; i < tamanho; i++)
        {   
            // exibe a coordenada do navio na diagonal e adiciona 1 ao valor da linha e coluna
            printf("(%d, %c) ", cabecalhoVertical[linhaPrincipal + i], cabecalhoHorizontal[colunaPrincipal + i]);
        }
        printf("\n"); // separa as coordenadas para melhor visualização e organização no terminal

        // exibição das coordenadas diagonal sevundária
        printf("Coordenada diagonal secundária: ");
        soma = linhaSecundaria + colunaSecundaria; // calcula os valores de linha e coluna para verificar o se resultado é igual a 9  
        if (soma == 9) // se resultado igual a nove executa o código, se não retorna erro.
        {
            for (int i = 0; i < tamanho; i++)
            {

                // define o posicionamento do navio na diagonal no tabuleiro
                tabuleiro[linhaSecundaria + i][colunaSecundaria - i] = tamanho;
                // exibe a coordenada do navio na diagonal e adiciona 1 ao valor da linha e tira 1 da coluna
                printf("(%d, %c) ", cabecalhoVertical[linhaSecundaria + i], cabecalhoHorizontal[colunaSecundaria - i]);
            }
        } else {
            printf("Houve um erro! Tente novamente."); // se a condição for falsa retorna esse erro.
        }
        printf("\n"); // separa as coordenadas e banner para melhor visualização e organização no terminal

        // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
        // posicionamento dos navios
        for (int i = 0; i < tamanho; i++)
        {   
            //define a posição e armazena o número 3 para demarcar a localização dos navios
            /* Exemplo:

                Digitar:
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3; 

                É o mesmo que digitar:
                tabuleiro[1][5 + i] = 3; 
            */
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = tamanho; // define o posicionamento do navio na horizontal e adiciona 1 na coluna
            tabuleiro[linhaVertical + i][colunaVertical] = tamanho; // define o posicionamento do navio na vertical e adiciona 1 na linha
            tabuleiro[linhaPrincipal + i][colunaPrincipal + i] = tamanho; // define o posicionamento do navio na diagonal no tabuleiro e adiciona 1 na linha e coluna
        }

        // banner de exibição do tabuleiro
        printf("===================================\n");
        printf("------------ TABULEIRO ------------\n");
        printf("===================================\n");
        printf("\n"); // separa banner e cabeçalho para melhor visualização e organização no terminal

        /* imprime o cabeçalho seguinte maneira:

                |A| |B| |C| => horizontal
            |0|  0   0   0
            |1|  0   0   0
            |2|  0   0   0
             ^
            Vertical
        */

        // exibição do cabeçalho horizontal 
        printf("   "); // espaçamento para organizar a exibição do cabeçalho no terminal
        // executa a repetição até que x se torne maior que 10 
        for (int x = 0; x < 10; x++)
        {   
            // armazena o valor atual de x e exibe as letras correspondentes a posição no vetor
            printf("|%c|", cabecalhoHorizontal[x]); 
        }
        printf("\n"); // evita que o cabeçalho e a primeira linha fiquem no mesmo espaço

        // exibição do tabuleiro com a posição dos navios
        for (int i = 0; i < linha; i++)
        {
            // exibição do cabeçalho vertical
            // armazena o valor atual de i e exibe os números correspondentes a posição no vetor
            printf("|%d| ", cabecalhoVertical[i]); 
            for (int j = 0; j < coluna; j++)
            {
                // imprime 0 até que i seja maior que 10 e j seja maior que 10 formando o tabuleiro
                printf("%d  ", tabuleiro[i][j]);  
            }
            printf("\n"); // separa as linhas para melhor visualização e organização do tabuleiro
        }
    }
    printf("\n"); // separa as linhas para melhor visualização e organização do tabuleiro
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
