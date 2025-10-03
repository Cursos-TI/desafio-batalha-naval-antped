#include <stdio.h>

#define TAB_SIZE 10
#define SHIP_SIZE 3
#define NAVIO 3
#define AGUA 0

// Função para verificar se uma posição está livre no tabuleiro
int posicaoLivre(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna) {
    return (linha >= 0 && linha < TAB_SIZE && coluna >= 0 && coluna < TAB_SIZE && tabuleiro[linha][coluna] == AGUA);
}

// Função para posicionar navio horizontal
int posicionarHorizontal(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna) {
    int i;
    for(i = 0; i < SHIP_SIZE; i++) {
        if(!posicaoLivre(tabuleiro, linha, coluna + i)) return 0; // Não cabe ou sobreposição
    }
    for(i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarVertical(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna) {
    int i;
    for(i = 0; i < SHIP_SIZE; i++) {
        if(!posicaoLivre(tabuleiro, linha + i, coluna)) return 0; // Não cabe ou sobreposição
    }
    for(i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio diagonal (para baixo e à direita)
int posicionarDiagonalDesc(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna) {
    int i;
    for(i = 0; i < SHIP_SIZE; i++) {
        if(!posicaoLivre(tabuleiro, linha + i, coluna + i)) return 0; // Não cabe ou sobreposição
    }
    for(i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio diagonal (para baixo e à esquerda)
int posicionarDiagonalAsc(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna) {
    int i;
    for(i = 0; i < SHIP_SIZE; i++) {
        if(!posicaoLivre(tabuleiro, linha + i, coluna - i)) return 0; // Não cabe ou sobreposição
    }
    for(i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE];
    int i, j;

    // Inicializar tabuleiro com água
    for(i = 0; i < TAB_SIZE; i++) {
        for(j = 0; j < TAB_SIZE; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionar navios horizontal e vertical
    posicionarHorizontal(tabuleiro, 1, 1); // Horizontal na linha 2, coluna B
    posicionarVertical(tabuleiro, 4, 5);   // Vertical na linha 5, coluna F

    // Posicionar navios diagonais
    posicionarDiagonalDesc(tabuleiro, 0, 6); // Diagonal descendo para baixo/direita
    posicionarDiagonalAsc(tabuleiro, 3, 9);  // Diagonal descendo para baixo/esquerda

    // Exibir tabuleiro com cabeçalhos
    printf("   ");
    for(j = 0; j < TAB_SIZE; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for(i = 0; i < TAB_SIZE; i++) {
        printf("%2d ", i + 1);
        for(j = 0; j < TAB_SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
