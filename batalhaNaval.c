#include <stdio.h>

#define TAB_SIZE 10
#define SHIP_SIZE 3

#define HABILIDADE 5  // Valor para marcar área de efeito das habilidades
#define NAVIO 3       // Valor para navio
#define AGUA 0        // Valor para água

// Função para sobrepor matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAB_SIZE][TAB_SIZE], int habilidade[5][5], int origemLinha, int origemColuna) {
    int tamanho = 5; // tamanho da matriz de habilidade
    int i, j;

    for(i = 0; i < tamanho; i++) {
        for(j = 0; j < tamanho; j++) {
            if(habilidade[i][j] == 1) {
                int linhaTab = origemLinha - tamanho/2 + i;
                int colTab = origemColuna - tamanho/2 + j;

                // Verificar se está dentro dos limites do tabuleiro
                if(linhaTab >= 0 && linhaTab < TAB_SIZE && colTab >= 0 && colTab < TAB_SIZE) {
                    // Não sobrescreve navios
                    if(tabuleiro[linhaTab][colTab] == AGUA) {
                        tabuleiro[linhaTab][colTab] = HABILIDADE;
                    }
                }
            }
        }
    }
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

    // Definir navios
    int navioH_row = 1, navioH_col = 2; // Horizontal
    int navioV_row = 4, navioV_col = 6; // Vertical

    for(i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioH_row][navioH_col + i] = NAVIO;
        tabuleiro[navioV_row + i][navioV_col] = NAVIO;
    }

    // Criar matrizes de habilidade (5x5)
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Construção dinâmica do cone
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Construção dinâmica da cruz
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Construção dinâmica do octaedro (losango)
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(j >= 2 - abs(2 - i) && j <= 2 + abs(2 - i)) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // Cone no topo esquerdo
    aplicarHabilidade(tabuleiro, cruz, 6, 3);      // Cruz no meio
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro canto inferior direito

    // Exibir tabuleiro com cabeçalhos
    printf("   ");
    for(j = 0; j < TAB_SIZE; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for(i = 0; i < TAB_SIZE; i++) {
        printf("%2d ", i + 1);
        for(j = 0; j < TAB_SIZE; j++) {
            if(tabuleiro[i][j] == AGUA) printf("A ");       // Água
            else if(tabuleiro[i][j] == NAVIO) printf("N "); // Navio
            else if(tabuleiro[i][j] == HABILIDADE) printf("H "); // Área de habilidade
        }
        printf("\n");
    }

    return 0;
}
