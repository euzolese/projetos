#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

// Função para verificar se uma posição do tabuleiro está ocupada
int esta_ocupado(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return tabuleiro[linha][coluna] != 0;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa com água (0)

    // ------------------------------
    // POSICIONAMENTO DOS NAVIOS
    // ------------------------------

    // 1. Navio Horizontal (linha 1, coluna 2 até 4)
    int linhaH = 1, colH = 2;
    if (colH + TAMANHO_NAVIO <= TAMANHO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (esta_ocupado(tabuleiro, linhaH, colH + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colH + i] = 3;
            }
        }
    }

    // 2. Navio Vertical (linha 5 a 7, coluna 6)
    int linhaV = 5, colV = 6;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (esta_ocupado(tabuleiro, linhaV + i, colV)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colV] = 3;
            }
        }
    }

    // 3. Navio Diagonal Principal ↘ (ex: [0][0], [1][1], [2][2])
    int linhaD1 = 0, colD1 = 0;
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO && colD1 + TAMANHO_NAVIO <= TAMANHO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (esta_ocupado(tabuleiro, linhaD1 + i, colD1 + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colD1 + i] = 3;
            }
        }
    }

    // 4. Navio Diagonal Secundária ↙ (ex: [0][9], [1][8], [2][7])
    int linhaD2 = 0, colD2 = 9;
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO && colD2 - TAMANHO_NAVIO + 1 >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (esta_ocupado(tabuleiro, linhaD2 + i, colD2 - i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colD2 - i] = 3;
            }
        }
    }

    // ------------------------------
    // EXIBIÇÃO DO TABULEIRO
    // ------------------------------
    printf("\n=== Tabuleiro Batalha Naval ===\n\n   ");
    for (int col = 0; col < TAMANHO; col++) {
        printf("%2d ", col); // Cabeçalho de colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i); // Cabeçalho de linhas
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
