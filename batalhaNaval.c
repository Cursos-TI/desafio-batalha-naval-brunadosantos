#include <stdio.h>
#include <stdlib.h>

// declaração de constantes
#define tamanho_tabuleiro 10
#define tamanho_cone 5
#define tamanho_cruz 5
#define tamanho_octaedro 5
#define tamanho_navio 3

// declaração de matriz
int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro] = {0}; // define o tamanho da matriz em 10x10 e todos os indices recebem o valor 0.
int tabuleiro_cone[tamanho_cone][tamanho_cone] = {0}; // define o tamanho da matriz em 5x5 e todos os indices recebem o valor 0.
int tabuleiro_cruz[tamanho_cruz][tamanho_cruz] = {0}; // define o tamanho da matriz em 5x5 e todos os indices recebem o valor 0.
char tabuleiro_octaedro[tamanho_octaedro][tamanho_octaedro] = {0}; // define o tamanho da matriz em 5x5 e todos os indices recebem o valor 0.

// definição de funções
void matrizCone(){
    
    // definição do cone
    for (int i = 0; i < 3; i++)
    {
        for (int j = tamanho_cone / 2 - i; j <= tamanho_cone / 2 + i; j++)
        {
            if (j >= 0 && j < tamanho_cone)
            {
                tabuleiro_cone[i][j] = 5; // armazena os valores do cone
            }
        }
    }
}

void matrizCruz(){

    // declaração de variável para encontrar o meio do tabuleiro
    int meio = tamanho_cruz / 2;

    // definição da cruz
    for (int i = 0; i < tamanho_cruz; i++)
    {
        tabuleiro_cruz[i][meio] = 7; // linha vertical    
        tabuleiro_cruz[meio][i] = 7; // linha horizontal
    }
}

void matrizOctaedro() {

    // declaração de variável para encontrar o meio do tabuleiro
    int centro = tamanho_octaedro / 2;
    // definição do octaedro
    for (int i = 0; i <= centro; i++)
    {
        for (int j = centro - i; j <= centro + i; j++)
        {
            tabuleiro_octaedro[i][j] = 9; // parte superior
            tabuleiro_octaedro[tamanho_octaedro - i - 1][j] = 9; // parte inferior
        }
    }
}

void mesclarTabuleiro() {
    // declaração de variáveis
    int linha_cone = 0, coluna_cone = 0;
    int linha_cruz = 4, coluna_cruz = 0;
    int linha_octaedro = 0, coluna_octaedro = 5;
    int valores;

    // definição do cone
    for (int i = 0; i < 3; i++) {
        for (int j = tamanho_cone / 2 - i; j <= tamanho_cone / 2 + i; j++) {
            if (tabuleiro_cone[i][j] != 0) {
                tabuleiro[linha_cone + i][coluna_cone + j] = tabuleiro_cone[i][j];
            }
        }
    }

    // definição da cruz
    for (int i = 0; i < tamanho_cruz; i++) {
        for (int j = 0; j < tamanho_cruz; j++) {
            if (tabuleiro_cruz[i][j] != 0) {
                tabuleiro[linha_cruz + i][coluna_cruz + j] = tabuleiro_cruz[i][j];
            }
        }        
    }

    // definição do octaedro
    for (int i = 0; i < tamanho_octaedro; i++) {
        for (int j = 0; j < tamanho_octaedro; j++) {
            tabuleiro[linha_octaedro + i][coluna_octaedro + j] = tabuleiro_octaedro[i][j];
        }
    }

}

