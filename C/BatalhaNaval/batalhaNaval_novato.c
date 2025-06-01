#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa toda a matriz com 0 (água)

    // Posições iniciais dos navios (definidas diretamente no código)
    int linhaNavioH = 2; // Linha do navio horizontal
    int colNavioH = 4;   // Coluna inicial do navio horizontal

    int linhaNavioV = 5; // Linha inicial do navio vertical
    int colNavioV = 7;   // Coluna do navio vertical

    // Validação: garantir que o navio horizontal esteja dentro dos limites
    if (colNavioH + TAMANHO_NAVIO <= TAMANHO) {
        // Posiciona o navio horizontalmente
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioH][colNavioH + i] = 3;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação: garantir que o navio vertical esteja dentro dos limites
    if (linhaNavioV + TAMANHO_NAVIO <= TAMANHO) {
        // Verifica se as posições já estão ocupadas pelo navio horizontal
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioV + i][colNavioV] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio verticalmente
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioV + i][colNavioV] = 3;
            }
        } else {
            printf("Erro: Os navios se sobrepõem.\n");
            return 1;
        }

    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada posição com espaço
        }
        printf("\n"); // Quebra de linha por linha
    }

    return 0;
}
