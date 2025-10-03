#include <stdio.h>

#define TAB_SIZE 10    // Tamanho do tabuleiro
#define SHIP_SIZE 3    // Tamanho dos navios

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE]; // Matriz do tabuleiro
    int i, j;

    // 1. Inicializar o tabuleiro com 0 (água)
    for(i = 0; i < TAB_SIZE; i++) {
        for(j = 0; j < TAB_SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definir coordenadas iniciais dos navios
    int navioH_row = 1;  // Linha inicial do navio horizontal
    int navioH_col = 2;  // Coluna inicial do navio horizontal

    int navioV_row = 4;  // Linha inicial do navio vertical
    int navioV_col = 6;  // Coluna inicial do navio vertical

    // 3. Posicionar navio horizontal e exibir coordenadas
    printf("Navio Horizontal (tamanho %d):\n", SHIP_SIZE);
    for(i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioH_row][navioH_col + i] = 3;
        printf("Parte %d: Linha %d, Coluna %c\n", i + 1, navioH_row + 1, 'A' + navioH_col + i);
    }
    printf("\n");

    // 4. Posicionar navio vertical e exibir coordenadas
    printf("Navio Vertical (tamanho %d):\n", SHIP_SIZE);
    for(i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioV_row + i][navioV_col] = 3;
        printf("Parte %d: Linha %d, Coluna %c\n", i + 1, navioV_row + i + 1, 'A' + navioV_col);
    }
    printf("\n");

    // 5. Exibir o tabuleiro com cabeçalhos
    printf("Tabuleiro Batalha Naval:\n\n");

    // Cabeçalho das colunas (A, B, C, ...)
    printf("   ");
    for(j = 0; j < TAB_SIZE; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Exibir linhas com números e conteúdo do tabuleiro
    for(i = 0; i < TAB_SIZE; i++) {
        printf("%2d ", i + 1); // Número da linha
        for(j = 0; j < TAB_SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