void exibirTabuleiro(){
    // declaração de vetor
    char cabecalho_horizontal[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int cabecalho_vertical[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Declaração de variáveis
    int linhaHorizontal = 8, linhaVertical = 4;
    int colunaHorizontal = 0, colunaVertical = 9;
    int linhaPrincipal = 7, linhaSecundaria = 3;
    int colunaPrincipal = 7, colunaSecundaria = 6;
    int soma;

    // Validação de erros
    if ((linhaHorizontal == colunaPrincipal) || (linhaVertical == colunaSecundaria) || (linhaHorizontal == linhaVertical))
    {  
        // Validação de colisão
        // linhas e colunas não podem se sobrepor umas as outras
        printf("Houve uma colisão! Tente novamente.");
    } else if ((linhaVertical + tamanho_navio > 10) || (linhaHorizontal > 10) || (colunaVertical > 10) || (colunaHorizontal + tamanho_navio > 10))
    { 
        // Validação de limite do tabuleiro horizontal e vertical
        // As variáveis linhas e colunas não podem ultrapassar 10 que é o tamanho limite do tabuleiro
        printf("O navio não cabe no tabuleiro! Tente novamente.");
    } else if((linhaPrincipal + tamanho_navio > 10) || (linhaSecundaria + tamanho_navio > 10) || (colunaPrincipal + tamanho_navio > 10) || (colunaSecundaria < 2))
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
        for (int i = 0; i < tamanho_navio; i++)
        {   
            // exibe a coordenada do navio e adiciona 1 ao valor da coluna
            printf("(%d, %c) ", cabecalho_vertical[linhaHorizontal], cabecalho_horizontal[colunaHorizontal + i]);
        }
        printf("\n"); // separa as coordenadas para melhor visualização e organização no terminal

        // exibição das coordenadas vertical 
        printf("Coordenada vertical: ");
        for (int i = 0; i < tamanho_navio; i++)
        {   
            // exibe a coordenada do navio e adiciona 1 ao valor da linha
            printf("(%d, %c) ", cabecalho_vertical[linhaVertical + i], cabecalho_horizontal[colunaVertical]);
        }
        printf("\n"); // separa as coordenadas e banner para melhor visualização e organização no terminal

        // exibição das coordenadas diagonal superios  
        printf("Coordenada diagonal superior: ");
        for (int i = 0; i < tamanho_navio; i++)
        {   
            // exibe a coordenada do navio na diagonal e adiciona 1 ao valor da linha e coluna
            printf("(%d, %c) ", cabecalho_vertical[linhaPrincipal + i], cabecalho_horizontal[colunaPrincipal + i]);
        }
        printf("\n"); // separa as coordenadas para melhor visualização e organização no terminal

        // exibição das coordenadas diagonal sevundária
        printf("Coordenada diagonal secundária: ");
        soma = linhaSecundaria + colunaSecundaria; // calcula os valores de linha e coluna para verificar o se resultado é igual a 9  
        if (soma == 9) // se resultado igual a nove executa o código, se não retorna erro.
        {
            for (int i = 0; i < tamanho_navio; i++)
            {

                // define o posicionamento do navio na diagonal no tabuleiro
                tabuleiro[linhaSecundaria + i][colunaSecundaria - i] = tamanho_navio;
                // exibe a coordenada do navio na diagonal e adiciona 1 ao valor da linha e tira 1 da coluna
                printf("(%d, %c) ", cabecalho_vertical[linhaSecundaria + i], cabecalho_horizontal[colunaSecundaria - i]);
            }
        } else {
            printf("Houve um erro! Tente novamente."); // se a condição for falsa retorna esse erro.
        }
        printf("\n"); // separa as coordenadas e banner para melhor visualização e organização no terminal

        // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
        // posicionamento dos navios
        for (int i = 0; i < tamanho_navio; i++)
        {   
            //define a posição e armazena o número 3 para demarcar a localização dos navios
            /* Exemplo:

                Digitar:
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3; 

                É o mesmo que digitar:
                tabuleiro[1][5 + i] = 3; 
            */
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = tamanho_navio; // define o posicionamento do navio na horizontal e adiciona 1 na coluna
            tabuleiro[linhaVertical + i][colunaVertical] = tamanho_navio; // define o posicionamento do navio na vertical e adiciona 1 na linha
            tabuleiro[linhaPrincipal + i][colunaPrincipal + i] = tamanho_navio; // define o posicionamento do navio na diagonal no tabuleiro e adiciona 1 na linha e coluna
        }

        // banner de exibição do tabuleiro
        printf("===================================\n");
        printf("------------ TABULEIRO ------------\n");
        printf("===================================\n");
        printf("\n"); // separa banner e cabeçalho para melhor visualização e organização no terminal
    
        // adiciona o cabeçalho horizontal
        printf("   "); // cria um espaçamento para alinhar o cabeçalho a matriz
        for (int x = 0; x < tamanho_tabuleiro; x++)
        {
            printf("|%c|", cabecalho_horizontal[x]); // exibe o cabeçalho horizontal com caracteres |A|, |B|, |C|...
        }
        printf("\n");

        // exibição da matriz principal
        for (int i = 0; i < tamanho_tabuleiro; i++)
        {   
            printf("|%d| ", cabecalho_vertical[i]); // exibe o cabeçalho vertical com números |1|, |2|, |3|...
            for (int j = 0; j < tamanho_tabuleiro; j++)
            {   
                printf("%d  ", tabuleiro[i][j]); // imprime os valores da linha e coluna da matriz tabuleiro
            }
            printf("\n");
        }
    }
    printf("\n"); // separa as linhas para melhor visualização e organização do tabuleiro
}

int main() {
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // chamada de função
    matrizCone();
    matrizCruz();
    matrizOctaedro();
    mesclarTabuleiro();
    exibirTabuleiro();

    return 0;
}

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